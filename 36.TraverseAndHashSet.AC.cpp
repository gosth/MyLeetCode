class Solution {
public:
    bool isHitHistoryData(std::set<char>* historyData, char item) {
        if (historyData->find(item) == historyData->end()) {
            historyData->emplace(item);
            return false;
        }
        return true;
    }

    bool isValidSudoku(vector <vector<char>>& board) {
        if (board.empty() || board.front().empty()) {
            return false;
        }
        // 行、列去重用
        std::vector <std::set<char>> linesSets(9, std::set<char>()), columnsSets(9, std::set<char>());
        // 数独子块去重用（相邻的9个格）
        std::vector < std::vector < std::set < char>>> areaSets(3,
                std::vector < std::set < char >> (3, std::set<char>()));
        const int lines = board.size(), columns = board.front().size();
        for (int line = 0; line < lines; ++line) {
            const int lineAreaSetIndex = line / 3;
            std::vector <std::set<char>>& lineAreaSets = areaSets[lineAreaSetIndex];
            auto& lineSet = linesSets[line];
            for (int column = 0; column < columns; ++column) {
                auto& columnSet = columnsSets[column];
                const auto& item = board[line][column];
                if (item == '.') {
                    continue;
                }
                const int columnAreaSetIndex = column / 3;
                auto& areaSet = lineAreaSets[columnAreaSetIndex];

                if (isHitHistoryData(&lineSet, item) ||
                        isHitHistoryData(&columnSet, item) ||
                        isHitHistoryData(&areaSet, item)) {
                    return false;
                }
            }
        }
        return true;
    }
};