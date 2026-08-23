class Solution {
public:
    bool sumGame(string num) {
        int leftSumCount = 0;
        int rightSumCount = 0;

        int leftQnMarkCount = 0;
        int rightQnMarkCount = 0;

        int n = num.length();

        for (int i = 0; i < n; i++) {
            if (num[i] == '?') {
                if (i < n / 2) {
                    leftQnMarkCount++;
                } else {
                    rightQnMarkCount++;
                }
            } else {
                if (i < n / 2) {
                    leftSumCount += num[i] - '0';
                } else {
                    rightSumCount += num[i] - '0';
                }
            }
        }

        int totalQnMark = leftQnMarkCount + rightQnMarkCount;
        if (totalQnMark % 2 == 1) {
            return true;
        }
        int LEFT = 2 * leftSumCount + 9 * leftQnMarkCount;
        int RIGHT = 2 * rightSumCount + 9 * rightQnMarkCount;

        if (LEFT == RIGHT) {
            return false;
        }
        return true;
    }
};