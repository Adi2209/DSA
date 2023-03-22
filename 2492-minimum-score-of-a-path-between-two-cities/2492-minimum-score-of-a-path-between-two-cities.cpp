class Solution{
private:
    int root(int ans, int *arr){
        while (ans != arr[ans]){
            arr[ans] = arr[arr[ans]];
            ans = arr[ans];
        }
        return ans;
    }

public:
    int minScore(int n, vector<vector<int>> &a){
        int mini = INT_MAX;
        int fr[n];
        int arr[n];

        for (int i = 0; i < n; i++){
            fr[i] = i;
            arr[i] = INT_MAX;
        }
        for (int i = 0; i < a.size(); i++){
            int temp1 = a[i][0] - 1;
            int temp2 = a[i][1] - 1;
            int temp3 = a[i][2];
            arr[temp1] = min(arr[temp1], temp3);
            arr[temp2] = min(arr[temp2], temp3);

            fr[root(temp1, fr)] = root(temp2, fr);
        }
        for (int i = 0; i < n; i++)
            if (root(i, fr) == root(0, fr))
                mini = min(arr[i], mini);

        return mini;
    }
};