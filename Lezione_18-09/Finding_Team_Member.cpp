
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SOLUTION DESCRIPTION:
 * We notice that the highest-rated couple will be a team for sure beacause
 * both of them haven't a better choice. Now, ignoring the first two, 
 * the problem of choosing the others couples is the same as the starting
 * one, but the size of N is decreased by 1. So by induction we can prove 
 * that the solution can be found ordering the couples by rating, and then
 * pick the best one that hasn't a team member already choosed.
 * Time complexity is O( (2N)^2*log( (2N)^2 ) ) = O( N^2logN ), space 
 * complexity is O( N^2 ).
*/


#include <bits/stdc++.h>

using namespace std;

#define MAXN 400

int N;
int v;
vector < pair< int, pair< int, int > > > couples;
bool occuped[2*MAXN+1];
int teammate[2*MAXN+1];

int main() {
	
	ios_base::sync_with_stdio(false);
	
	cin >> N;
	
	for(int i = 2; i <= 2*N; i++ ) {
		for(int j = 1; j < i; j++ ) {
			cin >> v;
			couples.push_back( make_pair( -v, make_pair( i, j ) ) );
		}
	}
	
	sort( couples.begin(), couples.end() );
	
	for( auto c: couples ) {
		// cout << c.first << ' ' << c.second.first << ' ' << c.second.second << endl;
		if( !occuped[c.second.first] && !occuped[c.second.second] ) {
			teammate[c.second.first] = c.second.second;
			teammate[c.second.second] = c.second.first;
			occuped[c.second.first] = true;
			occuped[c.second.second] = true;
		}
		
	}
	
	for( int i = 1; i <= 2*N; i++ ) cout << teammate[i] << ' ';
	cout << endl;
	
	return 0;
}
