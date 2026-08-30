class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        auto min_it = min_element(nums.begin(), nums.end());
        auto max_it = max_element(nums.begin(), nums.end());

        int min_pos = min_it - nums.begin();
        int max_pos = max_it - nums.begin();

        int n = nums.size();

        int a = min(min_pos, max_pos);
        int b = max(min_pos, max_pos);

        int ans = min({
            b + 1,
            n - a,
            a + 1 + n - b
        });

        return ans;
    }
};