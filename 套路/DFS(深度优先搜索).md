# DFS(深度优先搜索)

## 定义
深度优先搜索算法（英语：Depth-First-Search，DFS）是一种用于遍历或搜索树或图的算法。这个算法会尽可能深的搜索树的分支。当节点v的所在边都己被探寻过，搜索将回溯到发现节点v的那条边的起始节点。这一过程一直进行到已发现从源节点可达的所有节点为止。如果还存在未被发现的节点，则选择其中一个作为源节点并重复以上过程，整个进程反复进行直到所有节点都被访问为止。

## 树状数据遍历顺序
从根节点出发，沿着左子树方向进行纵向遍历，直到找到叶子节点为止。然后回溯到前一个节点，进行右子树节点的遍历，直到遍历完所有可达节点为止。

## 实现
1.递归实现（常用）
2.借助栈，通过循环实现

数据结构定义如下

```cpp
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

```
以先序遍历为例
1.递归实现（常用）
```cpp
  void DFS(TreeNode* node, vector<TreeNode*>* result) {
      if (node == nullptr) {
        return;
      }
      result->emplace_back(node);
      DFS(node->left);
      DFS(node->right);
  }

```

2.借助栈，通过循环实现
```cpp
void DFS(TreeNode* root, vector<TreeNode*>* result) {
    if (nullptr == root) {
        return;
    }
    stack<TreeNode*> s;
    s.push(root);
    while (!s.empty()) {
        root = s.top();
        result->emplace_back(root);
        s.pop();
        if (root->right != nullptr) {
            s.push(root->right);
        }
        if (root->left != nullptr) {
            s.push(root->left);
        }

    }
} 
```
