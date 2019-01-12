
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SOLUTION DESCRIPTION:
 * We use a gready strategy and we claim that exist a solution where 
 * people are sorted by increasing a. Then given a solution for first i 
 * people ordered as described before, inserting the (i+1)th person does 
 * not affect the preceding ones, so it's sufficent to choose the correct
 * height for respecting the condition a_(i+1). If it is not possible it 
 * means that there is no solution for the problem.
 * Complexity: since we use the function insert n times time complexity is
 * O(n^2), while space complexity is O(n).
*/


#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<string, int>> Q;
vector<int> I;
vector<int> o, h;

bool cmp(int a, int b) {
	return Q[a].second < Q[b].second;
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	#define endl '\n'
	
	cin >> n;
	Q.resize(n);
	for(auto& q: Q) {
		cin >> q.first >> q.second;
	}
	
	I.resize(n);
	iota(I.begin(), I.end(), 0);
	sort(I.begin(), I.end(), cmp);
	
	// forse si può fare in NlogN anche questo passaggio, ma tanto non serve...
	o.push_back(I[0]);
	for(int i = 1; i < n; i++) {
		// cant find a solution
		if( Q[I[i]].second > int(o.size()) ) {
			cout << -1 << endl;
			return 0;
		}
		o.insert(o.begin() + Q[I[i]].second, I[i]); 
	}
	
	int H = n + 1;
	h.resize(n);
	for(auto& p: o) {
		h[p] = H--;
	}
	
	for(auto i: I) {
		cout << Q[i].first << ' ' << h[i] << endl;
	}
	 
	return 0;
}
