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

# regenerate.sh is a no-op when the seed is already fresh, and refuses outright
# when it cannot tell — the asymmetry that matters here: unlike the pre-push hook,
# which only *checks* and tolerates not knowing, this path is about to WRITE the
# committed artefact, so an unusable compiler is a hard stop. Its own guards carry
# the messages, so there is nothing to pre-check here.
step "Reseeding if the committed seed is stale"
./bootstrap/regenerate.sh

if git diff --quiet -- bootstrap/bootstrap.c bootstrap/VERSION; then
  step "Nothing to commit"
else
  step "Committing the bump"
  git commit -q -m 'chore(bootstrap): bump seed' \
    bootstrap/bootstrap.c bootstrap/VERSION
  git --no-pager log --oneline -1
fi

step "Pushing"
git push "$@"
printf '%b==> done%b\n' "$g" "$r"
