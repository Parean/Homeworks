findFirstPositionOfMaxElements :: [Int] -> Int
findFirstPositionOfMaxElements list = head $ foldl findPosition [0, head list, 0] list where
  findPosition [position, summ, predHead] currHead = if newSumm > summ
                                                     then [position + 1, newSumm, currHead]
                                                     else [position, summ, currHead] where
                                                        newSumm = currHead + predHead 
