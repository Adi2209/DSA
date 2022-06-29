class Solution
{
public:
    string simplifyPath(string path)
    {

        stack<string> st;
        for (int i = 0; i < path.size(); i++)
        {

            if (path[i] == '/')
                continue;
            string s = "";
            while (i < path.size() && path[i] != '/')
            {
                s += path[i];
                i++;
            }
            if (s == ".")
            {
                continue;
            }
            if (s == "..")
            {
                if (!st.empty())
                {
                    st.pop();
                }
            }
            else
            {
                st.push(s);
            }
        }

        string ans = "";
        while (!st.empty())
        {
            ans = "/" + st.top() + ans;
            st.pop();
        }
        if (ans.size() == 0)
            return "/";

        return ans;
    }
};