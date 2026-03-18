/**
 * @brief 二叉树遍历
 */
#include "binary_tree.h"
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

// dfs，常用queue实现
/* 层序遍历，从上到下，从左到右 */
vector<int> levelOrder(TreeNode *root) {
    // 初始化队列，加入根节点
    queue<TreeNode *> queue;
    queue.push(root);
    // 初始化一个列表，用于保存遍历序列
    vector<int> vec;
    while (!queue.empty()) {
        TreeNode *node = queue.front();
        queue.pop();              // 队列出队
        vec.push_back(node->val); // 保存节点值
        if (node->left != nullptr)
            queue.push(node->left); // 左子节点入队
        if (node->right != nullptr)
            queue.push(node->right); // 右子节点入队
    }
    return vec;
}

// bfs
// 对于三种遍历方式代码的理解：对于每个子树，都按各自的遍历方式进行递归调用，直到遍历到空节点。

// 前序遍历（根左右)
void preorderTraversal(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    cout << root->val << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// 中序遍历（左根右）
void inorderTraversal(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

// 后序遍历（左右根）
void postorderTraversal(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->val << " ";
}

// 中序遍历的非递归算法
// 递归遍历的底层是系统自动用「调用栈」保存上下文，非递归算法的核心是手动用栈模拟系统栈的行为
void inorderTraversalNonRecursive(TreeNode *root) {
    stack<TreeNode *> st;
    TreeNode *cur = root;
    while (cur != nullptr || !st.empty()) {
        if (cur != nullptr) {
            st.push(cur);    // 根指针进栈，遍历左子树
            cur = cur->left; // 往左走
        } else {
            cur = st.top();
            st.pop();
            cout << cur->val << " "; // 访问根节点
            cur = cur->right;        // 遍历右子树
        }
    }
}

// 方法2：更直观
void inorderTraversalNonRecursive(TreeNode *root) {
    stack<TreeNode *> st;
    TreeNode *cur = root;

    // 循环条件：cur非空（还有左节点要压栈） OR 栈非空（还有节点待访问）
    while (cur != nullptr || !st.empty()) {
        // 1.把当前节点的所有左子节点压入栈（模拟递归深入左子树）
        while (cur != nullptr) {
            st.push(cur);    // 压栈（暂存，先不访问）
            cur = cur->left; // 继续往左走
        }

        // 2.弹出栈顶节点（此时左子树已处理完），访问该节点（根）
        cur = st.top();
        st.pop();
        cout << cur->val << " "; // 访问根节点（中序的核心：此时左空，该访问根了）

        // 3.处理右子树（模拟递归处理右子树）
        cur = cur->right;
    }
}

// 根据遍历序列确定二叉树
/*
一、什么样的遍历组合能唯一确定一棵二叉树？
我们要根据两种遍历结果还原二叉树，其实就是在找根节点以及左子树和右子树分别有哪些节点。

1. 需要中序遍历
中序遍历的特点是：根节点左边是左子树的所有节点，右边是右子树的所有节点。
只要我们知道根节点是谁，就能从中序里把左右子树分开。

2. 还需要另一种遍历来确定根节点
前序遍历：第一个节点就是根。
后序遍历：最后一个节点就是根。
层序遍历：第一个节点也是根。

所以，能唯一确定二叉树的组合有：
前序 + 中序 / 后序 + 中序 / 层序 + 中序

3. 前序 + 后序 为什么不行？
因为只知道前序的第一个是根、后序的最后一个是根，但无法区分左右子树的分界。
例如：
前序：AB，后序：BA，可以是一棵根A、左子树B，也可以是根A、右子树B，无法区分。
所以，必须要有中序遍历来帮忙划分左右子树。
*/

/**
 * 递归函数：根据一棵二叉树的中序遍历和前序遍历，输出它的后序遍历
 * @param inorder  当前子树的中序遍历字符串
 * @param preorder 当前子树的前序遍历字符串
 *
 * 核心思想：前序定根，中序分左右；递归左右，最后输出根 —— 即得后序。
 *
 * 工作原理：
 *   1. 前序遍历的第一个字符就是当前子树的根节点。
 *   2. 在中序遍历中找到根的位置，它左边的所有字符属于左子树，右边的属于右子树。
 *   3. 根据左子树的节点个数，可以从前序遍历中分离出左子树和右子树的前序遍历。
 *   4. 递归处理左子树和右子树，最后输出根节点 —— 这就构成了后序遍历。
 */
void printPostOrder(string inorder, string preorder) {
    // 【递归出口】如果为空，直接返回
    if (inorder.empty()) {
        return;
    }

    // 1.确定当前子树的根节点，前序遍历的第一个字符就是根
    char root = preorder[0];

    // 2.在中序中找到根的位置
    int rootPos = inorder.find(root);

    // 3. 切分出左子树的中序和前序
    string leftIn = inorder.substr(0, rootPos);         // 左子树中序
    string leftPre = preorder.substr(1, leftIn.size()); // 左子树前序（从第2个字符开始取同样长度）

    // 4. 切分出右子树的中序和前序
    string rightIn = inorder.substr(rootPos + 1);         // 右子树中序
    string rightPre = preorder.substr(1 + leftIn.size()); // 右子树前序（跳过根和左子树部分）

    // 5. 递归处理左右子树（后序：左→右→根），核心是每个子树都有子树，直到递归到叶节点，也就是只有一个根节点的情况
    printPostOrder(leftIn, leftPre);   // 输出左子树的后序遍历结果
    printPostOrder(rightIn, rightPre); // 输出右子树的后序遍历结果
    cout << root;                      // 输出当前子树的根节点
}