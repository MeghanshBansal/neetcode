class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        n = len(position)
        time = [0] * n
        
        for i in range(n):
            time[i] = (position[i], speed[i])
            
        time.sort()
        stack = []
        for i in range(n-1, -1, -1):
            time_taken_by_car = float(target - time[i][0]) / float(time[i][1])
            if len(stack) == 0 or stack[-1] < time_taken_by_car:
                stack.append(time_taken_by_car)
                
        return len(stack)