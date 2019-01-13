
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SOLUTION DESCRIPTION:
 * We use the function prefixTable from KMP to compute the asnwer for all
 * prefix of the given string.
 * Complexity: O(size(S)))
*/


#include <bits/stdc++.h>

using namespace std;

template<typename Container>
vector<int> prefixTable(const Container& P) {
	vector<int> pi(P.size()); // back_table for the pattern

	pi[0] = 0;
	for(unsigned int i = 1; i < P.size(); i++) {
		unsigned int j = pi[i-1];
		while(j > 0 and P[i] != P[j]) j = pi[j-1];
		if(P[i] == P[j])
			j++;
		pi[i] = j;
	}
	return pi;
}

void solve() {
	string S;
	cin >> S;
	const auto& pt = prefixTable(S);
	cout << pt[S.size()-1]<< endl;
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
