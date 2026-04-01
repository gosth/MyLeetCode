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
    bool isAnagram(string s, string t) {
        if (s.size() != t.size() || s == t) {
            return false;
        }
        std::unordered_map<char, int> s_counting, t_counting;
        for (const auto& s_item : s) {
            s_counting[s_item] += 1;
        }
        for (const auto& t_item : t) {
            t_counting[t_item] += 1;
        }
        if (s_counting.size() != t_counting.size()) {
            return false;
        }
        for (const auto& [key, value] : s_counting) {
            if (auto iter = t_counting.find(key); iter == t_counting.end()) {
                return false;
            } else {
                if (iter->second != value) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<vector<string>> equations{{"a", "b"},
                                     {"b", "c"}};
    vector<double> values{2.0, 3.0};
    vector<vector<string>> queries{{"b", "a"}};
    const auto &results = s.calcEquation(equations, values, queries);
    cout << "result=";
    for (int i = 0; i < results.size(); ++i) {
        cout << results[i] << "|";
    }
    cout << endl;
}


