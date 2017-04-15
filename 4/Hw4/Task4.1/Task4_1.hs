quantityOfEvenNumbers :: [Int] -> Int
quantityOfEvenNumbers = length . filter (\x -> x `mod` 2 == 0)

quantityOfEvenNumbers' :: [Int] -> Int
quantityOfEvenNumbers' = sum . map (\x -> if x `mod` 2 == 0 then 1 else 0)

quantityOfEvenNumbers'' :: [Int] -> Int
quantityOfEvenNumbers'' = foldr (\x summ -> if x `mod` 2 == 0 then (summ + 1) else summ) 0
