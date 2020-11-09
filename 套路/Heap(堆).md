# 堆Heap

## 定义
堆（Heap）是一个可以被看成近似完全二叉树的数组。树上的每一个结点对应数组的一个元素。除了最底层外，该树是完全充满的，而且是从左到右填充。—— 来自：《算法导论》

堆包括最大堆和最小堆：最大堆的每一个节点（除了根结点）的值不大于其父节点；最小堆的每一个节点（除了根结点）的值不小于其父节点。

## 性质
加入堆的数据，可以直接拿到最大值或者最小值，即堆顶

## 堆常见的操作：

+ HEAPIFY 建堆：把一个乱序的数组变成堆结构的数组，时间复杂度为 O(n)。
+ HEAPPUSH：把一个数值放进已经是堆结构的数组中，并保持堆结构，时间复杂度为O(log n)。
+ HEAPPOP：从最大堆中取出最大值或从最小堆中取出最小值，并将剩余的数组保持堆结构，时间复杂度为O(log n)。
+ HEAPSORT：借由 HEAPFY 建堆和 HEAPPOP 堆数组进行排序，时间复杂度为O(nlog n)，空间复杂度为O(1)。
堆结构的一个常见应用是建立优先队列（Priority Queue），分为大顶堆和小顶堆。

## 栈的定义及常用操作

```cpp
 #include<queue>
 std::priority_queue<int, std::vector<int>> maxHeap;  // 默认是大顶堆
 std::priority_queue<int, std::vector<int>, std::less<int>> maxHeap;  // 大顶堆
 std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;  // 小顶堆
 minHeap.emplace(1); // 入堆
 minHeap.top();  // 返回堆顶的引用
 store.pop();  // 出堆
```

## 构建自定义结构排序的堆
```cpp
 #include<queue>
 struct ValueNode {
	int m_lineNum, m_columnNum, m_value;

	ValueNode(int lineNum, int columnNum, int value) : m_lineNum(lineNum), m_columnNum(columnNum), m_value(value) {
	}

	bool operator<(const ValueNode& node) const {  // 自定义比较函数
		return m_value > node.m_value;
	}
};
 std::priority_queue<ValueNode> store;
```

## 堆用于解决的问题
单调栈主要解决以下问题：
+ 求前k大个元素
+ 求前k小个元素
+ 求第k大个元素
+ 求第k小个元素
