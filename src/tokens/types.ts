type CreateToken<T extends string> = {
    type: T,
    value: string,
    offset: number
}

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
    | CreateToken<'OpenParenthesis'>
    | CreateToken<'CloseParenthesis'>
    | CreateToken<'OpenCurlyBracket'>
    | CreateToken<'CloseCurlyBracket'>
    | CreateToken<'OpenSquareBracket'>
    | CreateToken<'CloseSquareBracket'>
    | CreateToken<'BangToken'>
    | CreateToken<'SemicolonToken'>
    | CreateToken<'ColonToken'>
    | CreateToken<'ColonColonToken'>
    | CreateToken<'ColonEqualToken'>
    | CreateToken<'CommaToken'>
    | CreateToken<'Identifier'>
    | CreateToken<'Keyword'>
    | CreateToken<'StringLiteral'>
