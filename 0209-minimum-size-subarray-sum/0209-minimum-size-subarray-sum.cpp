class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // sort(nums.begin(),nums.end(),greater<int>());
        int sum = 0;
        int l = 0;
        int mini = INT_MAX;
        for(int i = 0;i<nums.size();i++){
            sum += nums[i];
            
            while(target <= sum) {
                 mini = min(mini,i-l+1);
                 sum -= nums[l++];
               }
       
             
        }
        return mini == INT_MAX ? 0 : mini;
    }
};