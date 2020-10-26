// ConsoleApplication20.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include <iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;

struct Node {
	int m_value;
	std::vector<int> m_useIndex;
	Node(int value, std::vector<int> useIndex) : m_value(value), m_useIndex(useIndex) {};
};

struct cmp
{
	bool operator()(Node a, Node b)
	{
		return a.m_value > b.m_value;
	}
};


class Solution {
public:
	std::vector<std::vector<int>> getNextIndexs(const std::vector<int>& currentIndexs, int columns) {
		std::vector<std::vector<int>> nextIndexs;
		for (size_t index = 0; index < currentIndexs.size(); ++index) {
			if (currentIndexs[index] + 1 >= columns) {
				continue;
			}
			std::vector<int> newIndexs = currentIndexs;
			newIndexs[index] = currentIndexs[index] + 1;
			nextIndexs.emplace_back(newIndexs);
		}
		return nextIndexs;
	}

	Node buildNode(const std::vector<std::vector<int>>& mat, const std::vector<int>& currentIndexs) {
		int currentSum = 0;
		int line = 0;
		for (const auto& item : currentIndexs) {
			currentSum += mat[line][item];
			++line;
		}
		return Node(currentSum, currentIndexs);
	}

	int kthSmallest(vector<vector<int>>& mat, int k) {

		if (!k) {
			return 0;
		}
		int lines = mat.size();
		int columns = mat.size() > 0 ? mat.front().size() : 0;
		int result = 0;
		std::set<std::vector<int>> indexsSet;
		std::priority_queue<Node, std::vector<Node>, cmp> smallHeap;
		Node node = buildNode(mat, std::vector<int>(lines));
		smallHeap.emplace(node);
		indexsSet.emplace(std::vector<int>(lines));
		while (k--) {
			if (!k) {
				result = smallHeap.top().m_value;
				break;
			}
			const std::vector<std::vector<int>>& nextIndexs = getNextIndexs(
				smallHeap.top().m_useIndex, columns);
			smallHeap.pop();
			for (const auto& nextSequence : nextIndexs) {
				if (indexsSet.find(nextSequence) == indexsSet.end()) {
					indexsSet.emplace(nextSequence);
					smallHeap.emplace(buildNode(mat, nextSequence));
				}
			}
		}
		return result;
	}
};


//[[1, 3, 11], [2, 4, 6]]

int main() {
	Solution s;
	cout << s.kthSmallest(std::vector<std::vector<int>>{ std::vector<int>{1, 3, 11}, std::vector<int>{2, 4, 6}}, 9);
	getchar();
}
