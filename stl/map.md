### STL 容器小贴士：Map

`map` 是一个**关联容器**，它存储的是**键值对 (Key-Value Pair)**。 你可以把它想象成一个超级数组，这个数组的下标（Key）不一定是整数，可以是字符串、结构体甚至是其他容器。 例如： `map<string, int> backpack` 就可以理解为 `backpack["fire"] = 10` 。

**为什么要用它？** 

在 C/C++ 中，普通的数组 `a[100]` 只能用整数下标访问。如果我们要统计 “单词出现的次数”，传统的做法是写一个哈希函数或者维护两个平行数组。 `map` 帮我们封装好了这一切。底层通常使用**红黑树**实现，因此查找和插入的时间复杂度为 O(Llog⁡N)*O*(*L*log*N*)（L*L* 为字符串长度，N*N* 为元素个数）。

**常用方法举例：**

```cpp
#include <map>
#include <string>
using namespace std;

// 1. 定义：Key是string，Value是int
map<string, int> mp;

// 2. 插入与修改：像数组一样直接使用 []
mp["apple"] = 5;
mp["banana"] = 10;
mp["apple"] += 3; // 现在 apple 是 8

// 3. 访问
cout << mp["apple"] << endl; 

// 4. 注意：[] 运算符的副作用
// 如果访问一个不存在的 Key，map 会自动创建它并赋值为 0 (默认构造值)
int x = mp["orange"]; // "orange" 被创建了，x = 0

// 5. 查找（如果不希望自动创建）
if (mp.find("orange") != mp.end()) {
    // 存在
} else {
    // 不存在
}

// 6. 遍历
for (auto& pair : mp) {
    cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
}
```