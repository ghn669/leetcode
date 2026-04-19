class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> dp(n);
        for(int i=0; i<n; i++) dp[i] = matrix[0][i];
        
        for(int i=1; i<n; i++){
            vector<int> temp = dp;
            for(int j=0; j<n; j++){
                if(j == 0) {
                    dp[j] = min(temp[j], temp[j+1]) + matrix[i][j];
                }
                else if(j == n-1) {
                    dp[j] = min(temp[j], temp[j-1]) + matrix[i][j];
                }
                else {
                    dp[j] = min({temp[j-1], temp[j], temp[j+1]}) + matrix[i][j];
                }
            }
        }
        
        int res = dp[0];
        for(int num : dp) res = min(res, num);
        return res;
    }
};