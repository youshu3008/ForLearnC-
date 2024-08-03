#include <iostream>
#include <vector>
using namespace std;

int countWays(int n, int total) {
    vector<vector<int>> dp(n + 1, vector<int>(total + 1, 0));
    
    dp[0][0] = 1; // Base case: one way to reach sum 0 with 0 rounds

    for (int round = 1; round <= n; ++round) {
        for (int sum = 0; sum <= total; ++sum) {
            for (int num = 1; num <= 7; ++num) {
                if (sum >= num) {
                    dp[round][sum] += dp[round - 1][sum - num];
                }
            }
        }
    }
    
    return dp[n][total];
}

int main() {
    int n, total;
    cin >> n >> total;
    
    cout << countWays(n, total) << endl;

    return 0;
}
