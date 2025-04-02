class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_map;  //number and index store
        
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];  // Find the complement that adds up to target
            
            // Check if the complement exists in the map
            if (num_map.find(complement) != num_map.end()) {
                // Return the indices of the complement and the current number
                return {num_map[complement], i};
            }
            
            // If complement is not found, store the current number and its index
            num_map[nums[i]] = i;
        }
        
        // If no solution is found (though problem guarantees a solution exists)
        return {};
    }
};
