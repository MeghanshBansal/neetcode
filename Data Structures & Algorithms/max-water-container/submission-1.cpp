class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_water = 0;
        int i = 0, j = heights.size() - 1;
        while ( i < j)
        {
            int water = min(heights[i], heights[j]) * (j - i);
            max_water = max(water, max_water);
            if (heights[i] < heights[j])
            {
                i++;
            }
            else
            {
                --j;
            }
        }
        return max_water;
    }
};
