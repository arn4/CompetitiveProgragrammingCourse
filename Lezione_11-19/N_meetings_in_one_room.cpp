
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SOLUTION DESCRIPTION:
 * This is an implementation of the solution presented during class: we 
 * sort activities by end time and then we procede greadily.
 * Complexity: O(T*N*logN) in time and O(N) in space.
*/


#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b) {
	return a.first.second < b.first.second;
}

void solve() {
	int n;
	vector<pair<pair<int,int>,int>> A, ans; // we store pair {{end_time, start_time}, index}
	
	cin >> n;
	A.resize(n);
	for(unsigned int i = 0; i < A.size(); i++) {
		cin >> A[i].first.second;
		A[i].second = i + 1;
	}
	for(unsigned int i = 0; i < A.size(); i++) {
		cin >> A[i].first.first;
	}
	sort(A.begin(), A.end());
	
	int last = -1;
	for(auto& a: A) {
		if( a.first.second > last ) {
			last = a.first.first;
			ans.push_back(a);
		}	
	}
	
	sort(ans.begin(), ans.end(), cmp);
	for(auto& a: ans) {
		cout << a.second << ' ';
	}
	cout << endl;
}



int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	#define endl '\n'
	
	int T;
	
	cin >> T;
	while(T--) {
		solve();
	}
	
	return 0;
}
