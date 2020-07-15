class Solution {
public:
    int transfer(const char c) {
        return c - 'a';
    }

    int numKLenSubstrNoRepeats(string S, int K) {
        if (K > S.size() || !K) {
            return 0;
        }
        int rightIndex = 0, result = 0;
        std::set<char> existIds;
        std::vector<int> signs(26, -1);
        while (rightIndex < S.size()) {
            auto& item = S[rightIndex];
            if (existIds.find(item) != existIds.end()) {
                int targetIndex = signs[transfer(item)];
                for (auto existIter = existIds.begin(); existIter != existIds.end();) {
                    auto& existItem = *existIter;
                    if (signs[transfer(existItem)] > -1 && signs[transfer(existItem)] < targetIndex) {
                        signs[transfer(existItem)] = -1;
                        existIter = existIds.erase(existIter);
                    } else {
                        ++existIter;
                    }
                }
                signs[transfer(item)] = rightIndex;
            } else {
                if (K == existIds.size()) {
                    int itemIndex = -1, posIndex = INT_MAX;
                    for (auto existIter = existIds.begin(); existIter != existIds.end(); ++existIter) {
                        auto& existItem = *existIter;
                        if (signs[transfer(existItem)] > -1 && signs[transfer(existItem)] < posIndex) {
                            posIndex = signs[transfer(existItem)];
                            itemIndex = existItem;
                        }
                    }
                    signs[transfer(itemIndex)] = -1;
                    auto deleteIter = existIds.find(itemIndex);
                    if (deleteIter != existIds.end()) {
                        existIds.erase(deleteIter);
                    }
                    signs[transfer(item)] = rightIndex;
                    existIds.emplace(item);
                } else {
                    signs[transfer(item)] = rightIndex;
                    existIds.emplace(item);
                }
            }
            if (K == existIds.size()) {
                ++result;
            }
            ++rightIndex;
        }
        return result;
    }
};