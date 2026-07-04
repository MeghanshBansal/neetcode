class Solution {
public:
    bool isValid(string s) {
        if (s.length() % 2 != 0) return false; 
        stack<char> st;
        for (char c: s)
        {
            if (c == '(' || c == '{' || c == '[') 
                st.push(c);
            else 
            {
                if (!st.empty() && ((c == ')' && st.top() == '(') || (c == '}' && st.top() == '{') || (c == ']' && st.top() == '['))) 
                    st.pop();
                else return false;
            }
        }
        if (st.empty()) return true; 
        return false;
    }
};
