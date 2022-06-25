class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        //we will use the indexes to mark the traversed elements negative
        //as soon as the value will come negative that is only possible when their will be a duplicate number
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            int a = abs(nums[i]);
            if (nums[a - 1] < 0)
                return a;
            else
                nums[a - 1] *= -1;
        }
        return -1;
    }
};