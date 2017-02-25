main :: IO ()
main = do
  putStr $ "\n Hello!\n"
  loop []

loop :: [Int] -> IO ()
loop list = do
  putStrLn $ "\n Please enter: \n 0 to exit\n 1 to add value to sorted list\n 2 to remove value from list\n 3 to print list"
  symbol <- getLine
  case symbol of
    "0" -> putStrLn "\n Bye!"
    "1" -> changeList addValue list
    "2" -> changeList removeValue list
    "3" -> printList list
    _   -> loop list

changeList :: ([Int] -> Int -> [Int]) -> [Int] -> IO ()
changeList f list = do
  putStrLn $ "\n Please enter value"
  value <- getLine
  loop $ f list (read value :: Int)

printList :: [Int] -> IO()
printList list = do
  print list
  loop list

addValue :: [Int] -> Int -> [Int]
addValue [] value = [value]
addValue (head:tail) value
  | head < value = head : addValue tail value
  | otherwise = value : head : tail

removeValue :: [Int] -> Int -> [Int]
removeValue [] value = []
removeValue (head:tail) value
  | head == value = tail
  | otherwise = head : removeValue tail value
