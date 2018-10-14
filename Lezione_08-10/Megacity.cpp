
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SOLUTION DESCRIPTION:
 * We sort the cities by distance from (0,0). Then we scan the array until
 * the population becomes greater or equal than 1000000. The answer is the
 * distance of the last used city; or -1 if the population never reach 
 * 1000000.
 * 
*/


#include <bits/stdc++.h>

using namespace std;

struct City{
    int x, y, p;
    
    City( int x_, int y_, int p_ ) {
        x = x_;
        y = y_;
        p = p_;
    }
};

bool operator <( const City& a, const City& b ) {
    return ( a.x * a.x + a.y * a.y ) < ( b.x * b.x + b.y * b.y );
}

int n, s;
int a, b, c;
vector < City > C;

int main() {
	ios_base::sync_with_stdio(false);
	
	cin >> n >> s;
	
	C.reserve( n );
	
	for( int i = 0; i < n; i++ ) {
	    cin >> a >> b >> c;
	    C.push_back( City( a, b, c ));
	}
	
	sort( C.begin(), C.end() );
	auto it = C.begin();
	
	while( s < 1000000 and it != C.end() ) {
	    s += (*it).p;
	    it++;
	}
	
	cout << setprecision(15);
	if(it == C.begin() ) cout << 0.0 << endl;
	else if( (it == C.end() and s >= 1000000) or it != C.end() ) {
	    it--;
	    City f = *it;
	    cout << sqrt(f.x*f.x+f.y*f.y) << endl;
	} else cout << -1 << endl;
	
	return 0;
}
