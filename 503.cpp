class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        vector<int> res(n, -1);
        if (n == 0)
            return res;
        s.push(0);
        for (int i = 0; i < 2 * n - 1; i++) {
            while (!s.empty() && nums[i % n] > nums[s.top()]) {
                res[s.top()] = nums[i % n];
                s.pop();
            }
            s.push(i % n);
        }
        return res;
    }
};