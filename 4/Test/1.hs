generateList :: [Integer]
generateList = 1 : (-1) : generateList

generateList' :: [Integer]
generateList' = zipWith (*) [1..] generateList
