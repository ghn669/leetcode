//最长有效括号（dp）
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int len = s.size();
        for(int i=0;i<len;i++)
        {
            if(s[i]=='('||s[i]=='{'||s[i]=='[')
            {
                st.push(s[i]);
                continue;
            }
            else {
                if(st.empty()) return false;
                char top = st.top();
                if( (s[i] == ')' && top == '(') ||
                    (s[i] == '}' && top == '{') ||
                    (s[i] == ']' && top == '[') ) {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};