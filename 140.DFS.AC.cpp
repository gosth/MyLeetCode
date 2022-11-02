#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        std::unordered_map<std::string, std::vector<std::string>> memo;
        return DFS(s, wordDict, memo);
    }

    std::vector<std::string> DFS(const std::string& s, std::vector<std::string>& wordDict,     std::unordered_map<std::string, std::vector<std::string>>& memo) {
        if (memo.find(s) != memo.end()) {
            return memo[s];
        }
        if (s.empty()) {
            return {""};
        }
        std::vector<std::string> result;
        for (const auto& word : wordDict) {
            if (s.substr(0, word.size()) == word) {
                const std::vector<std::string>& later_results = DFS(s.substr(word.size()), wordDict, memo);
                for (const auto& later_result : later_results) {
                    result.emplace_back(word + (later_result.empty() ? "" : " " + later_result));
                }

            }
        }
        memo[s] = result;
        return result;
    }
};

int main() {
    std::string a = "123", b = "123", c;
    if (a + "" == b) {
        cout << "euqal" << endl;
    }
    return 0;
}
