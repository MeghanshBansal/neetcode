class Solution {
public:
    unordered_map<char, string> dig_map = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
    };

    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) return {};
        vector<string> ans;
        string curr = ""; 
        dfs(0, digits, ans, curr);
        return ans;     
    }

    void dfs(int index, string &digits, vector<string> &ans, string &curr)
    {
        if (index == digits.length()) 
        {
            ans.push_back(curr);
            return ;
        }

        string char_string = dig_map[digits[index]];
        string original_str = curr;
        for (char c: char_string)
        {
            curr += c;
            dfs(index + 1, digits, ans, curr);
            curr = original_str;
        }
    }
};
