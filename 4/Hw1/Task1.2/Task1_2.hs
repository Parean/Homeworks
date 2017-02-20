fibonacci :: Int -> Int
fibonacci n
  | n == 0 = 0
  | n == 1 = 1
  | otherwise = fibonacci' 0 1 n

fibonacci' :: Int -> Int -> Int -> Int
fibonacci' currentFibonacci nextFibonacci n
  | n == 0 = currentFibonacci
  | otherwise = fibonacci' nextFibonacci (nextFibonacci + currentFibonacci) (n - 1)
