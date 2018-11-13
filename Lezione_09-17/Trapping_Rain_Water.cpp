
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SOLUTION DESCRIPTION:
 * The level of water over a block is given by the minimum between maximum
 * height on left blocks and maximum height on right blocks. We can easy
 * compute the level by precalculating these two maximums. 
 * Time complexity is O( T*N ), space complexity is O( N ).
 * 
*/


#include <bits/stdc++.h>

using namespace std;

#define MAXN 100

int T, N;
int total_water;
int a[MAXN], left_max[MAXN], right_max[MAXN];


int main() {
	
	ios_base::sync_with_stdio(false);
	
	cin >> T;
	
	while( T-- ) {
		cin >> N;
		total_water = 0;
		for(int i = 0; i < N; i++ ) cin >> a[i];
	
		left_max[0] = a[0];
		for( int i = 1; i < N; i++ ) left_max[i] = max( left_max[i-1], a[i] );
		
		right_max[N-1] = a[N-1];
		for( int i = N-2; i >= 0; i-- ) right_max[i] = max( right_max[i+1], a[i] );
	
		
		for( int i = 0; i < N - 1; i++) total_water += max( min( left_max[i], right_max[i] ) - a[i], 0 );
		
		cout << total_water << endl;
	}
	
	return 0;
}
