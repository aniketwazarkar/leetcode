class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = arr[0].size();

        int col0 = 1;

        // Step 1: use first row and first column as markers
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] == 0) {
                    arr[i][0] = 0;
                    if (j != 0) {
                        arr[0][j] = 0;
                    } else {
                        col0 = 0;
                    }
                }
            }
        }

        // Step 2: zero out cells based on markers (skip row 0 and col 0!)
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (arr[i][j] != 0) {
                    if (arr[0][j] == 0 || arr[i][0] == 0) {
                        arr[i][j] = 0;
                    }
                }
            }
        }

        // Step 3: handle row 0 (length n, not m)
        if (arr[0][0] == 0) {
            for (int j = 0; j < n; j++) {
                arr[0][j] = 0;
            }
        }

        // Step 4: handle column 0 (length m, not n)
        if (col0 == 0) {
            for (int i = 0; i < m; i++) {
                arr[i][0] = 0;
            }
        }
    }
};