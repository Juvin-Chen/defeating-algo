/**
 * @brief 二叉树节点结构体
 * 每个节点包含一个整数值 val，以及指向左子节点和右子节点的指针。
 */

/* 链式存储：二叉树节点结构体 */
struct TreeNode {
    int val;         // 节点值
    TreeNode *left;  // 左子节点指针
    TreeNode *right; // 右子节点指针
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/* 顺序存储：二叉树节点结构体，比较适用于完全二叉树*/
struct ArrayTreeNode {
    int val;   // 节点值
    int left;  // 左子节点索引
    int right; // 右子节点索引
};
ArrayTreeNode arrayTree[100];
