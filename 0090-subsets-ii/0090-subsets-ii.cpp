class Solution {
public:
  vector<vector<int>> ans;

    void sum(vector<int>& nums, vector<int>& nums2, int i) {
        if (i == nums.size()) {
            ans.push_back(nums2);
            return;   // ⭐ important
        }

        // Include nums[i]
        nums2.push_back(nums[i]);
        sum(nums, nums2, i + 1);

        // Backtrack
        nums2.pop_back();
        int idx = i+1;
        while(idx < nums.size() && nums[idx] == nums[idx-1]){
            idx++;
        }
        // Don't include nums[i]
        sum(nums, nums2, idx);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         vector<int> nums2;
         sort(nums.begin(),nums.end());
        sum(nums, nums2, 0);
        return ans;
    }
};