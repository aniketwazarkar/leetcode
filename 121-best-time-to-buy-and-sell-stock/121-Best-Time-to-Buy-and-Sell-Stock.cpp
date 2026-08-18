class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int maxProfit = 0;
        int mini = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            int curProfit = arr[i] - mini;
            maxProfit = max(maxProfit, curProfit);
            mini = min(mini, arr[i]);
        }
        return maxProfit;
    }
};