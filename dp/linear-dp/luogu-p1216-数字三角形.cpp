#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// 最基础的解法，也是最优的O（n^2）
int main() {
    int r;
    cin >> r;

    vector<vector<int>> v(r, vector<int>(r, 0));

    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j <= i; j++) {
            cin >> v[i][j];
            // 第一行跳过
            if (i == 0)
                continue;
            if (j == 0) {
                v[i][j] += v[i - 1][j];
            } else if (j == i) {
                v[i][j] += v[i - 1][j - 1];
            } else {
                v[i][j] += max(v[i - 1][j - 1], v[i - 1][j]);
            }
        }
        // 遍历最后一行，找最大值
        if (i == r - 1) {
            int max = v[i][0];
            for (int k = 1; k <= i; k++) {
                if (v[i][k] > max)
                    max = v[i][k];
            }
            cout << max;
        }
    }
    return 0;
}

// 优化解法
// 从“自顶向下”改为“自底向上”（消灭边界判断）
int demo1() {
    // 站在倒数第二行只需要考虑自己下方的数和右下方的数哪一个更大，与更大的数相加
    int r;
    cin >> r;

    vector<vector<int>> v(r, vector<int>(r, 0));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> v[i][j];
        }
    }

    // 从倒数第二行开始向上遍历
    for (int k = r - 2; k >= 0; k--) {
        for (int i = 0; i <= k; i++) {
            // 最大值为当前值+下方两个数的最大值
            v[k][i] += max(v[k + 1][i], v[k + 1][i + 1]);
        }
    }
    cout << v[0][0];

    return 0;
}