class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int max_l = 0;
        int start = 0;
        int n = s.length();
        
        for (int i = 0; i < n; i++)
        {
            char c = s[i];
            
            if (mp.find(c) != mp.end())
            {
                start = max(start, mp[c] + 1);
            }

            int l = i - start + 1;
            max_l = max(l, max_l);
            mp[c] = i; 
        }

        return max_l;
    }
};
