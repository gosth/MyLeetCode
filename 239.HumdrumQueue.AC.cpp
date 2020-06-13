 class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            std::vector<int> results;
            std::deque<int> q;
            for (int i = 0; i < nums.size(); ++i) {
                auto current = nums[i];
                if (!q.empty() && q.front() < i - k + 1) {
                    q.pop_front();
                }
                while (!q.empty() && current > nums[q.back()]) {
                    q.pop_back();
                }
                q.push_back(i);
                if (i >= k - 1) {
                    results.emplace_back(nums[q.front()]);
                }
            }
            return results;
        }
    };