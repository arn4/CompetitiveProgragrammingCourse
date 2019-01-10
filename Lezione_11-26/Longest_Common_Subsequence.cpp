
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SOLUTION DESCRIPTION:
 * The solution is the implementation of the one discussed during class.
 * Complexity: O(n*m) in time and space.
*/


#include <bits/stdc++.h>

using namespace std;



void solve() {
	int n, m;
	string A, B;
	vector<vector<int>> dp;
	cin >> n >> m;
	cin >> A >> B;
	dp.assign(n + 1, vector<int>( m + 1, 0));
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) {
			dp[i][j] = max(dp[i-1][j-1] + (A[i-1]==B[j-1] ? 1 : 0), max(dp[i-1][j], dp[i][j-1]));
		}
		
	cout << dp[n][m] << endl;
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
