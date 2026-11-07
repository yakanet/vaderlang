// TypeScript peer of bench/task_switch.vader. JavaScript has no thread to
// park: a task is a promise that starts on the next microtask, its join an
// `await`, and the channel a queue of values beside a queue of waiting
// receivers, so each wake goes through the microtask queue.

const BATCH = 1_000;
const BATCHES = 10;
const TRIPS = 300_000;

// Starts on the next microtask, as a task starts once its launcher waits.
async function task(n: number): Promise<number> {
  await null;
  return n + 1;
}

async function launchAndJoin(): Promise<number> {
  let total = 0;
  for (let b = 0; b < BATCHES; b++) {
    const tasks: Promise<number>[] = [];
    for (let i = 0; i < BATCH; i++) tasks.push(task(b * BATCH + i));
    for (const t of tasks) total += await t;
  }
  return total;
}

class Channel {
  private readonly values: number[] = [];
  private readonly receivers: ((value: number | null) => void)[] = [];
  private closed = false;

  send(value: number): void {
    const receiver = this.receivers.shift();
    if (receiver) receiver(value);
    else this.values.push(value);
  }

  receive(): Promise<number | null> {
    if (this.values.length > 0) return Promise.resolve(this.values.shift()!);
    if (this.closed) return Promise.resolve(null);
    return new Promise((resolve) => this.receivers.push(resolve));
  }

  close(): void {
    this.closed = true;
    for (const receiver of this.receivers.splice(0)) receiver(null);
  }
}

async function echo(ping: Channel, pong: Channel): Promise<number> {
  let echoed = 0;
  for (let value = await ping.receive(); value !== null; value = await ping.receive()) {
    pong.send(value + 1);
    echoed++;
  }
  return echoed;
}

async function pingPong(): Promise<string> {
  const ping = new Channel();
  const pong = new Channel();
  const echoer = echo(ping, pong);
  let total = 0;
  for (let i = 0; i < TRIPS; i++) {
    ping.send(i);
    total += (await pong.receive())!;
  }
  ping.close();
  return `traded=${total} echoed=${await echoer}`;
}

const launched = await launchAndJoin();
console.log(`task_switch launched=${launched} ${await pingPong()}`);
