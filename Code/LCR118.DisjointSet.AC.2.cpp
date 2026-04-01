class UnionFind {
private:
    // 存储每个节点的父节点
    std::vector<int> parent;
    // 存储以每个节点为根节点时，树的高度
    std::vector<int> rank;

public:
    // 初始化并查集，将所有节点的父节点设为它自己，将所有节点的树高度设为1
    UnionFind(int size) : rank(size, 1) {
        parent.resize(size);
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }
    }

    // 查找x所在的根节点
    int find(int x) {
        // 如果x的父节点不是它自己，说明x不是根节点，继续往上查找
        if (parent[x] != x) {
            // 路径压缩：将x的父节点设为它的根节点，减少查找路径
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // 合并x和y所在的集合
    void unionSet(int x, int y) {
        int root_x = find(x);
        int root_y = find(y);
        // 如果x和y的根节点相同，说明它们已经在同一个集合中，无需合并
        if (root_x == root_y) {
            return;
        }
        // 按秩合并：将树高度较小的根节点指向高度较大的根节点
        if (rank[root_x] > rank[root_y]) {
            parent[root_y] = root_x;
        } else if (rank[root_x] < rank[root_y]) {
            parent[root_x] = root_y;
        } else {
            parent[root_y] = root_x;
            rank[root_x] += 1;  // 如果两个树的高度相同，合并后高度加1
        }
    }

    // 判断x和y是否在同一个集合中
    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFind union_find(edges.size() + 1);
        for (const auto& edge : edges) {
            int node_1 = edge.front();
            int node_2 = edge.back();
            // 两个节点不在同一集合，就进行连接
            if (!union_find.isConnected(node_1, node_2)) {
                union_find.unionSet(node_1, node_2);
            } else {
                // 两点已经在同一集合了，现在又来了一条边，这条边就是多余的
                return edge;
            }
        }
        return {};
    }
};