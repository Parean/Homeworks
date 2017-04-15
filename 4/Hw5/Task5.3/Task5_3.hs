import Control.Monad

getFirstMax (a:b:c:list) = mplus (if a < b && b > c then Just b else Nothing) (getFirstMax (b:c:list))
getFirstMax _ = Nothing
