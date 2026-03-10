### Multiset

`multiset` 与 `set` 非常相似，底层也是**红黑树**（平衡二叉搜索树）。 唯一的、也是最重要的区别在于： **`set` 会自动去重，而 `multiset` 允许存储重复的元素**。


**常用方法与陷阱（重点！）：**

```cpp
#include <set> // multiset 也包含在这里
using namespace std;

multiset<int> ms;

// 1. 插入
ms.insert(100);
ms.insert(100); // 现在集合里有 {100, 100}

// 2. 计数
int cnt = ms.count(100); // 返回 2

// 3. 删除（大坑预警！）
// 如果直接写 ms.erase(100)，它会把所有的 100 全部删掉！
// 题目要求只删一个，正确做法是先找到迭代器，再删迭代器：
auto it = ms.find(100); // 找到第一个 100 的位置
if (it != ms.end()) {
    ms.erase(it); // 只删除这个迭代器指向的那一个 100
}

// 4. 查找严格大于 x 的第一个元素 (Upper Bound)
// set/multiset 自带 upper_bound，效率 O(log N)
auto ub = ms.upper_bound(90); // 指向第一个 > 90 的元素
if (ub != ms.end()) {
    cout << *ub << endl;
}
```