// 当程序中需要频繁进行输入
// 这个过程中，我们需要先定义类型，再用标准库 cin>> X，于是可以想到使用模板函数来减少重复代码

#include <iostream>
#include <string>

using namespace std;

// 这是一个函数模板，可以读取任意类型的输入（只要 cin >> 支持）
template <typename T> T read() {
    T x;
    cin >> x;
    return x;
}

int main() {
    // 1. 读取整数（int）
    int a = read<int>();
    cout << "读取的int值：" << a << endl;

    // 2. 读取长整数（long long）
    long long b = read<long long>();
    cout << "读取的long long值：" << b << endl;

    // 3. 读取字符串（string）
    string c = read<string>();
    cout << "读取的string值：" << c << endl;

    return 0;
}