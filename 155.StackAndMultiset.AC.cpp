class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		dataStack.push(x);
		dataSet.insert(x);
	}

	void pop() {
		multiset<int>::iterator it = dataSet.find(dataStack.top());
		if (it != dataSet.end()) {
			dataSet.erase(it);
		}
		dataStack.pop();
	}

	int top() {
		return dataStack.top();
	}

	int getMin() {
		return *dataSet.begin();
	}
private:
	stack<int> dataStack;
	multiset<int> dataSet;
};