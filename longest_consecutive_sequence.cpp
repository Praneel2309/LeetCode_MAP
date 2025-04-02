class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int max_streak = 0;

        // Iterate through each number in the set
        for (int num : numSet) {
            // Only check for sequences starting from a number that is the beginning of the sequence
            if (numSet.find(num - 1) == numSet.end()) {
                int current_num = num;
                int current_streak = 1;

                // Count how many consecutive numbers exist starting from 'num'
                while (numSet.find(current_num + 1) != numSet.end()) {
                    current_num =current_num + 1;
                    current_streak =current_streak + 1;
                }

                // Update the longest streak
                max_streak = max(max_streak, current_streak);
            }
        }

        return max_streak;
    }
};
