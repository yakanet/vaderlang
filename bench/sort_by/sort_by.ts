// TypeScript peer of bench/sort_by.vader. `Array.prototype.sort` has been
// required to be stable since ES2019, which the checksum depends on — equal keys
// are common and their order is read back.

const ITEM_COUNT = 20_000;
const PASS_COUNT = 24;
const STRIDE = 1103515245;

function buildItems(): number[] {
  const out: number[] = [];
  for (let index = 0; index < ITEM_COUNT; index++) {
    out.push((index * STRIDE) % 1000003);
  }
  return out;
}

let checksum = 0;
for (let pass = 0; pass < PASS_COUNT; pass++) {
  const items = buildItems();
  items.sort((a, b) => (a % 1000) - (b % 1000));
  for (let index = 0; index < items.length; index++) {
    checksum += (index + 1) * (items[index]! % 97);
  }
}
console.log(`sort_by items=${ITEM_COUNT} passes=${PASS_COUNT} checksum=${checksum}`);
