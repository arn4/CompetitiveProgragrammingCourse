
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SOLUTION DESCRIPTION:
 * DP subproblema are all the substrings. The solution is very similar to 
 * lonhest common subsequence and easily understandable from the code.
 * Complexity: O(size(S)^2) both time and space.
*/


#include <bits/stdc++.h>

using namespace std;

int dp[1000][1001]; // TLE using vector...

void solve() {
	string A;
	cin >> A;
	int n = A.size();
	
	for(int i = 0; i < n; i++)
		dp[i][i+1] = 1;
	
	for(int l = 2; l <= n; l++) 
		for(int i = 0; i < n and i + l <= n; i++) {
			dp[i][i+l] = max({dp[i+1][i+l],
							  dp[i][i+l-1], 
							  (A[i]==A[i+l-1] ? 2 + dp[i+1][i+l-1]:INT_MIN) });
		}
	cout << dp[0][n] << endl;
}


int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	#define endl '\n'
	
	int T;
	cin >> T;
	while(T--)
		solve();
	
	return 0;
}
