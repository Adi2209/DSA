class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int maxJump = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            maxJump = max(maxJump, i + nums[i]);
            if (maxJump >= nums.size() - 1)
                return true;
            if (maxJump <= i)
                return false; // if all the previous jumps will direct to 0 ,like in the 2nd testcase
        }
        return false;
    }
};