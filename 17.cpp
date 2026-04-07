//手机电话号码字母组合
class Solution {
public:
    vector<string> res;
    string s;
    vector<string> board={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void dfs(int pos,string digits)
    {
        if(pos==digits.size())
        {
            res.push_back(s);
            return;
        }
        int num = digits[pos]-'0';
        for(int i=0;i<board[num].size();i++)
        {
            s.push_back(board[num][i]);
            dfs(pos+1,digits);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return res;
        dfs(0,digits);
        return res;
    }
};