class Solution {
public:
    vector<vector<int>> ans;
    void sum(vector<int>& nums,vector<int>& nums2,int i){
        if(i == nums.size()){
            ans.push_back(nums2);
            return ;
        }
        
        nums2.push_back(nums[i]);
        sum(nums,nums2,i+1);
        nums2.pop_back();
        sum(nums,nums2,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> nums2;
        sum(nums,nums2,0);
        return ans;
    }
};