class MedianFinder {
public:
	MedianFinder() {

	}

	void addNum(int num) {
		data.push_back(num);
	}

	double findMedian() {
		sort(data.begin(), data.end());
		if (data.size() % 2 == 1) {
			return data[data.size() / 2];
		}
		size_t mid = data.size() / 2;
		return (data[mid - 1] + data[mid]) * 1.0 / 2;
	}

private:
	std::vector<int> data;
};