class MedianFinder {
public:
	/** initialize your data structure here. */
	MedianFinder() {

	}

	void addNum(int num) {
		if (bigHeap.empty()) {
			bigHeap.push(num);
			return;
		}
		if (smallHeap.size() == bigHeap.size()) {
			if (num < bigHeap.top()) {
				bigHeap.push(num);
			}
			else {
				smallHeap.push(num);
			}
		}
		else if (bigHeap.size() > smallHeap.size()) {
			if (num > bigHeap.top()) {
				smallHeap.push(num);
			}
			else {
				smallHeap.push(bigHeap.top());
				bigHeap.pop();
				bigHeap.push(num);
			}
		}
		else if (bigHeap.size() < smallHeap.size()) {
			if (num < smallHeap.top()) {
				bigHeap.push(num);
			}
			else {
				bigHeap.push(smallHeap.top());
				smallHeap.pop();
				smallHeap.push(num);
			}
		}
	}

	double findMedian() {
		if (bigHeap.size() == smallHeap.size()) {
			return (bigHeap.top() + smallHeap.top()) * 1.0 / 2;
		}
		else if (bigHeap.size() > smallHeap.size()) {
			return bigHeap.top();
		}
		else {
			return smallHeap.top();
		}

	}

private:
	priority_queue<int, std::vector<int>, std::greater<int> > smallHeap;
	priority_queue<int, std::vector<int>, std::less<int> > bigHeap;

};