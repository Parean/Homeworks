generateList n = [1..n] >>= (\x->[x*y| y<-[1..n]])
