/*
0 5 2 3
4 5 6 7
8 9 10 11
这样的一个地图当中，每经过一个点累加的宝藏值只能来自其 左 / 上，左 / 上就是动态规划的上一状态。
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> treasure(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> treasure[i][j];
        }
    }

    // 定义dp[i][j]为走到(i,j)时可以收取宝藏的最大值
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0)
                continue;
            if (i == 0) {
                dp[i][j] = dp[i][j - 1] + treasure[i][j];
            } else if (j == 0) {
                dp[i][j] = dp[i - 1][j] + treasure[i][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + treasure[i][j];
            }
        }
    }
    cout << dp[m - 1][n - 1];
    return 0;
}