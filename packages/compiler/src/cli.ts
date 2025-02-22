class CommandLine {
  public readonly positionalArgument: Set<string>;
  public readonly options: Map<string, string | null>;

  constructor(
    public readonly nodeRuntime: string,
    public readonly typescriptFile: string,
    options: string[]
  ) {
    this.positionalArgument = new Set();
    this.options = new Map();
    for (const o of options) {
      if (!o.startsWith("-")) {
        this.positionalArgument.add(o);
      } else {
        const [key, value] = o.split("=");
        let clean_key_index = 0;
        while (key[clean_key_index] === "-") {
          clean_key_index++;
        }
        if (!key[clean_key_index]) {
          break;
        }
        this.options.set(key.substring(clean_key_index), value ?? null);
      }
    }
  }
}

export function parseCommandLine(cmd: string[]) {
  return new CommandLine(cmd[0], cmd[1], cmd.slice(2));
}
