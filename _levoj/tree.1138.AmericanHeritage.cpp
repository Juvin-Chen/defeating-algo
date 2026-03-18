#include <iostream>
#include <string>

using namespace std;

void printpostorder(string in, string pre) {
    if (in.empty()) {
        return;
    }

    char root = pre[0];
    int index_root = in.find(root);

    string left_in = in.substr(0, index_root);
    string left_pre = pre.substr(1, left_in.size());

    string right_in = in.substr(index_root + 1);
    string right_pre = pre.substr(1 + left_in.size());

    printpostorder(left_in, left_pre);
    printpostorder(right_in, right_pre);
    cout << root;
}

int main() {
    string inorder, preorder;
    cin >> inorder >> preorder;
    printpostorder(inorder, preorder);
    return 0;
}
