class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxi(n,-1);
        vector<int> mini(n,-1);
        
         int maxu = nums[0];
          int minu = nums[n-1];
        for(int i = 0;i<nums.size();i++){
          if(nums[i] > maxu){
            maxu = nums[i];
          }  
          maxi[i] = maxu;
        }
        for(int i = n-1;i >= 0;i--){
          if(nums[i] < minu){
            minu = nums[i];
          }  
          mini[i] = minu;
        }

        for(int i = 0;i<n;i++){
            if(maxi[i]-mini[i] <= k){
                return i;
            }
        }
        return -1;
    }
};