
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        if (n > m) return false;

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        // First string ki frequency
        for (int i = 0; i < n; i++) {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }

        // First window check
        if (freq1 == freq2) return true;

        // Fixed-size sliding window
        for (int r = n; r < m; r++) {

            // Incoming character add
            freq2[s2[r] - 'a']++;

            // Outgoing character remove
            freq2[s2[r - n] - 'a']--;

            if (freq1 == freq2) {
                return true;
            }
        }

        return false;
    }
};
