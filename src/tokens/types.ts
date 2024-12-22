type CreateToken<T extends string> = {
    type: T,
    value: string,
    offset: number
}

export type Token =
    | CreateToken<'PlusToken'>
    | CreateToken<'StarToken'>
    | CreateToken<'MinusToken'>
    | CreateToken<'DivideToken'>
    | CreateToken<'EqualToken'>
    | CreateToken<'DoubleEqualToken'>
    | CreateToken<'NumberToken'>
    | CreateToken<'OpenParenthesis'>
    | CreateToken<'CloseParenthesis'>
    | CreateToken<'OpenCurlyBracket'>
    | CreateToken<'CloseCurlyBracket'>
    | CreateToken<'OpenSquareBracket'>
    | CreateToken<'CloseSquareBracket'>
    | CreateToken<'ColonToken'>
    | CreateToken<'CommaToken'>
    | CreateToken<'Identifier'>
    | CreateToken<'Keyword'>
    | CreateToken<'StringLiteral'>
    | CreateToken<'EOF'>
