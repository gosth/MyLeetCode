#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    void DFS(const std::string& source,
             const std::string& target,
             const std::unordered_map<std::string, std::set<std::pair<std::string, double>>>& graph,
             std::vector<double>* path,
             std::set<std::string>* visited,
             bool* is_reach) {
        if (source == target) {
            *is_reach = true;
            return;
        }
        if (auto neighbors_iter = graph.find(source); neighbors_iter != graph.end()) {
            for (const auto& neigh_node : neighbors_iter->second) {
                // neighbor为source的邻接节点，weight为source到neighbor的边权重
                const auto& neighbor = neigh_node.first;
                const auto& weight = neigh_node.second;
                if (visited->find(neighbor) != visited->end()) {
                    continue;
                }
                path->emplace_back(weight);
                visited->emplace(neighbor);
                DFS(neighbor, target, graph, path, visited, is_reach);
                if (*is_reach) {
                    return;
                }
                path->pop_back();
            }
        }
    }

    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        std::unordered_map<std::string, std::set<std::pair<std::string, double>>> graph;
        for (int index = 0; index < equations.size(); ++index) {
            const auto& equation = equations[index];
            graph[equation.front()].emplace(equation.back(), values[index]);
            graph[equation.back()].emplace(equation.front(), 1.0 / values[index]);
        }
        std::vector<double> results;
        for (const auto& query : queries) {
            const auto& source = query.front();
            const auto& target = query.back();
            if (graph.find(source) == graph.end() || graph.find(target) == graph.end()) {
                results.emplace_back(-1.0);
                continue;
            }
            if (source == target) {
                results.emplace_back(1.0);
                continue;
            }
            std::vector<double> path;
            std::set<std::string> visited;
            visited.emplace(source);
            bool is_reach = false;
            DFS(source, target, graph, &path, &visited, &is_reach);
            if (path.empty()) {
                results.emplace_back(-1.0);
            } else {
                results.emplace_back(
                        std::accumulate(path.begin(), path.end(), 1.0, std::multiplies<double>()));
            }
        }
        return results;
    }
};

int main() {
    Solution s;
    vector<vector<string>> equations{{"a","b"},{"b","c"}};
    vector<double> values{2.0,3.0};
    vector<vector<string>> queries {{"b","a"}};
    const auto& results = s.calcEquation(equations, values, queries);
    cout << "result=";
    for (int i = 0; i < results.size(); ++i) {
        cout << results[i] << "|";
    }
    cout << endl;
}


