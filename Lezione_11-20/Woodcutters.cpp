
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SOLUTION DESCRIPTION:
 * This is a dp solution. For each tree we store the best solution in both
 * cases it falls left or right, considering only trees on the left.
 * Given the answer for i-th tree, it's easy to compute it also for i+1-th,
 * distinguing some cases, as you can see in lines 43-45.
 * Complexity: O(N) both in space and time.
 * 
*/


#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000


int n;
int x[MAXN + 1], h[MAXN];

int dp[MAXN][2];

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	#define endl '\n'
	
	cin >> n;
	for( int i = 0; i < n; i++ ) cin >> x[i] >> h[i];
	
	dp[0][0] = 1;
	dp[0][1] = (h[0] + x[0] <= x[1] ? 1 : 0);
	x[n] = INT_MAX; // Avoid problems with last tree
	
	for( int i = 1; i < n; i++ ) {
		dp[i][0] = max( dp[i-1][0] + (x[i] - h[i] > x[i-1] ? 1 : 0),
						dp[i-1][1] + (x[i] - h[i] > x[i-1] + h[i-1] ? 1 : 0) );
		dp[i][1] = max(dp[i-1][1], dp[i-1][0]) + (x[i] + h[i] < x[i+1] ? 1 : 0);
	}
	
	cout << max(dp[n-1][0], dp[n-1][1]) << endl;
	
	return 0;
}
