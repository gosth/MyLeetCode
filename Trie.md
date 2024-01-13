# 前缀树/字典树Trie

## Trie树的简介
Trie树，又称字典树，单词查找树或者前缀树，是一种用于快速检索的多叉树结构。如英文字母的字典树是一个26叉树，数字的字典树是一个10叉树。它的核心思想是空间换时间，空间消耗大但是插入和查询有着很优秀的时间复杂度。

## Trie树的定义
Trie树的键不是直接保存在节点中，而是由节点在树中的位置决定。一个节点的所有子孙都有相同的前缀（prefix）,从根节点到当前结点的路径上的所有字母组成当前位置的字符串。

下图是一个 Trie 树的例子。每个红色节点代表一个字符串的结束。例如，从根节点（最顶部）到第一个红色节点，路径上的字符连接起来为“abc”。
![Alt text](https://pic2.zhimg.com/80/v2-9d07fbd164fc0d737aabe428b4484bd1_1440w.webp)

## Trie树的性质：
+ 根节点不包含字符，除根节点外的每个节点都只包含一个字符。
+ 从根节点到某一节点，路径上经过的字符连接起来，为该节点对应的字符串。
+ 每个节点的所有子节点包含的字符都不相同。
+ Trie树的查找效率高，查找时间与树的深度（即字符串长度）成正比，与字典的大小无关。


## Trie树常见的操作：
+ 插入（insert）：插入一个字符串到Trie树中。从根节点开始，按照字符串的每个字符进行路径搜索，如果路径存在则继续搜索下一个字符，如果路径不存在则创建一个新的节点。当插入完整个字符串后，标记最后一个字符代表的节点为“结束节点”，表示一个完成的字符串结束于这个节点。
+ 搜索（search）：搜索一个指定的字符串是否在Trie树中。从根节点开始，依次根据字符串的每个字符进行路径搜索，如果每个字符的路径都存在（即每次搜索到下一个节点），且最后一个字符对应的节点是“结束节点”，则代表这个字符串存在于Trie树中。反之，若在搜索过程中路径中断或者最后一个字符对应的节点不是结束节点，则代表这个字符串不存在于Trie树中。
+ 前缀查询（startsWith）：前缀查询是指查询Trie树中是否存在某个前缀开头的字符串。从根节点开始，按照前缀的每个字符搜索，如果每个字符的路径都存在（即每次都能搜索到下一个节点），则说明存在这样一个前缀。反之，如果在搜索过程中路径中断，则说明不存在这样一个前缀。

## Trie树的定义及常用操作
```cpp
    class TrieNode {
    public:
        // 存储子节点结构。key为字符，value为子节点指针
        std::map<char, TrieNode*> children;
        // 标识字符串结尾
        bool endOfWord;
    
        TrieNode(): endOfWord(false) {}
    };
    
    class Trie {
    public:
        Trie() : root(new TrieNode()) {}
    
        // 插入一个单词至Trie
        void insert(std::string word) {
            TrieNode* node = root;
            for(char c : word) {
                if(node->children.count(c) == 0) {
                    node->children[c] = new TrieNode();
                }
                node = node->children[c];
            }
            node->endOfWord = true;
        }
    
        // 在Trie中查找一个单词
        bool search(std::string word) {
            TrieNode* node = root;
            for(char c : word) {
                if(node->children.count(c) == 0) {
                    return false;
                }
                node = node->children[c];
            }
            return node->endOfWord;
        }
    
        // 检查是否有任何单词以该前缀开始
        bool startsWith(std::string prefix) {
            TrieNode* node = root;
            for(char c : prefix) {
                if(node->children.count(c) == 0) {
                    return false;
                }
                node = node->children[c];
            }
            return true;
        }
    
    private:
        TrieNode* root;
    };
```

## Trie树用于解决什么问题
+ 字符串查找：Trie树是一种非常有效的字符串查找工具，可以在字典中进行全文检索。如在搜索引擎中的关键词提示功能，它就是通过Trie树进行实现的。

+ 字符串匹配：通过Trie树，我们可以很容易地实现一个字符串匹配器，比如，给出一个文本和一个模式串列表，查找出所有的模式串在文本中出现的位置。

+ 词频统计：在大数据处理中，经常需要对海量文本中的词频进行统计。使用Trie树，我们可以快速而准确地完成这项任务。

+ 排序和去重：Trie树的中序遍历结果是有序的，所以我们可以通过对Trie树进行中序遍历，得到一个排序后的字符串。同时，Trie 树也可以用于字符串的去重操作。

+ 模糊搜索和拼写检查：Trie树还可以用于模糊搜索和拼写检查，在单词拼写稍有差错但是接近正确的情况下，能找出最可能的正确结果。

+ IP路由查找：在网络设备如路由器中，会用到一种根据前缀确定路由的前缀查找问题，Trie树对这类问题有非常高效的解决方案。