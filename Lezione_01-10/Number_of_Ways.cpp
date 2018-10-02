
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SOLUTION DESCRIPTION:
 * The solution is the implementation of the one discussed at lecture.
 * Complexity is lienear both in time and space.
*/


#include <bits/stdc++.h>

using namespace std;

#define MAXN 500000

int N;
long long total, A[MAXN];
long long rightc[MAXN+1];
long long answer;

int main() {
	
	ios_base::sync_with_stdio(false);
	
	cin >> N;
	
	for( int i = 0; i < N; i++ ) {
		cin >> A[i];
		total += A[i];
	}
	
	if( total % 3 != 0 ) {
		cout << 0 << endl;
		return 0;
	}
	
	total /= 3;
	
	long long partial = 0;
	
	for( int i = N - 1; i >= 0; i-- ) {
		partial += A[i];
		rightc[i] = rightc[i+1] + ( partial == total ? 1 : 0 );
	}
	
	partial = 0;
	
	for( int i = 0; i < N - 2; i++ ) {
		partial += A[i];
		if( partial == total ) answer += rightc[i+2];
	}
	
	cout << answer << endl;
	
	return 0;
}
