### Queue

`queue` 是一种**先进先出 (FIFO, First-In-First-Out)** 的容器适配器。 它就像现实生活中的排队：新来的人只能站在队尾（push），办理业务的人只能从队头离开（pop）。

使用 `queue` ，入队和出队都是 O(1)*O*(1) 的操作。

**常用方法举例：**

```cpp
#include <queue>
using namespace std;

// 1. 定义
queue<int> q;

// 2. 入队 (push)：放到队尾
q.push(10);
q.push(20); // q: Front [10, 20] Back

// 3. 访问队头 (front)：查看队伍最前面是谁
int x = q.front(); // x = 10

// 4. 出队 (pop)：移除队头
q.pop(); // q: Front [20] Back

// 5. 判空
while (!q.empty()) {
    // ...
}

// 6. 获取大小
int len = q.size();
```