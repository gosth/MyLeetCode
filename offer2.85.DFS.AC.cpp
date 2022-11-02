#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    void DFS(int n, int left_used, int right_used, std::string *state, std::vector<std::string> *results) {
        if (left_used == n && right_used == n) {
            results->emplace_back(*state);
            return;
        }
        if (right_used > left_used) {
            return;
        }
        if (left_used < n) {
            state->append("(");
            DFS(n, left_used + 1, right_used, state, results);
            state->pop_back();
        }
        if (right_used < n) {
            state->append(")");
            DFS(n, left_used, right_used + 1, state, results);
            state->pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        int left_used = 1, right_used = 0;
        std::string state = "(";
        std::vector<std::string> results;
        DFS(n, left_used, right_used, &state, &results);
        return results;
    }
};