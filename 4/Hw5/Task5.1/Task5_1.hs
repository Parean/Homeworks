getSummands 0 = [[]]
getSummands n = [s:ss | s<-[1..n], ss<-getSummands(n - s)]
