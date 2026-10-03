class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int z = 0;
        int l = 0;
        int maxi = INT_MIN;
        for(int i = 0;i<nums.size();i++){
          if(nums[i] == 0) z++;
          while(z>k){
            if(nums[l] == 0) z--;
            l++;
          }
          maxi = max(maxi,i-l+1);
        }
        
        return maxi;
    }
};