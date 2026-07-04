import math
class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        def distance(point):
            x, y = point
            return math.sqrt(x ** 2 + y ** 2)

        points.sort(key=distance)
        return points[:k]