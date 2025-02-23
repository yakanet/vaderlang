import type {Position} from "../parser/types.ts";

export type Location = {
    start: Position,
    end: Position
    file: string
}

export function locationToString(location: Location) {
    return `${location.file}:${location.start.line}:${location.start.column}`
}

type CreateToken<T extends string, V = string> = {
    type: T,
    value: V,
    location: Location
}

export type Decorator = 'intrinsic' | 'file' | 'load'

export type Token =
    | CreateToken<'EOF'>
    | CreateToken<'PlusToken'>
    | CreateToken<'PlusEqualToken'>
    | CreateToken<'PlusPlusToken'>
    | CreateToken<'StarToken'>
    | CreateToken<'StarEqualToken'>
    | CreateToken<'DotToken'>
    | CreateToken<'DotDotToken'>
    | CreateToken<'DashToken'>
    | CreateToken<'BitwiseAndToken'>
    | CreateToken<'BooleanAndToken'>
    | CreateToken<'BitwiseOrToken'>
    | CreateToken<'BooleanOrToken'>
    | CreateToken<'LambdaArrowToken'>
    | CreateToken<'DashDashToken'>
    | CreateToken<'DashEqualToken'>
    | CreateToken<'SlashToken'>
    | CreateToken<'SlashEqualToken'>
    | CreateToken<'PercentToken'>
    | CreateToken<'PercentEqualToken'>
    | CreateToken<'LowerThanToken'>
    | CreateToken<'HigherThanToken'>
    | CreateToken<'LowerThanEqualToken'>
    | CreateToken<'HigherThanEqualToken'>
    | CreateToken<'EqualToken'>
    | CreateToken<'DoubleEqualToken'>
    | CreateToken<'NumberToken'>
    | CreateToken<'OpenRoundBracket'>
    | CreateToken<'CloseRoundBracket'>
    | CreateToken<'OpenCurlyBracket'>
    | CreateToken<'CloseCurlyBracket'>
    | CreateToken<'OpenSquareBracket'>
    | CreateToken<'CloseSquareBracket'>
    | CreateToken<'BangToken'>
    | CreateToken<'BangEqualToken'>
    | CreateToken<'SemicolonToken'>
    | CreateToken<'ColonToken'>
    | CreateToken<'CommaToken'>
    | CreateToken<'UnderscoreToken'>
    | CreateToken<'Identifier'>
    | CreateToken<'Keyword'>
    | CreateToken<'Decorator', Decorator>
    | CreateToken<'StringLiteral'>
