#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    void
    DFS(const std::string &s, int start_index, int cut_length, std::string *candidate, std::set<std::string> *results,
        int *dot_count) {
        if (*dot_count == 4 && start_index < s.size()) {
            return;
        }
        if (start_index == s.size() && (*dot_count == 4)) {
            auto result = *candidate;
            result.pop_back();
            results->emplace(result);
            return;
        }
        if (start_index + cut_length > s.size()) {
            return;
        }
        const std::string &target = s.substr(start_index, cut_length);
        if (target.size() >= 2 && target.front() == '0') {
            return;
        }
        int value = std::stoi(target);
        if (value > 255) {
            return;
        }
        (*candidate) += target + ".";
        (*dot_count) += 1;
        for (int length = 1; length <= 3; ++length) {
            DFS(s, start_index + cut_length, length, candidate, results, dot_count);
        }
        candidate->resize(candidate->size() - target.size() - 1);
        (*dot_count) -= 1;
    }

    vector<string> restoreIpAddresses(string s) {
        if (s.empty()) {
            return {};
        }
        std::vector<std::string> results;
        std::set<std::string> results_set;
        std::string candidate;
        int dot_count = 0;
        for (int length = 1; length <= 3; ++length) {
            DFS(s, 0, length, &candidate, &results_set, &dot_count);
        }
        for_each(results_set.begin(), results_set.end(), [&](const std::string &item) { results.emplace_back(item); });
        return results;
    }
};