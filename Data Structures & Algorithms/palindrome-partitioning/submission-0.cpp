class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr; 
        backtrack(0, curr, s, ans);
        return ans; 
    }   

    void backtrack(int index, vector<string> &curr, string &s, vector<vector<string>> &ans)
    {
        if (index == s.size())
        {
            ans.push_back(curr);
            return ;
        }

        for(int i = index; i < s.length(); i++)
        {
            if (isPalindrome(s.substr(index, i - index + 1)))
            {
                curr.push_back(s.substr(index, i - index + 1));
                backtrack(i + 1, curr, s, ans);
                curr.pop_back();
            }
        }
    }

    bool isPalindrome(string s)
    {
        int i = 0, j = s.length() - 1;
        while (i < j)
        {
            if (s[i] != s[j]) return false; 
            i++;
            j--;
        }
        return true; 
    }
};
