class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = 0;
        
        for(int i = 0;i<k;i++){
           ans += nums[i];
        }
        double l = 0;
       double maxi = ans;
        for(int i = k;i<nums.size();i++){
            ans = ans+nums[i]-nums[l++];
           maxi = max(maxi,ans);
        }
        return double(maxi/k);
    }
};