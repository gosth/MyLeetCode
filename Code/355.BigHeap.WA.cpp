



struct FeatureMessage {
    int m_id;
    int64_t m_timeStamp;
    FeatureMessage(int id, int64_t timeStamp) : m_id(id), m_timeStamp(timeStamp) {};
    bool operator< (const FeatureMessage& featureMessage2) const {
        return m_timeStamp < featureMessage2.m_timeStamp;
    }
};

using FeatureStore = std::priority_queue<FeatureMessage>;

struct FeatureUser {
    int m_id;

    bool operator<(const FeatureUser& rhs) const {
        return m_id > rhs.m_id;
    }

    std::set<FeatureUser> m_focusFeatureUsers;
    std::vector<FeatureMessage> m_featureMessages;
    FeatureUser(int id) : m_id(id) {};
};

class Twitter {
private:
    std::map<int, FeatureUser> m_userInfos;
    int m_messageId = 0;
public:

    void pushFeatureGroup(int featureUserId, const std::map<int, FeatureUser>& userInfos, FeatureStore* featureStore) {
        if (featureStore->size() >= 10) {
            return;
        }
        auto iter = userInfos.find(featureUserId);
        if (iter != userInfos.end()) {
            for (auto innerIter = iter->second.m_featureMessages.rbegin(); innerIter != iter->second.m_featureMessages.rend(); ++innerIter) {
                featureStore->emplace(*innerIter);
                if (featureStore->size() >= 10) {
                    break;
                }
            }
        }
    }

    /** Initialize your data structure here. */
    Twitter() {

    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        ++m_messageId;
        FeatureMessage featureMessage(tweetId, m_messageId);
        auto iter = m_userInfos.find(userId);
        if (iter != m_userInfos.end()) {
            iter->second.m_featureMessages.emplace_back(featureMessage);
        }
        else {
            FeatureUser featureUser(userId);
            featureUser.m_featureMessages.emplace_back(featureMessage);
            m_userInfos.emplace(userId, featureUser);
        }
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        if (userId ==  2) {
            std::cout << "userId=2 call" << std::endl;
        }
        FeatureStore featureStore;
        pushFeatureGroup(userId, m_userInfos, &featureStore);
        auto iter = m_userInfos.find(userId);
        if (iter != m_userInfos.end()) {
            if (userId ==  2) {
                std::cout << "find userId=2, " << std::endl;
            }
            for (const auto& focus : iter->second.m_focusFeatureUsers) {
                if (userId ==  2) {
                    std::cout << "userId=2, " << focus.m_id << std::endl;
                }
                pushFeatureGroup(focus.m_id, m_userInfos, &featureStore);
            }
        }
        std::vector<int> results;
        while (!featureStore.empty()) {
            results.emplace_back(featureStore.top().m_id);
            featureStore.pop();
        }
        return  results;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followeeId == followerId) {
            return;
        }
        auto iter = m_userInfos.find(followerId);
        if (iter != m_userInfos.end()) {
            auto& focusFeatureUsers = iter->second.m_focusFeatureUsers;
            focusFeatureUsers.emplace(FeatureUser(followeeId));
        } else {
            FeatureUser featureUser(followerId);
            featureUser.m_focusFeatureUsers.emplace(FeatureUser(followeeId));
            m_userInfos.emplace(followerId, featureUser);
        }
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        auto iter = m_userInfos.find(followerId);
        if (iter != m_userInfos.end()) {
            auto& focusFeatureUsers = iter->second.m_focusFeatureUsers;
            auto innerIter = focusFeatureUsers.find(FeatureUser(followeeId));
            if (innerIter != focusFeatureUsers.end()) {
                focusFeatureUsers.erase(innerIter);
            }
        }
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