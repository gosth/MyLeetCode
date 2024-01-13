#include <iostream>

using namespace std;

class Solution {
public:
    void DFS(int index,
             int target_node_index,
             const std::vector<std::vector<int>>& graph,
             std::vector<int>* candidate_path,
             std::vector<std::vector<int>>* results) {
        candidate_path->emplace_back(index);
        if (index == target_node_index) {
            results->emplace_back(*candidate_path);
            candidate_path->pop_back();
            return;
        }
        for (auto& next_index : graph[index]) {
            DFS(next_index, target_node_index, graph, candidate_path, results);
        }
        candidate_path->pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int target_node_index = graph.size() - 1;
        std::vector<int> candidate_path;
        std::vector<std::vector<int>> results;
        DFS(0, target_node_index, graph, &candidate_path, &results);
        return results;
    }
};

int main() {
    cout << "hello" << endl;
}
