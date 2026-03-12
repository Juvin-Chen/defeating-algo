// P1309 最长单调递增子序列

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int LIS(const string &s) {
    // d[i] 表示长度为 i+1 的递增子序列的最小末尾字符
    vector<char> d;
    for (auto c : s) {
        // 二分查找第一个大于等于 c 的位置
        auto it = lower_bound(d.begin(), d.end(), c);
        if (it == d.end()) {
            // c 比所有末尾都大，可以扩展最长长度
            d.push_back(c);
        } else {
            *it = c;
        }
    }
    return d.size();
}

int main() {
    int n;
    cin >> n;
    vector<int> res(n, 0);
    string str;
    for (int i = 0; i < n; i++) {
        cin >> str;
        res[i] = LIS(str);
    }
    for (auto &i : res) {
        cout << i << endl;
    }
    return 0;
}