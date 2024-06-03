class Solution
{
public:
    int appendCharacters(string str, string str2)
    {
        int itr = 0;
        int j = 0;
        while (itr < str.size() && j < str2.size())
        {
            if (str[itr] == str2[j])
            {
                itr++;
                j++;
                continue;
            }
            else itr++;
        }

        if (j == str2.size()) return 0;
        return str2.size() - j;
    }
};