
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SOLUTION DESCRIPTION:
 * We store all the values in an array, and then we scan backwards for 
 * finding leader elements: if it is a leader we keep it unchanged, 
 * intestead if it isn't a leader we set it to -1;
 * Then we scan the array forward printing all the elements which arent 
 * equal to -1.
 * The time complexity and space complexity are O(N).
 * 
*/


#include <bits/stdc++.h>

using namespace std;

#define MAXN 10000000

int T, N;
int max_value;
long long V[MAXN+1];


int main() {
	
	ios_base::sync_with_stdio(false);
	
	cin >> T;
	while( T-- ) {
		cin >> N;
		max_value = -1;
		
		for( int i = 0; i < N; i++) {
			cin >> V[i];
		}
		
		for( int i = N - 1; i >= 0; i-- ) {
			if( V[i] >= max_value ) {
				max_value = V[i];
			} else {
			    V[i] = -1;
			}
		}
		
		for( int i = 0; i < N; i++) {
			if( V[i] != -1 ) {
			    cout << V[i] << ' ';
			}
		}
		cout << endl;
	}
	
	return 0;
}

