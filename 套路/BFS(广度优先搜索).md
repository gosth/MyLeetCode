# 广度优先搜索BFS
##定义
BFS，其英文全称是Breadth First Search。从算法的观点，所有因为展开节点而得到的子节点都会被加进一个先进先出的队列中。
直观地讲，它其实就是一种“地毯式”层层推进的搜索策略，即先查找离起始顶点最近的，然后是次近的，依次往外搜索。    
##遍历顺序
树的遍历：从根结点依此按层序依次遍历（从左至右）
图的遍历：从当前节点依次将与之关联的结点放入队列，逐步层次遍历

## 树的BFS实现
借助队列，通过循环实现

数据结构定义如下

```cpp
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

```

```cpp
void BFS(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    std::queue<TreeNode*> q;
    q.emplace(node);
    while(!q.empty()) {
        auto& current = q.front();
        q.pop();
        if (current->left) {
            q.emplace(current->left);
        }
        if (current->right) {
            q.emplace(current->right);
        }
    }
}

```

## 图的BFS实现
借助队列，通过循环实现
图的表示方法是邻接矩阵，即如果图有n个节点（编号0-n-1），其中节点1到节点2有条有向边，可以表示为如下代码

```cpp
  std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
  matrix[1][2] = 1;  

```
以无向图BFS遍历为例
```cpp
  std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
  // 构造邻接矩阵，如节点1和节点2相连
  matrix[1][2] = 1;  
  matrix[2][1] = 1;

  void BFS(int node, std::vector<std::vector<int>>& matrix) {
            std::deque<int> q;
            std::vector<int> result;
            // 访问过的节点
            std::set<int> visited;
            visited.emplace(node);
            q.emplace_back(node);
            result.emplace_back(node);
            while(!q.empty()){
                auto& current = q.front();
                q.pop_front();
                for (int i = 0; i < n; ++i) {
                    if (matrix[current][i]) {
                        if (visited.find(i) != visited.end()) {
                             matrix[current][i] = 0;
                             matrix[i][current] = 0;
                            continue;
                        }
                        q.emplace_back(i);
                        visited.emplace(i);
                        result.emplace_back(i);
                        matrix[current][i] = 0;
                        matrix[i][current] = 0;
                    }
                }
            }
  }
```




