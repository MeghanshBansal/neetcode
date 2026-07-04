class Solution {
   public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> graph;
        for (vector<int>& flight : flights) {
            // src = [[price, destination]]
            graph[flight[0]].push_back({flight[2], flight[1]});
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;

        // cost, node, stop
        q.push({0, src, 0});

        vector<int> stops_to_node(n, int(1e9));

        while (!q.empty()) {
            auto current = q.top();
            q.pop();

            int current_node = current[1];
            int current_price = current[0];
            int current_far = current[2];

            if (current_node == dst) return current_price;

            if (current_far > k) continue;

            if (current_far >= stops_to_node[current_node]) continue;

            stops_to_node[current_node] = current_far;

            for (const auto& neighbour : graph[current_node]) {
                int new_dest = neighbour.second;
                int new_dest_price = neighbour.first;
                q.push({current_price + new_dest_price, new_dest, current_far + 1});
            }
        }

        return -1;  // destination unreachable
    }
};
