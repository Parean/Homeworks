checkBracketsOrder :: String -> Bool
checkBracketsOrder string = checkBracketsOrder' string (Just [])

checkBracketsOrder' :: String -> Maybe String -> Bool
checkBracketsOrder' _ Nothing = False
checkBracketsOrder' [] (Just brackets) = null brackets
checkBracketsOrder' (symbol:string) (Just brackets)
  | isOpeningBracket symbol = checkBracketsOrder' string (Just (symbol : brackets))
  | isClosingBracket symbol = if (not $ null brackets) && (areSameBrackets (head brackets) symbol)
                              then checkBracketsOrder' string (Just(tail brackets))
                              else checkBracketsOrder' string Nothing
  | otherwise = checkBracketsOrder' string (Just brackets)

isOpeningBracket :: Char -> Bool
isOpeningBracket symbol = symbol == '[' || symbol == '{' || symbol == '('

isClosingBracket :: Char -> Bool
isClosingBracket symbol = symbol == ']' || symbol == '}' || symbol == ')'

areSameBrackets :: Char -> Char -> Bool
areSameBrackets symbol1 symbol2 = symbol1 == '[' && symbol2 == ']' ||
                                  symbol1 == '{' && symbol2 == '}' ||
                                  symbol1 == '(' && symbol2 == ')'
