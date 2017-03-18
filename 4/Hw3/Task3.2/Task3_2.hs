generateList :: [Integer]
generateList = 1 : 7 : 9 : generateList'

generateList' :: [Integer]
generateList' = concatMap (\x -> [x+1, x+7, x+9]) $ generateList''

generateList'' :: [Integer]
generateList'' = map (* 10) generateList
