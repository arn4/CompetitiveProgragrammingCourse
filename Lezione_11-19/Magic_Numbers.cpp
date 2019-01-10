
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SOLUTION DESCRIPTION:
 * We scan the string backward and simply check if all the rules are
 * respected.
 * Complexity: O(size(S)) in time and O(size(S)) in space. Space complexity
 * can be reduced to O(1) easily since is not necessary to store all the 
 * string at the same time.
*/


#include <bits/stdc++.h>

using namespace std;

void term() {
	cout << "NO" << endl;
	exit(0);
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	#define endl '\n'
	
	string S;
	int four = 0;
	
	cin >> S;
	for(int i = S.size()-1; i >= 0; i--) {
		if(S[i] == '4') {
			if( i == 0 ) term();
			four++;
		} else if(S[i] == '1') {
			four = 0;
		} else term();
	
		if(four > 2) term();
	}
	
	cout << "YES" << endl;
	return 0;
}
