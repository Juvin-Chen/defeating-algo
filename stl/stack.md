### Stack

`stack` 是一种**后进先出 (LIFO, Last-In-First-Out)** 的容器适配器。 它就像一个只能从顶部放书、只能从顶部取书的箱子。

**常用方法举例：**

```cpp
#include <stack>
using namespace std;

// 1. 定义
stack<int> s;

// 2. 入栈 (push)
s.push(10);
s.push(20); // 栈顶是 20

// 3. 访问栈顶 (top)
int x = s.top(); // x = 20

// 4. 出栈 (pop)
s.pop(); // 移除 20，现在栈顶是 10

// 5. 判空
if (s.empty()) { ... }

// 6. 大小
int len = s.size();
```