class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        stack<char> st;
        int cnt = 0;
        int i = 0;
        while(i<n){
            if(s[i] == '('){
                st.push('(');
                i++;
                
            }
            else{
               
               if(st.empty()){
                while(s[i] == ')'){
                     cnt++;
                     i++;
                }
               }else{
                st.pop();
                i++;
               }
            }
            // i++;
        }
        while(!st.empty()){
            cnt++;
            st.pop();
        }
        return abs(cnt);
    }
};