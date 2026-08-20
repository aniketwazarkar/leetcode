class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        vector<vector<int>> ans;
        vector<int> set;

        int n = arr.size();
        sort(arr.begin(),arr.end());

        set.push_back(arr[0][0]);
        set.push_back(arr[0][1]);
        

        for (int i = 1; i < n; i++) {

            if (set[1] >= arr[i][0]) {
                set[1] = max(set[1], arr[i][1]);
            } 
            else {
                ans.push_back(set);
                set.clear();

                set.push_back(arr[i][0]);
                set.push_back(arr[i][1]);
            }
        }

        ans.push_back(set);

        return ans;
    }
};
