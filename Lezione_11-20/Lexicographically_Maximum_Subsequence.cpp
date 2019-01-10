
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SOLUTION DESCRIPTION:
 * 
 * 
*/


#include <bits/stdc++.h>

using namespace std;

string S, ans;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	#define endl '\n'
	
	cin >> S;
	
	for(char c: S) {
		while(not ans.empty() and c > ans.back()) 
			ans.pop_back();
			
		ans.push_back(c);
	}
	
	cout << ans << endl;
	
	return 0;
}
