class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		priority_queue<int, std::vector<int>, std::greater<int> > smallHeap;
		for (size_t i = 0; i < nums.size(); ++i) {
			const int item = nums[i];
			if (smallHeap.size() < k) {
				smallHeap.push(item);
			}
			else {
				if (item > smallHeap.top()) {
					smallHeap.pop();
					smallHeap.push(item);
				}
			}
		}
		return smallHeap.top();
	}
};