class Solution {
   public:
    string foreignDictionary(vector<string>& words) {
        vector<vector<bool>> graph(26, vector<bool>(26, false));
        vector<bool> seen(26, false);  // FIX: Set size to 26
        int cnt = 0;                   // FIX: Initialize to 0

        // 1. Gather all unique characters
        for (const string& word : words) {
            for (char c : word) {
                int char_pos = c - 'a';
                if (!seen[char_pos]) {
                    seen[char_pos] = true;
                    cnt++;
                }
            }
        }

        // 2. Build the dependency graph
        int n = words.size();
        for (int i = 0; i < n - 1; i++) {
            string first_word = words[i];
            string second_word = words[i + 1];

            // FIX: Invalid prefix validation (e.g., "apple" followed by "app")
            if (first_word.length() > second_word.length() &&
                first_word.substr(0, second_word.length()) == second_word) {
                return "";
            }

            // FIX: Use std::min to accurately constrain word comparisons
            int min_length = min(first_word.length(), second_word.length());
            for (int j = 0; j < min_length; j++) {  // FIX: Added 'int' declaration
                if (first_word[j] == second_word[j]) continue;

                int u = first_word[j] - 'a';
                int v = second_word[j] - 'a';

                if (graph[v][u]) return "";  // FIX: Added missing semicolon

                // Only add edge and break if it's a fresh dependency rule
                if (!graph[u][v]) {
                    graph[u][v] = true;
                }
                break;  // CRITICAL: Stop comparing after finding the first character
                        // difference
            }
        }

        // 3. Compute Indegrees
        vector<int> indegree(26, 0);
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (i != j && seen[i] && seen[j] && graph[i][j]) {
                    indegree[j]++;
                }
            }
        }

        // 4. Initialize Queue with 0-indegree nodes
        queue<int> q;  // Use int queue to process indices seamlessly
        unordered_set<char> already_processed;

        // FIX: Scan in original appearance order to safely prioritize sequence
        for (const string& word : words) {
            for (char c : word) {
                int char_pos = c - 'a';
                if (already_processed.find(c) == already_processed.end() && seen[char_pos] &&
                    indegree[char_pos] == 0) {  // FIX: Removed Python colon
                    q.push(char_pos);           // FIX: use push() instead of insert()
                    already_processed.insert(c);
                }
            }
        }

        // 5. Kahn's Algorithm Loop
        string ans = "";
        while (!q.empty()) {
            int t = q.front();  // FIX: Use front() for std::queue
            q.pop();

            ans += (char)('a' + t);  // FIX: Clean character type casting

            for (int i = 0; i < 26; i++) {
                if (seen[i] && graph[t][i]) {
                    indegree[i]--;
                    if (indegree[i] == 0) {
                        q.push(i);  // FIX: use push() instead of insert()
                    }
                }
            }
        }

        // 6. Validate if graph execution touched all letters (cycle validation)
        return cnt != ans.length() ? "" : ans;
    }
};
