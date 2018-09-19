
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SOLUTION DESCRIPTION:
 * Since the leght of the bars is limited to 1000, we keep track of the 
 * number of bars for every lenght. Then we find two required numbers scanning 
 * all possible leghts.
 * Time complexity is O( N ), space complexity is O( 1 ) since it does 
 * not depend on the size of the input.
*/


#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000

int N, l;
int counter[MAXN+1];
int max_height = -1;
int towers = 0;

int main() {
	
	ios_base::sync_with_stdio(false);
	
	cin >> N;
	
	while( N -- ) {
		cin >> l;
		counter[l]++;
	}
	
	for( int i = 1; i <= 1000; i++ ) {
		if( counter[i] != 0 ) towers++;
		max_height = max( max_height, counter[i] );
	}
	
	cout << max_height << ' ' << towers << endl;
	
	return 0;
}
