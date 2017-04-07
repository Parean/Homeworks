isSatisfiesCondition :: (a -> Bool) -> [a] -> Bool
isSatisfiesCondition f = foldl (\result x -> result && f x) True

