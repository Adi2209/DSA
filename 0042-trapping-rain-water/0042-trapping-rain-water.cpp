class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int left=0, right=n-1;
        int ans=0,leftMax=-1,rightMax=-1;
        
        while(left<right){
            // this will check automatically the available right building to store water
            if(height[left]<=height[right]){
                //if it is the leftMax then it can't store water
                if(height[left]>leftMax) leftMax=height[left];
                else ans+=leftMax-height[left];
                left++;
            }
            else{
                //height[left]>height[right]
                if(height[right]>rightMax) rightMax=height[right];
                else ans+=rightMax-height[right];
                right--;
            }
        }
        return ans;
    }
};