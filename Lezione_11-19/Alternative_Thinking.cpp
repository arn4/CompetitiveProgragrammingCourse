
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SOLUTION DESCRIPTION:
 * This is a DP solution. We observe that the solution is the longest 
 * alternating subsequence with at most two pairs of consecutive characters
 * that are equal. sol[c][i] is the solution ending with charcter c with 
 * exactly i repetitions (i = 0, 1, 2). We read all characters updating 
 * sol as you can read in the code.
 * Complexity: O(n) time and O(n) space. It could be solved in O(1) space,
 * but is 30% faster reading all the string than character per character.
*/


#include <bits/stdc++.h>

using namespace std;

int n;
string S;
int sol[2][3];

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	#define endl '\n'
	
	int n;
	cin >> n;
	cin >> S;
	for(char c: S) {
		if(c == '0') {
			sol[0][2] = max({sol[0][1] + 1, sol[1][2]+1, sol[0][2]});
			sol[0][1] = max({sol[0][0] + 1, sol[1][1]+1, sol[0][1]});
			sol[0][0] = max(sol[1][0] + 1, sol[0][0]);
		} else {
			sol[1][2] = max({sol[1][1] + 1, sol[0][2]+1, sol[0][2]});
			sol[1][1] = max({sol[1][0] + 1, sol[0][1]+1, sol[0][1]});
			sol[1][0] = max(sol[0][0] + 1, sol[1][0]);
		}
	}
	
	cout << max({sol[0][0],sol[0][1],sol[0][2],sol[1][0],sol[1][1],sol[1][2]});
	
	return 0;
}
