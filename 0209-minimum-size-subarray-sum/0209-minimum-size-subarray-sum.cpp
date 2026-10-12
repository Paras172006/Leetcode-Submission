class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int maxi = INT_MAX;
        int sum = 0;
        for(int r = 0;r<nums.size();r++){
            sum += nums[r];
            while(sum >= target){
                maxi = min(maxi,r-l+1);
                sum -= nums[l];
                l++;
            }
            
        }
        return maxi == INT_MAX ? 0 : maxi;
    }
};