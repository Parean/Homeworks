printRhombus :: Int -> IO()
printRhombus n = do
  helper (+1) 1 n

helper :: (Int->Int) -> Int -> Int -> IO()
helper op inc n
  | inc == n = do
      printSpaces inc n
      printX inc n
  | otherwise = do
      printSpaces inc n
      printX inc n
      helper op (op inc) n

printX :: Int->Int->IO()
printX inc n
  | inc == n = do
       putChar 'x'
  | otherwise = do
     putChar 'x'
     printX (inc+1) n

printSpaces :: Int->Int->IO()
printSpaces inc n  
  | inc == n = do
      putChar ' '
  |otherwise = do
      putChar ' '
      printSpaces (inc+1) n

