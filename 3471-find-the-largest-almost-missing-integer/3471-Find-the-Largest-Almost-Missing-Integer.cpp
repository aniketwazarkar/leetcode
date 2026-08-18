class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;

        for (int i = 0; i <= nums.size() - k; ++i) {
            unordered_map<int, bool> seenInThisWindow;

            for (int j = i; j < i + k; ++j) {
                if (!seenInThisWindow[nums[j]]) {
                    freqMap[nums[j]]++;
                    seenInThisWindow[nums[j]] = true;
                }
            }
        }

        int result = -1;
        for (const auto& entry : freqMap) {
            if (entry.second == 1) {
                result = max(result, entry.first);
            }
        }

        return result;
    }
};