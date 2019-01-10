
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SOLUTION DESCRIPTION:
 * We store in dp[n] the minimum number of jumps needed to get to n. We 
 * scan the array J and for every position we jump in all the possible positions
 * and if we did better than the actual minimum we save it.
 * Complexity: O(N) space and O(N*maxA) time.
 * 
*/


#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> J(n), dp(n, INT_MAX);
	for(auto& j: J)
		cin >> j;
	
	dp[0] = 0;
	for(int i = 0; i < n; i++) 
		if(dp[i] != INT_MAX) 
			for(int j = 1; j <= J[i] and i + j < n; j++)
				dp[i+j] = min(dp[i] + 1, dp[i+j]);
		
	if( dp[n-1] == INT_MAX)
		cout << -1 << endl;
	else 
		cout << dp[n-1] << endl;
	
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
