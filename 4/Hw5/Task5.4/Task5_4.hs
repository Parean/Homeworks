data Expression = X | Const Int | Expression :+: Expression | Expression :-: Expression
                    | Expression :*: Expression | Expression :/: Expression | Expression :^: Int deriving(Eq, Show)


testExpr = ((Const 2 :+: Const 1 :+: (Const 1 :*: X)) :-: (Const 0 :/: ((X :+: X) :^: 3)))

derivate (fst :+: snd) = (derivate fst) :+: (derivate snd)
derivate (fst :-: snd) = (derivate fst) :-: (derivate snd)
derivate (fst :*: snd) = ((derivate fst) :*: snd) :+: (fst :*: (derivate snd))
derivate (fst :/: snd) = (((derivate fst) :*: snd) :-: (fst :*: (derivate snd))) :/: (snd :^: 2)
derivate (x :^: n) = (Const n :*: (x :^: (n - 1))) :*: (derivate x)
derivate (X) = Const 1
derivate (Const c) = Const 0

simplify :: Expression -> Expression
simplify (fst :+: snd) =  simplify' (simplify fst :+: simplify snd)
simplify (fst :-: snd) =  simplify' (simplify fst :-: simplify snd)
simplify (fst :*: snd) =  simplify' (simplify fst :*: simplify snd)
simplify (fst :/: snd) =  simplify' (simplify fst :/: simplify snd)
simplify (x :^: n) =  simplify' (simplify x :^: n)
simplify (X) = X
simplify (Const c) = Const c

simplify' :: Expression -> Expression
simplify' (x :-: Const 0) = x
simplify' (Const fst :-: Const snd) = Const (fst - snd)
simplify' (Const 0 :+: x) = x
simplify' (x :+: Const 0) = x
simplify' (Const fst :+: Const snd) = Const (fst + snd)
simplify' (Const 0 :*: x) = Const 0
simplify' (Const 1 :*: x) = x
simplify' (x :*: Const 1) = x
simplify' (x :*: Const 0) = Const 0
simplify' (Const fst :*: Const snd) = Const (fst * snd)
simplify' (Const 0 :/: x) = Const 0
simplify' (x :/: Const 1) = x
simplify' (Const fst :/: Const snd) = Const (fst `div` snd)
simplify' (Const 0 :^: x) = Const 0
simplify' (x :^: 0) = Const 1
simplify' (x :^: 1) = x
simplify' x = x
