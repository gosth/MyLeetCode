bool searchResult(const std::vector<std::vector<int>>& matrix,
	int lineEndPos,
	int columnStartPos,
	const size_t lines,
	const size_t columns,
	const int target) {
	bool result = false;
	if (lineEndPos >= 0 && columnStartPos >= 0 && columnStartPos < columns) {
		const auto& currentLastLine = matrix[lineEndPos];
		cout << currentLastLine.size() << "|" << columnStartPos << endl;
		// 左下角元素值
		const int leftDownItem = currentLastLine[columnStartPos];
		if (leftDownItem == target) {
			return true;
		}
		else if (target > leftDownItem) {
			return searchResult(matrix, lineEndPos, columnStartPos + 1, lines, columns, target);
		}
		else if (target < leftDownItem) {
			return searchResult(matrix, lineEndPos - 1, columnStartPos, lines, columns, target);
		}
	}
	return result;
}

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		const size_t lines = matrix.size();
		bool result = false;
		if (lines) {
			const size_t columns = matrix.front().size();
			if (columns) {
				return searchResult(matrix, lines - 1, 0, lines, columns, target);
			}
			else {
				return result;
			}
		}
		return result;
	}
};