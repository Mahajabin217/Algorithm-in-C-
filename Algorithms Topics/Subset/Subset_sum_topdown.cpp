#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
bool subset_sum(int n, int a[], int sum)
{
    // base case
        if (n == 0)
    {
        if (sum == 0)
            return true;
        else
            return false;
    }
    // Memoization 
    if (dp[n][sum] != -1)
        return dp[n][sum];
    if (a[n - 1] <= sum)
    {
        // option 2 ta
        // niye dekhbo, na niye dekhbo
        bool op1 = subset_sum(n - 1, a, sum - a[n - 1]);
        bool op2 = subset_sum(n - 1, a, sum);
        return dp[n][sum] = op1 || op2;
    }
    else
    {
        // option 1 ta
        // na niyei dekhbo
        return dp[n][sum] = subset_sum(n - 1, a, sum);
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int sum;
    cin >> sum;
    if (subset_sum(n, a, sum))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}