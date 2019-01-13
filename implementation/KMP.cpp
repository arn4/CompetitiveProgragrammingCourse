
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* KMP
 * Source: cp-algorithms.com and Competitive Programming 3
 */


#include <bits/stdc++.h>

using namespace std;

/* Compute the prefix function of the string P. Since pi[0] is not well 
 * defined we fix it to 0.
 */
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

/* KMP algorithm */ 
template<typename Container>
vector<int> KMP(const Container& P, const Container& T) {
	vector<int> occ;
	const vector<int>& b = prefixTable(P);
	unsigned int j = 0;
	for(unsigned int i = 0; i < T.size(); i++) {
		while( j > 0 and P[j] != T[i]) j = b[j-1];
		if(P[j] == T[i])
			j++;
		if(j == P.size()) {
			occ.push_back(i-j+1);
			j = b[j-1];
		}
	}
	return occ;
}


int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	#define endl '\n'
	int T; cin >> T;
	while(T--) {
		string A, B;
		cin >> A >> B;
		cout << endl;
		vector<int> O = KMP(B, A);
		if(O.size() > 0) 
			cout << O.size() << endl;
		else
			cout << "Not Found" << endl;
		for(auto i: O)
			cout << i+1 << ' ';
		cout << endl;
	}
	
	return 0;
}
