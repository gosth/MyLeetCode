class Solution {
public:
  // 是否有环
  bool DFS(int index,
           const std::unordered_map<int, std::unordered_set<int>>& graph,
           std::unordered_set<int>* visited,
           int father_node) {
    visited->emplace(index);
    if (auto iter = graph.find(index); iter != graph.end()) {
      for (auto next_node_iter = iter->second.begin(); next_node_iter != iter->second.end();
      ++next_node_iter) {
        if (*next_node_iter != father_node) {
          if (visited->find(*next_node_iter) == visited->end()) {
            DFS(*next_node_iter, graph, visited, index);
          } else {
            return true;
          }
        }
      }
    }
    return false;
  }

  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    std::unordered_map<int, std::unordered_set<int>> graph;
    for (const auto& edge : edges) {
      graph[edge.front()].emplace(edge.back());
      graph[edge.back()].emplace(edge.front());
    }
    for (auto r_iter = edges.rbegin(); r_iter != edges.rend(); ++r_iter) {
      graph[r_iter->front()].erase(r_iter->back());
      graph[r_iter->back()].erase(r_iter->front());
      std::unordered_set<int> visited;
      // 第一个节点id为1，没有父节点设为-1
      bool have_circle = DFS(1, graph, &visited, -1);
      if (!have_circle && visited.size() == edges.size()) {
        return *r_iter;
      }
      graph[r_iter->front()].emplace(r_iter->back());
      graph[r_iter->back()].emplace(r_iter->front());
    }
    return {};
  }
};