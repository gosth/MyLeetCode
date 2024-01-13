#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    struct node {
        int val;
        int x, y;

        bool operator<(const node &other) const {
            return val > other.val;
        }
    };

    node Add(int val, int x, int y) {
        return (node) {val, x, y};
    }

    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        priority_queue <node> q;
        vector<vector<int>> ans;
        int n, m;
        n = nums1.size();
        m = nums2.size();
        for (int i = 0; i < min(k, n); i++) {
            q.push(Add(nums1[i] + nums2[0], i, 0));
        }
        while (!q.empty() && k) {
            node tmp = q.top();
            q.pop();
            k--;
            int x, y;
            x = tmp.x;
            y = tmp.y;
            vector<int> c;
            c.push_back(nums1[x]);
            c.push_back(nums2[y]);
            ans.push_back(c);
            if (m > y + 1) q.push(Add(nums1[x] + nums2[y + 1], x, y + 1));
        }
        return ans;
    }
};

/** 这道双指针没做出来，得用最小堆
作者：无尽
链接：https://leetcode.cn/problems/find-k-pairs-with-smallest-sums/
**/