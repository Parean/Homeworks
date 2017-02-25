fibonacci :: Integer -> Integer
fibonacci n = fibonacci' 0 1 n
  where fibonacci' curr prev n | n == 0   = curr
                               | n > 0    = fibonacci' (curr+prev) curr (n-1)
                               | n < 0    = fibonacci' prev (curr-prev) (n+1)
