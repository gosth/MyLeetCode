class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        if (orders.empty()) {
            return  vector<vector<string>>();
        }
        set<string> food;
        map<int, map<string, int>> data;
        for (auto& line : orders) {
            food.emplace(line[2]);
            data[std::stoi(line[1])][line[2]] += 1;
        }
        for (auto& line : data) {
            std::cout << line.first << ",";
        }
        std::cout << std::endl;;
        vector<vector<string>> result;
        result.resize(data.size() + 1);
        auto& line1 = result.front();
        line1.emplace_back("Table");
        for (auto& item : food) {
            line1.emplace_back(item);
        }
        int index = 0;
        for (auto& line : data) {
            ++index;
            auto& curLine = result[index];
            curLine.emplace_back(std::to_string(line.first));
            auto& curMenu = line.second;
            for (auto& item : food) {
                curLine.emplace_back(std::to_string(curMenu[item]));
            }
        }
        return result;
    }
};