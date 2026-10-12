
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(128, 0);

        for (char c : t) {
            need[c]++;
        }

        int l = 0;
        int missing = t.size();
        int start = 0;
        int minLen = INT_MAX;

        for (int r = 0; r < s.size(); r++) {

            // Current character ki need check karo
            if (need[s[r]] > 0) {
                missing--;
            }

            need[s[r]]--;

            // Jab saare required characters mil gaye
            while (missing == 0) {

                // Minimum window update karo
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }

                // Left character remove karo
                need[s[l]]++;

                if (need[s[l]] > 0) {
                    missing++;
                }

                l++;
            }
        }

        return minLen == INT_MAX
            ? ""
            : s.substr(start, minLen);
    }
};
