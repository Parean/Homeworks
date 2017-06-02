import System.Random

data BST a = Node (BST a) a (BST a) | Empty
    deriving Show

size (Node l _ r) = 1 + size l + size r
size Empty = 0

height (Node l _ r) = 1 + max (height l) (height r)
height Empty = 0

contains _ Empty = False
contains x (Node l v r)
    | x < v = contains x l
    | x > v = contains x r
    | x == v = True

insert x Empty = Node Empty x Empty
insert x (Node l v r)
    | x < v  = Node (insert x l) v r
    | x > v  = Node l v (insert x r)
    | x == v = Node l v r

remove x Empty = Empty
remove x (Node l v r)
    | x < v  = Node (remove x l) v r
    | x > v  = Node l v (remove x r)
    | x == v =
        case (l, r) of
            (Empty, Empty) -> Empty
            (_, Empty)     -> l
            (Empty, _)     -> r
            otherwise      ->
                Node l m r' where
                    m = minValue r where
                        minValue (Node Empty v' _) = v'
                        minValue (Node l' _ _)     =  minValue l'

                    r' = remove m r

getRandomTree (Node l v r) = Node (getRandomTree l) (fst $ randomR (-100, 100) (mkStdGen v)) (getRandomTree r)
getRandomTree _ = Empty
