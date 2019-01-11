
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SOLUTION DESCRIPTION:
 * The Dp state dp(n,s) represent the possinility to get s using only the
 * first n elements. The recurrence is:
 * dp[n][s] = dp[i-1][s] or dp[i-1][s-A[n-1]].
 * Complexity: O(N*sum) in both time and space.
*/


#include <bits/stdc++.h>

using namespace std;



void solve() {
	int n, goal = 0;
	cin >> n;
	vector<int> A(n);
	for(auto& a: A) {
		cin >> a;
		goal += a;
	}
	
	if(goal%2) {
		cout << "NO" << endl;
		return;
	}
	goal /= 2;
	
	vector<vector<bool>> dp(n + 1, vector<bool>( goal+1, 0));
	dp[0][0] = true;
	
	for(int i = 1; i <= n; i++)
		for(int s = 0; s <= goal; s++) 
			dp[i][s] = dp[i-1][s] or ( s >= A[i-1] and dp[i-1][s-A[i-1]]);
		
	if(dp[n][goal])
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
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
