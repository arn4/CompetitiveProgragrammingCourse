
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SOLUTION DESCRIPTION:
 * First of all we observ that the problem is equivalent to find the 
 * longest prefix of A that occur in B concatenated with itself. We use 
 * a modified version of KMP algorithm, where we keep track not only of 
 * complete occurnce of A in B, but also of partial ones.
 * Complexity: O(n) both in time and space.
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

/* Modified KMP algorithm */ 
template<typename Container>
int KMP(const Container& P, const Container& T) {
	unsigned int ans = 0, res = 0;
	const vector<int>& b = prefixTable(P);
	unsigned long j = 0;
	for(unsigned int i = 0; i < T.size()/2; i++) {
		while( j > 0 and P[j] != T[i]) j = b[j-1];
		if(P[j] == T[i])
			j++;
		
		if( min(j, T.size() / 2) > ans) {
			ans = min(j, T.size()/2);
			res = i - j + 1;
		} 			
	}
	return res;
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	#define endl '\n'
	int N;
	cin >> N;
	string A, B;
	cin >> A >> B;
	cout << KMP(A, B+B) << endl;
	
	
	return 0;
}
