import type {Statement} from "../parser/types";
import type {Scope} from "./scope";

export type Resolved<T> = {
    [K in keyof T]: 
    T[K] extends Array<infer A extends Statement> 
    ? Array<Resolved<A>>
    : T[K] extends Statement | undefined
    ? Resolved<NonNullable<T[K]>> 
    : T[K]
} & {scope: Scope}
