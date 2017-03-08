createListOfTwoDegrees :: Integral a => a -> [a]
createListOfTwoDegrees n = createList n [] where
  createList 0 list = list
  createList n list = createList (n - 1) $ (2 ^ n) : list
