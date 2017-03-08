sumOfDigits :: Int -> Int
sumOfDigits number = sumOfDigits' number 0 where
  sumOfDigits' 0 result = result
  sumOfDigits' number result = sumOfDigits' (number `div` 10) (result + number `mod` 10) 
