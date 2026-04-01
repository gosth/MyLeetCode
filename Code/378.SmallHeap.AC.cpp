struct ValueNode {
	int m_lineNum, m_columnNum, m_value;

	ValueNode(int lineNum, int columnNum, int value) : m_lineNum(lineNum), m_columnNum(columnNum), m_value(value) {
	}

	bool operator<(const ValueNode& node) const {
		return m_value > node.m_value;
	}
};


class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		int num = 0, result = 0;
		if (matrix.empty() || matrix.front().empty()) {
			return result;
		}
		int lines = matrix.size(), columns = matrix.front().size();
		std::priority_queue<ValueNode> store;
		std::set<std::pair<int, int>> uniq;
		store.emplace(ValueNode(0, 0, matrix[0][0]));
		uniq.emplace(std::make_pair(0, 0));
		while (num != k) {
			const auto node = store.top();
			result = node.m_value;
			if (node.m_lineNum + 1 < lines) {
				std::pair<int, int> pos{ node.m_lineNum + 1, node.m_columnNum };
				if (uniq.find(pos) == uniq.end()) {
					store.emplace(ValueNode(node.m_lineNum + 1, node.m_columnNum,
						matrix[node.m_lineNum + 1][node.m_columnNum]));
					uniq.emplace(pos);
				}
			}
			if (node.m_columnNum + 1 < columns) {
				std::pair<int, int> pos{ node.m_lineNum, node.m_columnNum + 1};
				if (uniq.find(pos) == uniq.end()) {
					store.emplace(ValueNode(node.m_lineNum, node.m_columnNum + 1,
						matrix[node.m_lineNum][node.m_columnNum + 1]));
					uniq.emplace(pos);
				}
			}
			store.pop();
			++num;
		}
		return result;
	}
};