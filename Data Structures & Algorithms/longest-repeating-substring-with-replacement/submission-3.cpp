class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int max_l = 0;
        int start = 0, end = 0;
        int max_occuring_char_count = 0;
        int n = s.length();
        while (end < n)
        {
            mp[s[end]]++;
            max_occuring_char_count = max(max_occuring_char_count, mp[s[end]]);
            while (end - start + 1 - max_occuring_char_count > k)
            {
                mp[s[start]]--;
                start ++;
            }

            max_l = max(max_l, end - start + 1);
            end ++;
        }

        return max_l;
    }
};
