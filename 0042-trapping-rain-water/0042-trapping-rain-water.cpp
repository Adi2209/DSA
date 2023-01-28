class Solution {
public:
    int trap(vector<int>& height) {
        int rightMax=-1,leftMax=-1,n=height.size();
        int left=0,right=n-1;
        int ans;
        
        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]>=leftMax) leftMax=height[left];
                else ans+=leftMax-height[left];
                left++;
            }
            else{
                //height[right]>height[left]
                if(height[right]>=rightMax) rightMax=height[right];
                else ans+=rightMax-height[right];
                right--;
            }
        }
        return ans;
    }
};