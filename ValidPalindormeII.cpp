class Solution
{
    bool isPalindrome(string s, int left, int right)
    {

        while (left < right)
        {
            if (s[left] == s[right])
            {
                left++;
                right--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }

public:
    bool validPalindrome(string s)
    {
        int n = s.size();

        int l = 0, r = n - 1;
        int cnt = 0;
        while (l < r)
        {
            if (s[l] == s[r])
            {
                l++;
                r--;
            }
            else
            {
                return isPalindrome(s, l + 1, r) || isPalindrome(s, l, r - 1);
            }
        }
        return true;
    }
};