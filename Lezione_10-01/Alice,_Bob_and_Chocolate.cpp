
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SOLUTION DESCRIPTION:
 * We use a deque to simulate the process. The front is Alice side, the 
 * back is Bob side. At every step the guy with less time spent eats a bar.
 * Since a bar enters and exits from deque exactily one time, the complexity
 * is linear both in time and space.
 * 
*/


#include <bits/stdc++.h>

using namespace std;

int N, tmp;
deque <int> bars;
int ta, tb, ba, bb;

int main() {
	
	ios_base::sync_with_stdio(false);
	
	cin >> N;
	
	while( N-- ) {
		cin >> tmp;
		bars.push_back( tmp );
	}
	
	while( not bars.empty() ) {
		if( ta <= tb ) {
			ta += bars.front();
			ba++;
			bars.pop_front();
		} else {
			tb += bars.back();
			bb++;
			bars.pop_back();
		}
	}
	
	cout << ba << ' ' << bb << endl;
	
	return 0;
}
