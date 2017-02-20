--return -1 if list does not contain the number

positionOfNumberInList :: [Int] -> Int -> Int
positionOfNumberInList list number = findPosition list number 1 where
  findPosition [] number position = -1
  findPosition (headOfList : tailOfList) number position
    | headOfList == number = position
    | otherwise = findPosition tailOfList number (position + 1)
