class Solution {
public:
    int majorityElement(vector<int>& arr) {
        unordered_map<int, int> freq;

        for (int digit : arr) {
            freq[digit]++;
        }

        for (auto& entry : freq) {
            if (entry.second > arr.size() / 2) {
                return entry.first;
            }
        }

        return 0;
    }
};