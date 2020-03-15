class Solution {
public:
    int superEggDrop(int K, int N) {
        std::map<std::pair<int, int>, int> memo;
        return dp(K, N, &memo);
    }

    int dp(int K, int N, std::map<std::pair<int, int>, int>* memo) {
        if (K == 1) {
            return N;
        }
        if (N == 0) {
            return 0;
        }
        const auto& key = std::make_pair(K, N);
        const auto iter = memo->find(key);
        if (iter != memo->end()) {
            return iter->second;
        }
        int result = INT_MAX;
        int low = 1, high = N;
        while (low <= high) {
            int mid = (low + high) / 2;
            int broken = dp(K - 1, mid - 1, memo);  // 碎
            int notBroken = dp(K, N - mid, memo);  // 没碎
            if (broken > notBroken) {
                high = mid - 1;
                result = std::min(result, broken + 1);
            } else {
                low = mid + 1;
                result = std::min(result, notBroken + 1);
            }
        }
        memo->insert(std::make_pair(key, result));
        return result;
    }
};