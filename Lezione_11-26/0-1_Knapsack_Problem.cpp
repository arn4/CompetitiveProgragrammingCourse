
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SOLUTION DESCRIPTION:
 * Implementation of: https://en.wikipedia.org/wiki/Knapsack_problem
*/


#include <bits/stdc++.h>

using namespace std;

void solve() {
	int N, W;
	cin >> N >> W;
	vector <int> val, wt;
	val.resize(N);
	wt.resize(N);
	for(int i = 0; i < N; i++)
		cin >> val[i];
	for(int i = 0; i < N; i++)
		cin >> wt[i];
		
	vector<vector<int>> dp(N + 1, vector<int>( W + 1, 0));
	
	for(int w = 0; w <= W; w++) 
		for(int i = 1; i <= N; i++) {
			dp[i][w] = dp[i-1][w];
			if( wt[i-1] <= w) 
				dp[i][w] = max(dp[i][w], dp[i-1][w-wt[i-1]] + val[i-1]);
		}
	
	cout << dp[N][W] << endl;
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
