#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 路径长度，积水个数，一次最远可以跨的距离
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> is_water(n + 1, 0);
    int number;
    while (m--) {
        cin >> number;
        is_water[number] = 1;
    }

    // dp[i] 表示走到 i 位置时最少的水坑数量
    vector<int> dp(n + 1, 0);
    dp[1] = is_water[1] == 0 ? 0 : 1;
    for (int i = 1; i <= n; i++) {
        int min = dp[i - 1] + is_water[i];
        for (int j = ; j < i; j++) {
            if ()
        }
    }
    cout << dp[n];
    return 0;
}