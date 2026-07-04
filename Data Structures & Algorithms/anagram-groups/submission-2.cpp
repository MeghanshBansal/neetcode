class Solution {
public:
    string get_key(string s)
    {
        vector<int> count(26, 0);
        for (char c: s)
        {
            count[c-'a']++;
        }

        string key = "";
        for (int i: count)
        {
            key += (to_string(i) + "->");
        }
        return key;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        for (const string &s: strs)
        {
            string key = get_key(s);
            mp[key].push_back(s);
        }

        for (const auto &[key, value]: mp)
        {
            ans.push_back(value);
        }

        return ans; 
    }
};
