class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {

        int n = nums.size();
        int cnt = 0, ele = 0;
        for (int i = 0; i < n; i++)
        {
            if (cnt == 0)
            {
                ele = nums[i];
            }
            if (nums[i] == ele)
            {
                cnt++;
            }
            else
                cnt--;
        }
        return ele;
    }
};