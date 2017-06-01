import Data.List

data Poly = Poly [Integer]

addPoly (Poly p1) (Poly p2) = Poly (addPoly' p1 p2)
addPoly' p1 p2 = if (length p1 >= length p2)
                    then (zipWith (+) p1 (p2 ++ (repeat 0)))
                    else addPoly' p2 p1

multiplyByConst a (Poly p1) = Poly (map (a*) p1)

multiplyByX (Poly pl) = Poly (0 : pl)

multiplyByPoly (Poly []) p2 = Poly []
multiplyByPoly (Poly (p:p1)) p2 = let pTimesP2 = multiplyByConst p p2
                                      xTimesP1TimesP2 = multiplyByX $ multiplyByPoly (Poly p1) p2
                                  in addPoly pTimesP2 xTimesP1TimesP2

showPoly [] = show 0
showPoly p =  intercalate " + " (reverse summands)
            where
                  coeffs = zip p [0..]
                  nonZeroCoeffs = filter (\(c,_) -> c /= 0) coeffs

                  coeffShow c = if c == 1
                            then ""
                            else show c

                  nShow n = case n of
                              0 -> ""
                              1 -> "x"
                              m -> "x^" ++ show m

                  coeffAndNShow (c, n) = if c == 1 && n == 0
                               then show 1
                               else concat $ filter (/="") [coeffShow c, nShow n]

                  summands = map coeffAndNShow nonZeroCoeffs

instance Show Poly  where
    show (Poly pl) = showPoly pl

f = show (Poly [0,1,2,3])
