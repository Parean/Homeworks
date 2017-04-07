printRhombus :: Int -> IO ()
printRhombus n = putStr $ unlines $ (map concat (getRow 1 (n+1))) ++ (tail $ reverse $ map concat (getRow 1 (n+1)))

getRow :: Int -> Int -> [[[Char]]]
getRow inc n
  | inc == n = []
  | otherwise = [replicate (n - inc) ' ', replicate (2 * inc - 1) 'x'] : getRow (inc+1) n

