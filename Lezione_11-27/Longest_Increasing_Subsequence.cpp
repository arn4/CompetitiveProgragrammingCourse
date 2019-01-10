
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SOLUTION DESCRIPTION:
 * We store at dp[n] the solution of the problem using the first n element
 * of A. It's obvious how to find the solution for n knwoing the answer for
 * all numbers <= n.
 * Complexity: O(N^2) time and O(N) space.
*/


#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, ans = -1;
	cin >> n;
	vector<int> A(n), dp(n);
	for(auto& a: A) 
		cin >> a;
	
	for(int i = 0; i < n; i++) {
		dp[i] = 1;
		for(int j = 0; j < i; j++)
			if(A[i] > A[j])
				dp[i] = max(dp[i], dp[j] + 1);
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
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
