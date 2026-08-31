/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        

        vector<int> res;
        while(head != nullptr){
            res.push_back(head->val);
            head = head->next;
        }
        if(res.size() <= 2){
            return {-1,-1};
        }
        vector<int> ctc;
         int prev = -1;
         int curr = -1;
         int mini = INT_MAX;
        for(int i = 1;i<res.size()-1;i++){
          if ((res[i + 1] > res[i] && res[i - 1] > res[i]) || (res[i + 1] < res[i] && res[i - 1] < res[i])) { ctc.push_back(i); curr = i; // Only calculate distance when we find // an actual critical point 
          if (prev != -1) { mini = min(mini, curr - prev); } prev = curr; }

        }
        if(ctc.size() < 2) return {-1,-1};
         int maxi = ctc.back() - ctc.front();
     
       
        return {mini,maxi};
    }
};