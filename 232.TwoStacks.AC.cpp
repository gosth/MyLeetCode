class MyQueue {
public:
	/** Initialize your data structure here. */
	MyQueue() : index(0) {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		dataStack[index].push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		while (dataStack[index].size() > 1) {
			dataStack[!index].push(dataStack[index].top());
			dataStack[index].pop();
		}
		int ret = dataStack[index].top();
		dataStack[index].pop();
		while (!dataStack[!index].empty()) {
			dataStack[index].push(dataStack[!index].top());
			dataStack[!index].pop();
		}
		return ret;
	}

	/** Get the front element. */
	int peek() {
		while (dataStack[index].size() > 1) {
			dataStack[!index].push(dataStack[index].top());
			dataStack[index].pop();
		}
		int ret = dataStack[index].top();
		while (!dataStack[!index].empty()) {
			dataStack[index].push(dataStack[!index].top());
			dataStack[!index].pop();
		}
		return ret;
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return dataStack[index].empty();
	}

private:
	stack<int> dataStack[2];
	size_t index;
};