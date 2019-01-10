
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SOLUTION DESCRIPTION:
 * We use the string ans as a stack. We scan S and remove all characters
 * at the top of the stack until we find one that is greater or equal than
 *  the actual char in S; then we insert the actual char in the stack ans.
 * It's easy to convice that we obtain the correct answer this way.
 * Since a char can enter and exit from the stack at most once, time and 
 * space complexity is O(size(S)).
 * 
*/


#include <bits/stdc++.h>

using namespace std;

string S, ans;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	#define endl '\n'
	
	cin >> S;
	
	for(char c: S) {
		while(not ans.empty() and c > ans.back()) 
			ans.pop_back();
			
		ans.push_back(c);
	}
	
	cout << ans << endl;
	
	return 0;
}
