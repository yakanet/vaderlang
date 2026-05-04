// Comptime value IR. The interpreter walks the typed AST and produces values
// of these shapes; the @comptime pass writes them back as constants. We use
// JS-native objects (tagged union) — perf doesn't matter at compile time and
// debugging is easier with a plain `console.log`.

export type ComptimeValue =
  | { readonly kind: "int"; readonly value: bigint; readonly typeName: string }
  | { readonly kind: "float"; readonly value: number; readonly typeName: string }
  | { readonly kind: "bool"; readonly value: boolean }
  | { readonly kind: "char"; readonly value: number }
  | { readonly kind: "string"; readonly value: string }
  | { readonly kind: "null" }
  | { readonly kind: "void" }
  | { readonly kind: "array"; readonly elements: readonly ComptimeValue[]; readonly elementTypeName: string }
  | { readonly kind: "struct"; readonly typeName: string; readonly fields: ReadonlyMap<string, ComptimeValue> };

export const VOID: ComptimeValue = { kind: "void" };
export const NULL: ComptimeValue = { kind: "null" };
export const TRUE: ComptimeValue = { kind: "bool", value: true };
export const FALSE: ComptimeValue = { kind: "bool", value: false };

export function intVal(value: bigint, typeName: string = "i32"): ComptimeValue {
  return { kind: "int", value, typeName };
}
export function floatVal(value: number, typeName: string = "f64"): ComptimeValue {
  return { kind: "float", value, typeName };
}
export function stringVal(value: string): ComptimeValue {
  return { kind: "string", value };
}

export function displayValue(v: ComptimeValue): string {
  switch (v.kind) {
    case "int":    return `${v.value.toString()}_${v.typeName}`;
    case "float":  return `${v.value}_${v.typeName}`;
    case "bool":   return v.value ? "true" : "false";
    case "char":   return `'\\u${v.value.toString(16).padStart(4, "0")}'`;
    case "string": return JSON.stringify(v.value);
    case "null":   return "null";
    case "void":   return "void";
    case "array":  return `[${v.elements.map(displayValue).join(", ")}]`;
    case "struct": {
      const fs = [...v.fields].map(([k, val]) => `.${k} = ${displayValue(val)}`).join(", ");
      return `${v.typeName} { ${fs} }`;
    }
  }
}
