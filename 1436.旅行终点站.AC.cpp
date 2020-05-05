class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        std::map<string, string> m;
        for (const auto& path : paths) {
            m.emplace(path.front(), path.back());
        }
        std::string begin = m.begin()->first;
        while(m.find(begin) != m.end()){
            begin = m[begin];
        }
        return begin;
    }
};