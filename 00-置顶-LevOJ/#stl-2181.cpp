// LevOJ P2181 信号过滤器

#include <iostream>
#include <queue>

using namespace std;

// 大根堆
priority_queue<int> pq;

int main() {
    int n, k;
    cin >> n >> k;
    int op, x;
    while (n--) {
        cin >> op >> x;
        if (op == 1) {
            if (pq.size() < k) {
                pq.push(x);
            } else {
                // 如果当前元素比堆顶元素大
                if (pq.top() > x) {
                    pq.pop();
                    pq.push(x);
                }
            }
        } else if (op == 2) {
            if (pq.size() < k) {
                cout << -1 << endl;
            } else {
                cout << pq.top() << endl;
            }
        }
    }
    return 0;
}
