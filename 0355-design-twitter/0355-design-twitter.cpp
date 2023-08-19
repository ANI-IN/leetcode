class Twitter {
    map<int,set<int>> friends;
    int curr;
    priority_queue<vector<int>> pq;
public:
    Twitter() {
        friends.clear();
        curr=0;
        while(!pq.empty())
            pq.pop();
    }
    
    void postTweet(int userId, int tweetId) {
        pq.push({curr++,tweetId,userId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<vector<int>>q=pq;
        int n=0;
        vector<int> ans;
        while(!q.empty() && n<10)
        {
            auto it = q.top();
            q.pop();
            if(it[2]==userId || friends[userId].count(it[2]) )
            {
                ans.push_back(it[1]);
                n++;
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        friends[followerId].insert(followeeId);
        
    }
    
    void unfollow(int followerId, int followeeId) {
        friends[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */