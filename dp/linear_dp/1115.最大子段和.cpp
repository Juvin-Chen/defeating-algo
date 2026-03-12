/*
定义 dp[i] 表示以第 i 个元素结尾的连续子数组的最大和。
对于 dp[i]，有两种情况：
1.把 a[i] 接到前面的子数组后面：dp[i] = dp[i-1] + a[i]
2.重新开始一个新子数组（只包含 a[i] 自己）：dp[i] = a[i]
我们要取这两种情况的较大者，所以：
dp[i] = max(dp[i-1] + a[i], a[i])

空间优化
注意到 dp[i] 只依赖于 dp[i-1]，所以我们不需要保存整个 dp 数组，只需用一个变量 cur 记录当前的 dp[i]，再用一个变量 ans
记录全局最大值。
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }
    if (n == 1) {
        cout << nums[1];
        return 0;
    }

    int cur = nums[1];
    // 注意：ans不能初始化为0，ans有可能为负数
    int ans = cur;
    // dp start
    for (int i = 2; i <= n; i++) {
        cur = cur + nums[i] > nums[i] ? cur + nums[i] : nums[i];
        if (cur > ans)
            ans = cur;
    }
    cout << ans;
    return 0;
}