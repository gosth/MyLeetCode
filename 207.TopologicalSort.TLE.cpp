#include <iostream>
#include<vector>
#include<unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (prerequisites.empty()) {
            return true;
        }
        std::vector<std::vector<int>> matrix(numCourses, std::vector<int>(numCourses, 0));
        for (const auto &item : prerequisites) {
            matrix[item.front()][item.back()] = 1;
        }
        std::set<int> used;
        bool change = true;
        while (used.size() != numCourses && change) {
            change = false;
            for (int j = 0; j < numCourses; ++j) {
                if (used.find(j) != used.end()) {
                    continue;
                }
                bool state = true;
                for (int i = 0; i < numCourses; ++i) {
                    if (matrix[i][j]) {
                        state = false;
                        break;
                    }
                }
                if (state) {
                    used.emplace(j);
                    change = true;
                    for (int k = 0; k < numCourses; ++k) {
                        if (1 == matrix[j][k]) {
                            matrix[j][k] = 0;
                        }
                    }
                }
            }
        }
        if (used.size() == numCourses) {
            return true;
        } else {
            return false;
        }
    }
};
