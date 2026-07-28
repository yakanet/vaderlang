#!/usr/bin/env bash
# Push, reseeding first if the committed C seed is stale.
#
# This is the one-command happy path for the "one reseed per push" cadence
# (docs/BOOTSTRAP.md § "Who bumps"). .githooks/pre-push is the safety net for a
# plain `git push` ; this script is what keeps that net from ever firing.
#
# Every argument is forwarded to `git push`, so `bootstrap/push.sh -u origin main`
# works as expected.
set -euo pipefail
cd "$(dirname "$0")/.."

if [ -t 1 ]; then b='\033[1m'; g='\033[1;32m'; r='\033[0m'; else b=''; g=''; r=''; fi
step() { printf '%b==>%b %s\n' "$b" "$r" "$*"; }

# Regenerating writes the committed artefact, so unlike the pre-push hook — which
# merely *checks*, and tolerates not knowing — an unusable or out-of-date
# compiler is a hard stop here. Reseeding with a stale binary bakes its old
# codegen into the seed, and the result then looks fresh to anything using that
# same binary. That is the failure mode worth refusing outright.
step "Checking whether the committed seed is fresh"
set +e
./bootstrap/check-seed.sh
verdict=$?
set -e

case "$verdict" in
  0)
    step "Seed already fresh — nothing to reseed"
    ;;
  2)
    echo "push.sh: cannot verify the seed, so refusing to regenerate one." >&2
    echo "  Reseeding with an out-of-date compiler would commit its old codegen." >&2
    echo "  Fix the cause above (usually: bun run build), then retry." >&2
    exit 1
    ;;
  *)
    # regenerate.sh requires a clean vader/ so the SHA it records is meaningful.
    # Say so here rather than letting it fail three steps in.
    if ! git diff-index --quiet HEAD -- vader/; then
      echo "push.sh: vader/ has uncommitted changes — commit them before reseeding." >&2
      exit 1
    fi

    step "Seed is stale — regenerating"
    ./bootstrap/regenerate.sh

    step "Committing the bump"
    git commit -q -m 'chore(bootstrap): bump seed' \
      bootstrap/bootstrap.c bootstrap/VERSION
    git --no-pager log --oneline -1
    ;;
esac

step "Pushing"
git push "$@"
printf '%b==> done%b\n' "$g" "$r"
