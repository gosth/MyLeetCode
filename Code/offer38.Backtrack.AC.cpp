class Solution {
public:
    void buildOnePath(const std::string& s,
            std::vector<bool>* indexSet,
            std::string* result,
            std::set <std::string>* results) {
        if (result->size() == s.size()) {
            results->emplace(*result);
            return;
        }
        for (int i = 0; i < s.size(); ++i) {
            if ((*indexSet)[i]) {
                continue;
            } else {
                (*indexSet)[i] = true;
                *result += s[i];
                buildOnePath(s, indexSet, result, results);
                (*indexSet)[i] = false;
                result->pop_back();
            }
        }

    }

    vector <string> permutation(string s) {
        if (s.empty()) {
            return std::vector<std::string>();
        }
        std::set <std::string> results;
        std::vector <std::string> realResults;
        for (int i = 0; i < s.size(); ++i) {
            std::string result = s.substr(i, 1);
            std::vector<bool> indexSet(s.size());
            indexSet[i] = true;
            buildOnePath(s, &indexSet, &result, &results);
        }
        for (const auto& item : results) {
            realResults.emplace_back(item);
        }
        return realResults;

    }
};