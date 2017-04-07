import Control.Monad
data Tree a = Leaf a | Node (Tree a) a (Tree a) deriving (Show)

search (Leaf a) pred1 pred2 = if pred1 * pred2 == a then Just a else Nothing
search (Node left a right) pred1 pred2 = mplus (if pred1 * pred2 == a then Just a else Nothing) (mplus (search left a pred1) (search right a pred1))

getElement (Node (Node left a right) b c) = mplus (search left a b) (mplus (search right a b) (search c a b))
getElement (Node (Leaf a) b c) = search c a b
getElement _ = Nothing

exampleTree = (Node (Node (Leaf 26) 4 (Leaf 21)) 5 (Node (Leaf 24) 6 (Node (Leaf 3) 15 (Leaf 4))))
