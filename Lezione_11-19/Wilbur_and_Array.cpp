
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SOLUTION DESCRIPTION:
 * The key observation is that a position is affected by all position that 
 * preced, and it affects all following positions. So that we can simply 
 * modify numbers in order.
 * Complexity: O(N) in time and O(1) in space.
 * 
*/


#include <bits/stdc++.h>

using namespace std;

int n;
long long actual, total, ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	#define endl '\n'
	
	cin >> n;
	while( n-- ) {
		cin >> actual;
		ans += abs( total - actual);
		total = actual;
	}
	
	cout << ans;
	
	return 0;
}
