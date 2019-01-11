
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SOLUTION DESCRIPTION:
 * The tecnich used is DFS+DP. For each vertex we compute the solution
 * for the subtree having it as radix, in both case that we use or not the
 * vertex considered to solve the subproblem. 
 * Complexity: O(N) in both time and space.
*/


#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000

int n;
vector<int> G[MAXN+1];
vector<bool> visited;

// {preso, non preso}
pair<int,int> dfs(int v) {
	visited[v] = true;
	
	pair<int, int> ans = {1,0};
	
	for(int u: G[v]) if(not visited[u]) {
		auto ch = dfs(u);
		// preso
		ans.first += min(ch.first, ch.second);
		// non preso
		ans.second += ch.first;
	}

	return ans;
}


int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	#define endl '\n'
	
	cin >> n;
	int a, b;
	for(int i = 0; i < n-1; i++) {
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	visited.assign(n+1, false);
	auto ans = dfs(1);
	cout << min(ans.first, ans.second) << endl;
	
	return 0;
}
