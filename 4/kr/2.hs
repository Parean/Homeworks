generateMatrix :: Integer -> [[Integer]]
generateMatrix n = map (\x -> generateHelper 1 x n) [1..n]

generateHelper inc currStr n 
  | inc <= currStr = currStr : generateHelper (inc+1) currStr n
  | inc == (n+1) = []
  | otherwise = inc : generateHelper (inc+1) currStr n
