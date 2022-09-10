#include <iostream>
using namespace std;

int maxBallonsBottomUp(int nums[],int n)
{
		// Extend list with head and tail (both are 1), index starts at 1
		int array[n + 2];
		array[0] = 1;
		array[n+2 - 1] = 1;
		for (int i = 0; i < n; i++) {
			array[i + 1] = nums[i];
		}
        n=n+2;

		// Initialize DP arrays, 1 index based
		int dp[n][n]; // dp[i][j] stands for
															// max coins at i
															// step, burst j
		for (int i = 0; i <n; i++) {
			for (int j = 0; j < n; j++) {
				dp[i][j] = 0;
			}
		}
		int r = 0;
		for (int i = 1; i < n - 1; i++) {
			for (int j = i; j >= 1; j--) {
				// k as last
				for (int k = j; k <= i; k++) {
						if (j - 1 == 0 && i + 1 == n - 1) {
						r = array[k];

					} else {
						r = array[j - 1] * array[i + 1];
					}
					dp[j][i] =max(r + dp[j][k - 1] + dp[k + 1][i],dp[j][i]);
				}
			}
		}

		return dp[1][n-2];
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int ans = maxBallonsBottomUp(a, n);
        cout<<ans<<endl;
    }
    return 0;
}
