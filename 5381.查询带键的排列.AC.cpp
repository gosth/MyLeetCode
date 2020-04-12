class Solution {

    inline const int iterator_to_index(const deque<int>& temp, deque<int>::iterator it) {
        return it - temp.begin();
    }

public:
    vector<int> processQueries(vector<int>& queries, int m) {
        deque<int> temp;
        vector<int> result;
        for (int i = 1; i <= m; ++i) {
            temp.push_back(i);
        }
        for (const auto& item : queries) {
            const auto& iter = std::find(temp.begin(), temp.end(), item);
            result.emplace_back(iterator_to_index(temp, iter));
            temp.erase(iter);
            temp.push_front(item);
        }
        return result;
    }
};