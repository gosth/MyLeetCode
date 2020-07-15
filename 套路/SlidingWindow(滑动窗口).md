# SlidingWindow(滑动窗口)

## 解决的问题
主要分为：
1.可变长度窗口：常用来寻找某个字符串中符合条件的子串。（如：给定一个字符串s，找出至多包含k个不同字符的最长子串T）

2.固定长度窗口：常用来寻找某个数组中符合条件的子数组。（如：给定一个数组，找出个数为k个的连续子数组其和最小）  

第一种情况的题目更常见。

## 实现
1.可变长度窗口

s为原始串，t为模式串。
```cpp
void slidingWindow(std::string s, std::string t) {
    std::unordered_map<char, int> need, window;
    for (char c : t) need[c]++;
    
    int left = 0, right = 0;
    int valid = 0; 
    while (right < s.size()) {
        // c 是将移入窗口的字符
        char c = s[right];
        // 右移窗口
        right++;
        // 进行窗口内数据的一系列更新
        ...

        /*** debug 输出的位置 ***/
        printf("window: [%d, %d)\n", left, right);
        /********************/
        
        // 判断左侧窗口是否要收缩
        while (window needs shrink) {
            // d 是将移出窗口的字符
            char d = s[left];
            // 左移窗口
            left++;
            // 进行窗口内数据的一系列更新
            ...
        }
    }
}
```  

2.固定长度窗口

```cpp
void slidingWindow(std::string s, int k) {
    if (s.size() < k) {
        return;
    }
    int left = 0;
    for (int right = k - 1; right < s.size(); ++right) {
        // 进行窗口内数据的一系列更新
        ...

        /*** debug 输出的位置 ***/
        printf("window: [%d, %d)\n", left, right);
        ++left;

    }
}
```
