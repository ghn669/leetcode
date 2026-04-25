class Solution {
public:
    stack<int> s;
    int calPoints(vector<string>& operations) {
        int n = operations.size();
        for(int i=0;i<n;i++)
        {
            if(operations[i]=="+")
            {
                int res1 = s.top();
                s.pop();
                int res2 = s.top();
                s.push(res1);
                s.push(res1+res2);
            }
            else if(operations[i]=="D")
            {
                int res1 = s.top();
                s.push(res1*2);
            }
            else if(operations[i]=="C")
            {
                s.pop();
            }
            else
            {
                s.push(stoi(operations[i]));
            }
        }
        int sum = 0;
        while(!s.empty())
        {
            sum+=s.top();
            s.pop();
        }
        return sum;
    }
};