
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SOLUTION DESCRIPTION:
 * We scan the array backwards, using a stack to keep the next greater 
 * element. Given a number we remove from the stack top all the elements
 * that are less or equal than the actual. If the stack is empty there 
 * isn't a next greater elemnt, otherwise it is the stack top. This is true
 * because the stack is ordered in decreasing order, and the elemets 
 * removed at each step can't be a next larger element beacause they are
 * smaller than the actual numbers and they are at left than actual number
 * in the array.
 * Every elemnt can enter and axit at most one from the stack, so complexity 
 * is O( N ) both space anf time.
 * 
*/


#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000

int T;
int N;
int A[MAXN];
stack <int> S;

int main() {
	
	ios_base::sync_with_stdio(false);
	
	cin >> T;
	
	while( T-- ) {
		cin >> N;
		while( !S.empty() ) S.pop();
		for( int i = 0; i < N; i++ ) cin >> A[i];
		
		
		for( int i = N - 1; i >= 0; i-- ) {
			
			while( !S.empty() and A[i] >= S.top() ) S.pop();
			
			int to_insert = A[i];
			
			if( S.empty() ) 
				A[i] = -1;
			else 
				A[i] = S.top();
			
			S.push( to_insert );
		}
		
		for( int i = 0; i < N; i++ ) cout << A[i] << ' ';
		
		cout << endl;
			
	}
	
	return 0;
}
