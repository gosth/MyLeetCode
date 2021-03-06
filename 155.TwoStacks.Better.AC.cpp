class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() : index(0) {

	}

	void push(int x) {
		dataStack[index].push(x);
		if (dataStack[!index].empty() || x <= getMin()) {
			dataStack[!index].push(x);
		}
	}

	void pop() {
		if (top() == getMin()) {
			dataStack[!index].pop();
		}
		dataStack[index].pop();
	}

	int top() {
		return dataStack[index].top();
	}

	int getMin() {
		return dataStack[!index].top();
	}
private:
	stack<int> dataStack[2];
	size_t index;
};