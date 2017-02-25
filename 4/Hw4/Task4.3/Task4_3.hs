{-# LANGUAGE DeriveFoldable #-}
data Tree a = Leaf a | Node (Tree a) a (Tree a) deriving (Show, Foldable)

collectValues tree = foldr (:) [] tree
