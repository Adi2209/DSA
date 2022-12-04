class Solution
{
public:
    int minimumAverageDifference(vector<int> &nums)
    {   int n=nums.size();
        if (n == 1)
            return 0;
        
        int idx = INT_MAX;

        long s1 = 0;
        long s2 = 0;

        for (int i = 0; i < n; i++)
            s1 += nums[i];
        // sum of all
        s1 = s1 - nums[0];
        s2 = nums[0];

        int mini = INT_MAX;
        vector<int> temp;
        int i = 0;
        while (i < n)
        {
            long f = s2 / (i + 1);
            long s = 0;
            int flag = 0;
            if (i == n - 1)
            {
                flag = 1;
                s = 0;
            }
            else
                s = s1 / (n - i - 1);
            //f is first 
            //second is s
            long average = abs(f - s);
            temp.push_back(average);
            if (average < mini)
            {
                mini = average;
                idx = i;
            }
            i++;

            if (flag == 1)
                break;
            else
            {
                s1 = s1 - nums[i];
                s2 = s2 + nums[i];
            }
        }
        return idx;
    }
};