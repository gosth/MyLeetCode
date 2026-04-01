class DisjointSet {
public:
    DisjointSet(int n) {
        for (int i = 0; i < n; ++i) {
            m_id.emplace_back(i);
            m_size.emplace_back(1);
        }
        m_count = n;
    }

    int find(int p) {
        while(p != m_id[p]) {
            m_id[p] = m_id[m_id[p]];
            p = m_id[p];
        }
        return p;
    }

    void unionFunc(int p, int q) {
        int i = find(p);
        int j = find(q);
        if (i == j) {
            return;
        }
        if (m_size[i] > m_size[j]) {
            m_id[j] = i;
            m_size[j] += m_size[i];
        } else {
            m_id[i] = j;
            m_size[i] += m_size[j];
        }
        --m_count;
    }

    int count(){
        return m_count;
    }
private:
    std::vector<int> m_id;  // p的leader为m_id[p]
    std::vector<int> m_size;  // p为leader，对应的树size为m_size[p]
    int m_count;  // 集合数
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        DisjointSet disjointSet(M.size());
        for (int i = 0; i < M.size(); ++i) {
            for (int j = i + 1; j < M.size(); ++j) {
                if (M[i][j]) {
                    disjointSet.unionFunc(i, j);
                }
            }
        }
        return disjointSet.count();
    }
};