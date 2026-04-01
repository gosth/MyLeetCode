class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        bool result = true;
        bool isEnd = false;
        int begin = 0, next = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                begin = i;
                break;
            }
        }
        for (int i = begin + 1; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                next = i;
                break;
            }
        }
        if (next == 0) {
            isEnd = true;
        } 
        while (1 && !isEnd) {
            if (next - begin > k) {
                begin = next;
                for (int i = next + 1; i < nums.size(); ++i) {
                    if (nums[i] == 1) {
                        next = i;
                        break;
                    }
                }
                if (begin == next) {
                    isEnd = true;
                }
            } else {
                result = false;
                break;
            }
        }
        return result;
    }
};