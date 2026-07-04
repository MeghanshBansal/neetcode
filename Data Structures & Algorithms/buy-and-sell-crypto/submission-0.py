class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) == 0:
            return 0;
        profit = 0
        buy = prices[0]

        for i in range(1, len(prices)):
            if buy > prices[i]:
                buy = prices[i]
            if prices[i] - buy > profit:
                profit = max(prices[i]-buy, profit)

        return profit