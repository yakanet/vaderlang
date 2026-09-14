// TypeScript peer of bench/closures.vader. A closure over a `let` is the same
// captured environment, and calling through an array of them keeps the call
// site megamorphic.

const CALLS = 6_000_000;
const ADDERS = 500;

function makeAdder(n: number): (x: number) => number {
  return (x: number) => x + n;
}

let counter = 0;
const bump = () => { counter = counter + 1; };
for (let i = 0; i < CALLS; i++) {
  bump();
}

const adders: ((x: number) => number)[] = [];
for (let index = 0; index < ADDERS; index++) {
  adders.push(makeAdder(index));
}
let total = 0;
for (let pass = 0; pass < CALLS / ADDERS; pass++) {
  for (let i = 0; i < adders.length; i++) {
    total = adders[i]!(total);
  }
}
console.log(`closures counter=${counter} total=${total}`);
