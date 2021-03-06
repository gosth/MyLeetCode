class MedianFinder {
public:
	/** initialize your data structure here. */
	MedianFinder() {

	}

	void addNum(int num) {
		data.push_back(num);
	}

	double findMedian() {
		if (data.size() % 2 == 1) {
			int Kminus1thLargest = 0;
			return findKthLargest(data, data.size() / 2 + 1, &Kminus1thLargest);
		}
		else {
			int Kminus1thLargest = 0;
			int KthLargest = findKthLargest(data, data.size() / 2 + 1, &Kminus1thLargest);
			return (Kminus1thLargest + KthLargest) * 1.0 / 2;
		}

	}

	int findKthLargest(vector<int>& nums, int k, int* Kminus1thLargest) {
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
		int KthLarget = smallHeap.top();
		smallHeap.pop();
		*Kminus1thLargest = smallHeap.top();
		return KthLarget;
	}

private:
	std::vector<int> data;
};