class Solution {
public:
    void sortColors(vector<int>& nums) {
        int j = 0;
        int i = 0;
        int r = nums.size()-1;
        while(j <= r){
            if(nums[j] == 1){
                j++;
            }else if(nums[j]== 2){
                swap(nums[j],nums[r]);
                r--;
            }else{
                swap(nums[j],nums[i]);
                i++;
                j++;
            }
        }
    }
};