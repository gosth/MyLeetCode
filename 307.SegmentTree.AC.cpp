// pos为线段树当前节点下标(value的下标)，left,right为当前树节点对应的区间下标（nums的下标）
void buildSegmentTree(std::vector<int>* value, const std::vector<int>& nums, int pos, int left, int right) {
	if (left == right) {
		value->operator[](pos) = nums[left];
		return;
	}
	int mid = (left + right) / 2;
	buildSegmentTree(value, nums, 2 * pos + 1, left, mid);
	buildSegmentTree(value, nums, 2 * pos + 2, mid + 1, right);
	value->operator[](pos) = value->operator[](2 * pos + 1) + value->operator[](2 * pos + 2);
}

int sumRangeSegmentTree(const std::vector<int>& value,
	int pos,
	int left,
	int right,
	int qLeft,
	int qRight) {
	if (right < qLeft || left > qRight) {
		return 0;
	}
	if (qRight >= right && qLeft <= left) {
		return value[pos];
	}
	int mid = (left + right) / 2;
	return sumRangeSegmentTree(value, 2 * pos + 1, left, mid, qLeft, qRight) +
		sumRangeSegmentTree(value, 2 * pos + 2, mid + 1, right, qLeft, qRight);
}

// index为要更新的数在原始数组中的下标，不是value的下标
void updateSegmentTree(std::vector<int>* value, int pos, int left, int right, int index, int newValue) {
	if (left == right) {
		value->operator[](pos) = newValue;
		return;
	}
	int mid = (left + right) / 2;
	if (index <= mid) {
		updateSegmentTree(value, pos * 2 + 1, left, mid, index, newValue);
	}
	else {
		updateSegmentTree(value, pos * 2 + 2, mid + 1, right, index, newValue);
	}
	value->operator[](pos) = value->operator[](2 * pos + 1) + value->operator[](2 * pos + 2);
}

class NumArray {
public:
	NumArray(vector<int>& nums) {
		if (nums.empty()) {
			return;
		}
		for (int i = 0; i < 4 * nums.size(); ++i) {
			m_treeNodes.emplace_back(0);
		}
		buildSegmentTree(&m_treeNodes, nums, 0, 0, nums.size() - 1);
		m_rightEnd = nums.size() - 1;
	}

	void update(int i, int val) {
		updateSegmentTree(&m_treeNodes, 0, 0, m_rightEnd, i, val);
	}

	int sumRange(int i, int j) {
		return sumRangeSegmentTree(m_treeNodes, 0, 0, m_rightEnd, i, j);
	}

private:
	std::vector<int> m_treeNodes;
	int m_rightEnd;
};

/**
* Your NumArray object will be instantiated and called as such:
* NumArray* obj = new NumArray(nums);
* obj->update(i,val);
* int param_2 = obj->sumRange(i,j);
*/