class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";
        vector<int> t_count(128, 0);

        for (char c: t)
        {
            t_count[c]++;
        }   

        int required = t.length();
        int start = 0, end = 0;
        int min_length = INT_MAX;
        int start_index = 0;

        while (end < s.length())
        {
            char r_char = s[end];
            if (t_count[r_char] > 0) required--;
            t_count[r_char]--;

            while (required == 0)
            {
                if (end - start + 1 < min_length)
                {
                    min_length = end - start + 1;
                    start_index = start;
                }

                char l_char = s[start];
                t_count[l_char]++;
                if (t_count[l_char] > 0) required++;
                start ++;
            }
            end ++;
        }

        if (min_length == INT_MAX) return "";
        return s.substr(start_index, min_length);
    }
};
