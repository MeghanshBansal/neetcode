class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> s_map;
        for (char c: s)
        {
            s_map[c]++;
        }

        for (char c: t)
        {
            s_map[c]--;
        }

        for (const auto &[key, value]: s_map)
        {
            if (value != 0) return false; 
        }

        return true; 
    }
};
