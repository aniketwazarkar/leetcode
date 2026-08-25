class Solution {
public:

    int findMissing(unordered_map<int, int>& mp, int k) {
        int multiple = k;

        while (true) {
            if (mp.find(multiple) == mp.end()) {
                return multiple;
            }

            multiple += k;
        }
    }

    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for (int q : nums) {
            mp[q]++;
        }

        int ans = findMissing(mp, k);

        return ans;
    }
};