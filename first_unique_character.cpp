class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> freq_map;

        for (char c : s) {
            freq_map[c]++;
        }

        // Find the first character with frequency 1
        for (int i = 0; i < s.size(); ++i) {
            if (freq_map[s[i]] == 1) {
                return i; 
            }
        }

        return -1; 
    }
};
