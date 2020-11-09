class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.empty()) {
            return 0;
        }
        if (ratings.size() == 1) {
            return 1;
        }
        // left > right or left < right
        std::vector<int> left2Right(ratings.size(), 1), right2Left(ratings.size(), 1);
        for (size_t i = 1; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i - 1]) {
                left2Right[i] = left2Right[i - 1] + 1;
            }
        }

        for (int i = ratings.size() - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                right2Left[i] = right2Left[i + 1] + 1;
            }
        }
        int result = 0;
        for (size_t i = 0; i < ratings.size(); ++i) {
            result += std::max(left2Right[i], right2Left[i]);
        }
        return result;
    }
};