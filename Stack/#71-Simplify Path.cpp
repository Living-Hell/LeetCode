// M1
// Using Stacks
// Faster than 35.46% (8ms)

class Solution
{
public:
    string simplifyPath(string path)
    {
        vector<string> dir;
        string temp;
        int n = path.size();

        if (path[n - 1] != '/')
        {
            path.push_back('/');
            n++;
        }

        stack<string> dq;
        string ans = "/";

        for (int i = 0; i < n; i++)
        {
            if (path[i] == '/')
            {
                cout << temp << " ";
                if (temp == ".")
                {
                }
                else if (temp == "..")
                {
                    if (!dq.empty())
                        dq.pop();
                }
                else
                {
                    if (temp.size())
                        dq.push(temp);
                }
                temp = "";
            }
            else
                temp.push_back(path[i]);
        }
        while (!dq.empty())
        {
            ans = "/" + dq.top() + ans;
            dq.pop();
        }
        if (ans.size() > 1)
            ans.pop_back();
        return ans;
    }
};