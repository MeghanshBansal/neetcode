class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for (string s: strs)
        {
            int length = s.length();
            encoded += (to_string(length) + "#" + s);
        }

        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0; 
        int l = s.length();
        while (i < l)
        {
            // getting length
            string str_len = "";
            while ((i < l) && (s[i] != '#' ))
            {
                str_len += s[i];
                i+=1;
            }
            int length = stoi(str_len);

            // skipping special char $
            i++;

            // take string
            string temp = "";
            int end_string_index = i + length;
            while (i < l && i < end_string_index)
            {
                temp += s[i];
                i+=1;
            }
            decoded.push_back(temp);
        }

        return decoded;
    }
};
