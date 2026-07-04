class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev1 = 0, prev2 = 0;
        int current = 0;
        for (int i = 2; i <= cost.size(); ++i)
        {
            current = min(cost[i-1] + prev1, cost[i-2] + prev2);
            prev2 = prev1;
            prev1 = current;
        }   
        return prev1;
    }
};
