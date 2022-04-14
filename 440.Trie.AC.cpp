#include <iostream>

using namespace std;

class Solution {
public:
    int findKthNumber(int n, int k) {
        int cur = 1;
        k -= 1;
        while (k > 0) {
            int nodes_num = GetSubtreeNodeNum(cur, n);
            if (k >= nodes_num) {
                k -= nodes_num;
                cur +=1;
            } else {
                k -= 1;
                cur *= 10;
            }
        }
        return cur;
    }

    int GetSubtreeNodeNum(int64_t cur, int n) {
        int64_t next = cur + 1;
        int node_num = 0;
        while (cur <= n) {
            node_num += std::min(next - cur, n - cur + 1);
            cur *= 10;
            next *= 10;
        }
        return node_num;
    }
};