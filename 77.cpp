//组合
class Solution {
public:
    vector<vector<int>> res;  // 放全局/类内，才能访问
    vector<int> path;          // 存放当前组合

    void dfs(int start, int k, int n) {
        // 终止条件：选够 k 个数
        if (path.size() == k) {
            res.push_back(path);
            return;
        }

        // 遍历：从 start 开始，防止重复
        for (int i = start; i <= n; i++) {
            path.push_back(i);    // 选
            dfs(i + 1, k, n);    // 递归
            path.pop_back();     // 回溯（撤销选择）
        }
    }

    vector<vector<int>> combine(int n, int k) {
        dfs(1, k, n);   // 从 1 开始选
        return res;
    }
};