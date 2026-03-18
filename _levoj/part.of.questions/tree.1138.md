# P1138 American Heritage

#### 题目描述

> Farmer John takes the heritage of his cows very seriously. He is not, however, a truly fine bookkeeper. He keeps his cow genealogies as binary trees and, instead of writing them in graphic form, he records them in the more linear `tree in-order" and `tree pre-order" notations.

> Your job is to create the `tree post-order" notation of a cow"s heritage after being given the in-order and pre-order notations. Each cow name is encoded as a unique letter. (You may already know that you can frequently reconstruct a tree from any two of the ordered traversals.) Obviously, the trees will have no more than 26 nodes.

> Here is a graphical representation of the tree used in the sample input and output:

```
              C
            /   \
           /     \
          B       G
         / \     /
        A   D   H
           / \
          E   F

The in-order traversal of this tree prints the left sub-tree, the root, and the right sub-tree.

The pre-order traversal of this tree prints the root, the left sub-tree, and the right sub-tree.

The post-order traversal of this tree print the left sub-tree, the right sub-tree, and the root.

----------------------------------------------------------------------------------------------------------------------------
```

#### 题目大意：

> 给出一棵二叉树的中序遍历 (inorder) 和前序遍历 (preorder)，求它的后序遍历 (postorder)。

#### 输入描述

> Line 1:

> The in-order representation of a tree.

> Line 2:

> The pre-o rder representation of that same tree.

> Only uppercase letter A-Z will appear in the input. You will get at least 1 and at most 26 nodes in the tree.

#### 输出描述

> A single line with the post-order representation of the tree.

#### 样例输入

```
ABEDFCHG CBADEFGH 
```

#### 样例输出

```
AEFDBHGC
```