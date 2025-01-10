/*
	In the name of Allah, The Most Gracious and The Most Merciful.

	Glory be to You(Allah)! We have no knowledge except what You have taught us.
	It is you who are the Knowledgeable, the Wise.
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9, LOG = 21;
int up[N][LOG], depth[N];
vector<int> children[N];

void dfs(int a) {
	for (auto b: children[a]) {
		depth[b] = depth[a] + 1;
		up[b][0] = a;	// a is parent of b
		for (int i = 1; i < LOG; ++i) {
			up[b][i] = up[up[b][i-1]][i-1];
		}
		dfs(b);
	}
}

int getKthAncestor(int node, int k) {
	if (depth[node] < k) return -1;
	for (int i = 0; i < LOG; ++i) { 
		if (k & (1 << i)) {
			node = up[node][i];
		}
	}
	return node;
}

int getLCA(int u, int v) {
	if (depth[u] < depth[v]) swap(u, v);
	u = getKthAncestor(u, depth[u] - depth[v]);
	if (u == v) return v;
	for (int i = LOG - 1; i >= 0; --i) {
		if (up[u][i] != up[v][i]) {
			u = up[u][i];
			v = up[v][i];
		}
	}
	return up[v][0];
}

int main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int m;
		cin >> m;
		for (int j = 0; j < m; ++j) {
			int v;
			cin >> v;
			children[i].push_back(v);
		}
	}	
	dfs(0); // root

	int q;
	cin >> q;
	while (q--) {
		int u, v;
		cin >> u >> v;
		cout << getLCA(u, v) << "\n";
	}

	return 0;
}
