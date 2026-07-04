class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int min_value = INT_MAX;
        for (int i: prices)
        {
            min_value = min(min_value, i);
            max_profit = max(i - min_value, max_profit);
        }

        return max_profit;
    }
};
