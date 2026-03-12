#include <iostream>
#include <vector>

using namespace std;

// 递归的方式
int f(int m, int n) {
    // 注意：无苹果的方式为盘子全空，也算一种方法，不是return 0
    if (m == 0)
        return 1;
    if (n == 0)
        return 0;
    if (m == 1 || n == 1) {
        return 1;
    }
    // 苹果数量小于盘子数量，最多只能有m个盘子有用
    if (m < n) {
        return f(m, m);
    } else {
        // 苹果数量大于盘子数量，则分为两种情况：
        // 1.至少一个盘子是空的
        // 2.每个盘子上面至少放1个苹果
        return f(m, n - 1) + f(m - n, n);
    }
}

// dp 优化版
int f_dp(int m, int n) {
    // 定义dp[i][j]为i个苹果放在j个盘子中的情况
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int j = 0; j <= n; j++) {
        dp[0][j] = 1;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (i < j) {
                dp[i][j] = dp[i][i];
            } else {
                dp[i][j] = dp[i - j][j] + dp[i][j - 1];
            }
        }
    }
    return dp[m][n];
}

int main() {
    // 苹果数量和盘子数量
    int m, n;
    cin >> m >> n;
    cout << f(m, n) << endl;
    // cout << f_dp(m, n) << endl;
    return 0;
}