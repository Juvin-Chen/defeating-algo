# Priority Queue


### 这是什么？ 

 `priority_queue` 是**优先队列**，它的底层通常是一个**二叉堆 (Binary Heap)**。 与普通队列（先进先出）不同，优先队列保证**队头（top）永远是优先级最高**的元素。 默认情况下，C++ 的 `priority_queue` 是**大根堆 (Max-Heap)**，即最大的元素在 `top` 。

### 为什么要用它？ 

堆可以在 **O(logN)** 的时间内插入元素，并以 **O(1)** 的时间获取最值。 本题中，我们需要频繁地 “动态维护” 一部分数据。如果使用数组排序，插入新数据后重新排序代价太大。使用堆可以高效解决。

### 常用方法举例：

```cpp
#include <queue>
#include <vector>
using namespace std;

// 1. 定义：默认是大根堆（最大的在上面）
priority_queue<int> pq; 

// 2. 插入
pq.push(10);
pq.push(5);
pq.push(20); 

// 3. 访问堆顶
int x = pq.top(); // x = 20 (因为是大根堆)

// 4. 删除堆顶
pq.pop(); // 移除 20，剩下的最大的是 10

// 5. 进阶：如何定义小根堆（最小的在上面）？
// 需要指定容器类型(vector<int>)和比较函数(greater<int>)
priority_queue<int, vector<int>, greater<int>> min_pq;
min_pq.push(10);
min_pq.push(5);
int y = min_pq.top(); // y = 5
```