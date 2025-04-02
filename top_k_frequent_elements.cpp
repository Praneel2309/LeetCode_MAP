class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq_map;

        for (int num : nums) {
            freq_map[num]++;
        }

        // Create a max heap (priority queue)
        priority_queue<pair<int, int>> max_heap;

        // Push elements into the heap with frequency as priority
        for (auto& entry : freq_map) {
            max_heap.push({entry.second, entry.first});
        }

        vector<int> result;
        while (k-- > 0) {
            result.push_back(max_heap.top().second);
            max_heap.pop();
        }

        return result;
    }
};
