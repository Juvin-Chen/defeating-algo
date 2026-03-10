// 单调栈算法

// 这里以一个很典型的应用场景举例:
// 在一维数组中，快速找到每个元素的下一个 更大 / 更小的元素，，这类问题用暴力法是 O(n2)，用单调栈能优化到 O(n)
// 问题：给数组 [2,1,2,4,3]，找每个元素右侧第一个比它大的元素
// 结果：[4,2,4,-1,-1]

#include <stack>
#include <vector>

using namespace std;

vector<int> nextGreaterElement(vector<int> &nums) {
    int n = nums.size();
    vector<int> res(n, -1); // 默认-1（无更大元素）
    stack<int> st;
    for (int i = 0; i < n; i++) {
        // 当前元素 > 栈顶元素 → 找到栈顶的下一个更大元素
        while (!st.empty() && nums[i] > nums[st.top()]) {
            int idx = st.top();
            st.pop();
            res[idx] = nums[i];
        }
        st.push(i);
    }
    return res;
}