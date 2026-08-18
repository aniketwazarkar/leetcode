class Solution {
public:

    void setZeroes(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = arr[0].size();

        vector<int> rowMark(m, 0);
        vector<int> colMark(n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] == 0) {
                    rowMark[i] = 1;
                    colMark[j] = 1;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rowMark[i] == 1 || colMark[j] == 1) {
                    arr[i][j] = 0;
                }
            }
        }
    }
};