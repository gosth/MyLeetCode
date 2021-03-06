class MyStack {
public:
	/** Initialize your data structure here. */
	MyStack() {

	}

	/** Push element x onto stack. */
	void push(int x) {
		dataQ.push(x);
		for (int i = 0; i < dataQ.size() - 1; ++i) {
			dataQ.push(dataQ.front());
			dataQ.pop();
		}
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int ret = dataQ.front();
		dataQ.pop();
		return ret;
	}

	/** Get the top element. */
	int top() {
		return dataQ.front();
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return dataQ.empty();
	}

private:
	queue<int> dataQ;
};