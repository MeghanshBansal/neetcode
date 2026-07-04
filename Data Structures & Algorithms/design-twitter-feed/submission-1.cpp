class Twitter {
public:
    int time = 0;
    unordered_map<int, vector<pair<int, int>>> posts;
    unordered_map<int, unordered_set<int>> followers;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        posts[userId].push_back({time, tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        if (posts.find(userId) != posts.end()) {
            for (auto& t : posts[userId]) {
                pq.push(t);
                if (pq.size() > 10) pq.pop();
            }
        }
        if (followers.find(userId) != followers.end()) {
            for (int followee : followers[userId]) {
                if (posts.find(followee) != posts.end()) {
                    for (auto& t : posts[followee]) {
                        pq.push(t);
                        if (pq.size() > 10) pq.pop();
                    }
                }
            }
        }

        vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return ;
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};
