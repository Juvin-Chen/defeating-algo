# List

### 这是什么？ 
`list` 是 **双向链表 (Doubly Linked List)**。 与 `vector` （连续内存数组）不同， `list` 的元素分散在内存中，通过指针相连。

### 为什么要用它？

- **优势**：在链表的**任意位置插入**或**删除**元素，只需要修改指针，时间复杂度为 **O(1)**（前提是你已经有了指向该位置的迭代器）。
- **劣势**：不支持随机访问。你不能像数组那样用 `L[5]` 直接访问第 5 个元素，必须从头遍历。

假如需要左右移动光标（迭代器 `++` 或 `--` ），以及在光标处插入删除。这正是链表的强项。

### 常用方法举例：

```cpp
#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
    // 1.初始化
    list<char> L;
    // 初始化时直接赋初始值
    list<char> L1 = {'a', 'b', 'c'}; // C++11+
    // 用迭代器范围初始化，也可以换成别的容器的迭代器√
    list<char> L2(L1.begin(), L1.end()); // 用迭代器范围初始化

    // 2.元素添加
    // 尾部添加（push_back）
    L.push_back('d'); // L → [a,b,c,d]
    // 头部添加（push_front）
    L.push_front('0'); 

    // 3. 插入：在 it 指向的元素 *之前* 插入 'a'
    // 插入后，it 仍然指向原来的那个元素（或者 end），
    // 所以光标实际上是在新插入元素的 "右边"。
    auto it = L.begin(); 
    it = L.insert(it, 'a'); 
    
    // 4. 删除：删除 it 指向的元素
    // erase 返回下一个有效元素的迭代器
    // 注意：如果题目是“删除光标左侧”，所以要先 it-- 再 erase
    it = L.erase(it);

    // 5. 移动
    it++;
    it--;

    // 6.清空所有元素（clear）：list变为空，迭代器失效
    L.clear(); // L为空
}
```