// LevOJ P2177 记忆碎片

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    // 提速
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    string str;
    int sign, num;

    // 这题数值可能超出int，要开long long
    map<string, long long> m;
    while (q--) {
        cin >> sign;
        switch (sign) {
        case 1: {
            cin >> str >> num;
            m[str] += num;
            break;
        }
        case 2: {
            cin >> str >> num;
            if (m.find(str) == m.end() || m[str] < num) { // 不存在 / 数量不足
                cout << -1 << endl;
                continue;
            } else {
                m[str] -= num;
                cout << m[str] << endl;
            }
            break;
        }
        case 3: {
            cin >> str;
            if (m.find(str) != m.end()) {
                cout << m[str] << endl;
            } else {
                cout << 0 << endl;
            }
            break;
        }
        }
    }
    return 0;
}