### Vector


`vector` 是 C++ 标准模板库（STL）中最基本的容器，是**可以自动动态改变长度的数组**。

在数据结构中，它常被用来实现**邻接表**。

**常用方法举例：**

```cpp
#include <vector>
using namespace std;

// 1. 定义：创建一个存放整数的 vector
vector<int> v; 

// 2. 插入：在尾部添加元素
v.push_back(10); 
v.push_back(5);  // 现在 v 里面是 {10, 5}

// 3. 访问：像数组一样使用下标
int x = v[0]; // x = 10

// 4. 获取大小
int len = v.size(); // len = 2

// 5. 排序：vector 可以结合算法库排序
#include <algorithm>
sort(v.begin(), v.end()); // 现在 v 里面是 {5, 10}

// 6. 清空
v.clear();
```