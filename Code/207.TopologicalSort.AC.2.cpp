#include <iostream>
#include<vector>
#include<unordered_map>
#include <set>
#include <deque>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        vector<int> indegree(numCourses);
        vector<vector<int>> graph(numCourses);//构建临接表（用vector储存临接点，方便访问）
        for (int i = 0; i < prerequisites.size(); ++i) {
            indegree[prerequisites[i][0]]++;
            graph[prerequisites[i][1]].emplace_back(prerequisites[i][0]);
        }

        std::vector<int> q;
        for (int i = 0; i < indegree.size(); ++i) {
            if (indegree[i] == 0) {
                q.emplace_back(i);
            }
        }
        int count = 0;
        while (!q.empty()) {

            int current = q.back();
            q.pop_back();
            count++;
            for (int i = 0; i < graph[current].size(); ++i) {
                indegree[graph[current][i]]--;
                if (indegree[graph[current][i]] == 0) {
                    q.emplace_back(graph[current][i]);
                }
            }
        }
        return count == numCourses;
    }
};

int main() {
    Solution a;
    vector<int> b{0, 1};
    vector<vector<int>> c;
    c.emplace_back(b);
    cout << a.canFinish(2, c);
}
