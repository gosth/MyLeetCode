class MedianFinder {
public:
	// 有效数据下标从begin到end，即[begin, end]
	int partition(vector<int>& data, int begin, int end) {
		int target = data[end];
		int greaterIndex = -1;
		for (size_t i = begin; i < end; ++i) {
			int& item = data[i];
			if (greaterIndex == -1) {
				if (item <= target) {
					continue;
				}
				else {
					greaterIndex = i;
				}
			}
			else {
				if (item <= target) {
					int temp = item;
					item = data[greaterIndex];
					data[greaterIndex] = temp;
					++greaterIndex;
				}
				else {
					continue;
				}
			}
		}
		if (greaterIndex == -1) {
			return end;
		}
		else {
			int temp = data[end];
			data[end] = data[greaterIndex];
			data[greaterIndex] = temp;
			return greaterIndex;
		}
	}


	void qsort(vector<int>& data, int begin, int end, int targetIndex) {
		int now = partition(data, begin, end);
		if (targetIndex < now) {
			qsort(data, begin, now - 1, targetIndex);
		}
		if (targetIndex > now) {
			qsort(data, now + 1, end, targetIndex);
		}
		if (targetIndex == now) {
			return;
		}
	}
	/** initialize your data structure here. */
	MedianFinder() {

	}

	void addNum(int num) {
		data.push_back(num);
	}

	double findMedian() {
		// sort(data.begin(), data.end());
		if (data.size() % 2 == 1) {
			qsort(data, 0, data.size() - 1, data.size() / 2);
			return data[data.size() / 2];
		}
		else {
			qsort(data, 0, data.size() - 1, data.size() / 2 - 1);
			qsort(data, data.size() / 2, data.size() - 1, data.size() / 2);
			return (data[data.size() / 2 - 1] + data[data.size() / 2]) * 1.0 / 2;
		}
	}
private:
	std::vector<int> data;
};