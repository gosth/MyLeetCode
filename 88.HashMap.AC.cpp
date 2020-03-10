class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        std::map<int, int> numSet;
        for (int i = 0; i < m; ++i) {
            numSet[nums1[i]] += 1;
        }
        for (int i = 0; i < n; ++i) {
            numSet[nums2[i]] += 1;
        }
        nums1.clear();
        for (const auto& num : numSet) {
            for (int i = 0; i < num.second; ++i) {
                nums1.emplace_back(num.first);    
            }
        }
        return;
    }
};