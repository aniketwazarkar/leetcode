class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        long long low = 1;
        long long high = 1LL * (*min_element(coins.begin(), coins.end())) * k;

        while (low < high) {
            long long mid = low + (high - low) / 2;
            long long count = 0;

            int n = coins.size();

            for (int mask = 1; mask < (1 << n); mask++) {
                long long lcm = 1;
                int bits = 0;
                bool overflow = false;

                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        bits++;

                        long long g = gcd(lcm, (long long)coins[i]);
                        lcm = (lcm / g) * coins[i];

                        if (lcm > mid) {
                            overflow = true;
                            break;
                        }
                    }
                }

                if (overflow)
                    continue;

                if (bits % 2 == 1)
                    count += mid / lcm;
                else
                    count -= mid / lcm;
            }

            if (count >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};
