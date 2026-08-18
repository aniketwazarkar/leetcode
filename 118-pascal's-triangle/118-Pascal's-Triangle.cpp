class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;

        for (int row = 0; row < numRows; row++) {
            // Make a new empty row, sized correctly (row+1 numbers)
            vector<int> currentRow(row + 1);

            // The first and last number in every row is always 1
            currentRow[0] = 1;
            currentRow[row] = 1;

            // Fill in the middle numbers
            for (int col = 1; col < row; col++) {
                // Add the two numbers above: same column and one column before,
                // from previous row
                currentRow[col] =
                    triangle[row - 1][col - 1] + triangle[row - 1][col];
            }

            // Add this finished row to our triangle
            triangle.push_back(currentRow);
        }

        // Now let's print it nicely
        for (int row = 0; row < numRows; row++) {
            for (int col = 0; col <= row; col++) {
                cout << triangle[row][col] << " ";
            }
            cout << endl;
        }
        return triangle;
    }
};