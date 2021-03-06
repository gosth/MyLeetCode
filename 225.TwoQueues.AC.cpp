class MyStack {
public:
	/** Initialize your data structure here. */
	MyStack() : index(0) {

	}

	/** Push element x onto stack. */
	void push(int x) {
		dataQ[!index].push(x);
		while (!dataQ[index].empty()) {
			dataQ[!index].push(dataQ[index].front());
			dataQ[index].pop();
		}
		index = !index;
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int ret = dataQ[index].front();
		dataQ[index].pop();
		return ret;
	}

	/** Get the top element. */
	int top() {
		return dataQ[index].front();
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return dataQ[index].empty() ? true : false;
	}
private:
	queue<int> dataQ[2];
	size_t index;
};