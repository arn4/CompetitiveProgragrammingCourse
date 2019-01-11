
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SOLUTION DESCRIPTION:
 We compute dp(n) for A and B (= reverse of A) as in LIS. Then we find 
 * the best matching, keeping care in the case thw two sequences end with 
 * the same number.
 * Complexity: O(N^2) time and O(N) space.
*/


#include <bits/stdc++.h>

using namespace std;

void LIS(vector<int>& A, vector<int>& dp) {
	int n = A.size();
	for(int i = 0; i < n; i++) {
		dp[i] = 1;
		for(int j = 0; j < i; j++)
			if(A[i] > A[j])
				dp[i] = max(dp[i], dp[j] + 1);
	}
}

void solve() {
	int n, ans = -1;
	cin >> n;
	vector<int> A(n), dpA(n), dpB(n);
	for(auto& a: A) 
		cin >> a;
	vector<int> B = A;
	reverse(B.begin(), B.end());
	
	LIS(A, dpA);
	LIS(B, dpB);
	
	
	
	for(int i = 0; i < n; i++)
		for(int j = n - i - 1; j >= 0; j--) {
			ans = max( ans, dpA[i] + dpB[j] - (A[i] == B[j] ? 1 : 0));
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
