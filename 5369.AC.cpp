class Solution {
public:
    int numTeams(vector<int>& rating) {
        int result = 0;
        for (size_t i = 0; i < rating.size(); ++i) {
            for (size_t j = i + 1; j < rating.size(); ++j) {
                bool isBigger = rating[j] > rating[i] ? true : false;
                for (size_t k = j + 1; k < rating.size(); ++k) {
                    if (isBigger) {
                        if (rating[k] > rating[j]) {
                            result += 1;
                        }
                    } else {
                        if (rating[k] < rating[j]) {
                            result += 1;
                        }
                    }
                }
            }
        }
        return  result;
    }
};