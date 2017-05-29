import Data.List
import Data.Maybe
import Control.Monad

data Graph = Graph [Int] [((Int,Int),Double)] deriving (Show)
data Path = Path { value  :: Int, dist :: Double, prev :: Int } deriving (Eq)

instance Show Path where
    show p = show (value p, dist p)

instance Ord Path where
    compare p1 p2 = dist p1 `compare` dist p2

dijkstra (Graph vs es) root = dijkstra' (map (\v -> Path v (if v == root then 0.0 else 1 / 0) v) vs) []
    where
          dijkstra' [] visited = visited
          dijkstra' unvisited visited = dijkstra' newUnvisited newVisited
              where
                    nearestNode = minimum unvisited
                    newVisited = nearestNode : visited
                    newUnvisited = (map (\p -> min p (getNewPath nearestNode p)) . delete nearestNode) unvisited
                    getNewPath (Path nearestNode nearestDist _) (Path currNode _ _) = Path currNode (nearestDist + distBetweenNodes nearestNode currNode) nearestNode

          distBetweenNodes n1 n2 = fromJust $ lookup (n1, n2) es `mplus` Just (1 / 0)

main = putStrLn $  show (dijkstra (Graph [1..4] [((1, 2), 5.0), ((1, 3), 18.0), ((2, 3), 13.0), ((2, 4), 7.0), ((3, 4), 3.0)]) 1)
