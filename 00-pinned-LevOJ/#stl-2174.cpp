// LevOJ P2174 动态星图

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= m; i++) {
        int a, b; // 起始边，终点边
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for (auto &vec : adj) {
        sort(vec.begin(), vec.end());
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (b <= adj[a].size()) {
            cout << adj[a][b - 1] << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}