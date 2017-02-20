reverseList :: Integral a => [a] -> [a]
reverseList list = reverseList' list [] where
	reverseList' [] list = list
	reverseList' (headOfList : tailOfList) list = reverseList' tailOfList (headOfList : list)
