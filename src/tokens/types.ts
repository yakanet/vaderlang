type CreateToken<T extends string> = {
    type: T,
    value: string,
    location: {
        start: number,
        end: number
        file: string
    }
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
    | CreateToken<'Identifier'>
    | CreateToken<'Keyword'>
    | CreateToken<'Decorator'>
    | CreateToken<'StringLiteral'>
