class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> fr(26,0);
        int l = 0;
        int cnt = 0;
        int maxi = 0;
        for(int i = 0;i<s.size();i++){
          fr[s[i]-'A']++;
          maxi = max(maxi,fr[s[i] - 'A']);

          while((i-l+1) - maxi > k){
             fr[s[l]-'A']--;
             l++;
          }
          cnt = max(cnt,i-l+1);
        }
        return cnt;
    }
};