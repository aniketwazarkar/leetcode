class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind = -1;
        int n = nums.size();

        // Find the break point from wherte we will swap and reverse the 2nd half of an array
        for (int i = n-2; i >=0; i--) {
            if (nums[i] < nums[i + 1]) {
                ind = i;
                break;
            }
        }

        // No lexicographical order possible now, Give array in sorted order i.e. reversed.
        if (ind == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Swap the two values to make sure we get the next lexicographical combination here.
        for (int i = n - 1; i > ind; i--) {
            if (nums[i] > nums[ind]) {
                swap(nums[i], nums[ind]);
                break;
            }
        }

        // Reverese the remaining part of an array 
        reverse(nums.begin() + ind + 1, nums.end());
    }
};