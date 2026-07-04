class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.length() < s1.length()) return false;
        vector<int> s1_count(26, 0), s2_count(26, 0);
        for (char c: s1)
        {
            s1_count[c - 'a']++;
        }

        int n = s1.length();
        for (int i = 0; i < n; i++)
        {
            s2_count[s2[i]-'a']++;
        }

        if (is_equal(s1_count, s2_count)) return true;

        int m = s2.length();
        for (int i = n; i < m; i++)
        {
            s2_count[s2[i] - 'a']++;
            s2_count[s2[i - n] - 'a']--;
            if (is_equal(s1_count, s2_count)) return true;
        }

        return false;
    }

    const bool is_equal(const vector<int> &s1_count, const vector<int> &s2_count) const 
    {
        if (s1_count.size() != s2_count.size()) return false;
        return equal(s1_count.begin(), s1_count.end(), s2_count.begin());
    }
};
