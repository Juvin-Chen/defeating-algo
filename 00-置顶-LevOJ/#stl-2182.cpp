// LevOJ P2182 虚空石板

#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;
    if (str == "EMPTY") {
        str = "";
    }
    list<char> L(str.begin(), str.end());

    // 指令Q次数
    int q_num;
    cin >> q_num;
    char op, x;
    // 初始迭代器的位置，也就是初始光标的位置
    auto it = L.begin();
    while (q_num--) {
        cin >> op;
        switch (op) {
        case '>': {
            if (it != L.end()) {
                it++;
            }
            break;
        }
        case '<': {
            if (it != L.begin()) {
                it--;
            }
            break;
        }
        case 'I': {
            cin >> x;
            L.insert(it, x);
            break;
        }
        case 'D': {
            if (it != L.begin()) {
                it--;
                // erase 返回下一个有效元素的迭代器
                it = L.erase(it);
            }
        }
        }
    }
    if (L.empty()) {
        cout << "";
    } else {
        for (char ch : L) {
            cout << ch;
        }
    }
    return 0;
}