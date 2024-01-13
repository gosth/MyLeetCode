class Solution {
public:
    void FillMatrixIfOnlyHaveOneDifference(int first_index,
                                           int second_index,
                                           const std::vector<std::string>& wordList,
                                           std::vector<std::pair<int, int>>* matrix) {
        int difference = 0;
        const std::string& first_string = wordList[first_index];
        const std::string& second_string = wordList[second_index];
        for (int index = 0; index < first_string.size(); ++index) {
            if (first_string[index] != second_string[index]) {
                ++difference;
                if (difference > 1) {
                    return;
                }
            }
        }
        if (1 == difference) {
            matrix->emplace_back(first_index, second_index);
        }
    }

    // 使用BFS算法查找无向图中两个节点之间的最短路径
    std::vector<int> BFS(int start, int end, std::map<int, std::set<int>>& adj) {
        // BFS队列
        std::queue<int> q;
        // 节点的父节点
        std::map<int, int> parent;
        // 访问过的节点
        std::set<int> visited;

        // 起始节点的父节点设为-1，并将其加入队列中
        parent[start] = -1;
        q.push(start);

        // BFS搜索
        while (!q.empty()) {
            int v = q.front();
            q.pop();

            // 如果已经访问过该节点，跳过
            if (visited.count(v) > 0) {
                continue;
            }
            visited.insert(v);

            // 遍历与当前节点相邻的所有节点
            for (int u : adj[v]) {
                // 如果节点u还没有被访问过，那么将其加入队列中，并更新其父节点
                if (visited.count(u) == 0) {
                    q.push(u);
                    if (parent.count(u) == 0) {
                        parent[u] = v;
                    }
                    // 如果找到了目标节点，退出循环
                    if (u == end) {
                        break;
                    }
                }
            }
        }

        // 如果目标节点没有被访问过，说明起始节点无法到达目标节点，返回空向量
        if (visited.count(end) == 0) {
            return {};
        } else {
            // 构造起始节点到目标节点的最短路径
            std::vector<int> path;
            for (int v = end; v != -1; v = parent[v]) {
                path.push_back(v);
            }
            std::reverse(path.begin(), path.end());
            return path;
        }
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (std::find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return 0;
        }
        wordList.emplace_back(beginWord);
        wordList.emplace_back(endWord);
        std::vector<std::pair<int, int>> matrix;
        for (int i = 0; i <= wordList.size() - 2; ++i) {
            for (int j = i + 1; j < wordList.size(); ++j) {
                FillMatrixIfOnlyHaveOneDifference(i, j, wordList, &matrix);
            }
        }
        std::map<int, std::set<int>> matrix_2;
        for (const auto& [key, value] : matrix) {
            matrix_2[key].emplace(value);
            matrix_2[value].emplace(key);
        }
        const std::vector<int>& path = BFS(wordList.size() - 2, wordList.size() - 1, matrix_2);
        return path.size();
    }
};