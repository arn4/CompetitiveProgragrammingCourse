
/* Luca Arnaboldi
 * 
 * Competitive Programming and Contest, a.a. 2018-2019
*/

/* SOLUTION DESCRIPTION:
 * The solution is trivial once found the strongly connected components 
 * of the graph. This solution uses Tarjan algorithm. The implementation
 * is from SNS's ICPC notebook.
 * Complexity: O( n + m ) both space and time. 
 * 
*/


#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000
#define MOD 1000000007

// Tarjan Algorithm
struct StronglyConnectedComponents{
	int V;
	const vector<int>* aa;
	int current_time;
	vector <int> opening_time;
	vector<bool> on_stack;
	vector<int> low_link;
	
	vector< vector<int> > components;
	vector<int> current_stack;
	
	StronglyConnectedComponents( int V, const vector<int> aa[] ) : 
			V(V),
			aa(aa),
			current_time(0),
			opening_time( V, -1 ),
			on_stack( V,false ),
			low_link(V) {
		for( int v = 0; v < V; v++ ) {
			if( opening_time[v] == -1 ) FindStrongComponents(v);
		}
	}
	
	vector<vector<int>> GetComponents() {
		return components;
	}
	
	void FindStrongComponents( int v ) {
		opening_time[v] = low_link[v] = current_time;
		current_time++;
		on_stack[v] = true;
		current_stack.push_back( v );
		for( int a: aa[v] ) {
			if( opening_time[a] == -1 ) {
				FindStrongComponents(a);
				low_link[v] = min(low_link[v], low_link[a]);
			} else if ( on_stack[a] ) {
				low_link[v] = min(low_link[v], low_link[a]);
			}
		}
		if (low_link[v] == opening_time[v] ) {
			components.emplace_back();
			while (true) {
				int u = current_stack.back();
				current_stack.pop_back();
				on_stack[u] = false;
				components.back().push_back(u);
				if (v==u) break;
			}
		}
	}

};

vector<vector<int>> FindSCC( int V, const vector<int> aa[]) {
	StronglyConnectedComponents scc(V, aa);
	auto components = scc.GetComponents();
	reverse(components.begin(), components.end());
	return components;
}
// end of tarjan 


int n, m;
vector <int> G[MAXN+1];
int cost[MAXN+1];

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	#define endl '\n'
	
	cin >> n;
	for ( int i = 0; i < n; i++) cin >> cost[i];
	
	int a, b;
	cin >> m;
	for( int i = 0; i < m; i++ ) {
		cin >> a >> b; a--; b--;
		G[a].push_back(b);
	}
	
	auto scc = FindSCC( n, G );
	long long total = 1, ans = 0;
	
	for( auto c: scc ) {
		int mic = INT_MAX, cnt = 1;
		for (auto v: c) {
			if ( mic == cost[v] ) cnt++;
			else if ( mic > cost[v] ) {
				mic = cost[v];
				cnt = 1;
			}
		}
		total *= cnt;
		total %= MOD;
		ans += mic;
	}
	
	cout << ans << ' ' << total << endl;

	return 0;
}









