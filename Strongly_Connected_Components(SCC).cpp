/*
	In the name of Allah, The Most Gracious and The Most Merciful.

	Glory be to You(Allah)! We have no knowledge except what You have taught us.
	It is you who are the Knowledgeable, the Wise.
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;

int vis[N], id[N];
vector<int> adj[N], adj_t[N];
vector<int> order;

void dfs(int v) {
	vis[v] = 1;
	for (int u: adj[v]) {
		if (!vis[u]) {
			dfs(u);
		}
	}
	order.push_back(v);
}

void dfs2(int v, int cnt) {
	vis[v] = 1;
	for (int u: adj_t[v]) {
		if (!vis[u]) {
			dfs2(u, cnt);
		}
	}
	id[v] = cnt;
}

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj_t[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) {
			dfs(i);
		}
	}

	int cnt = 0;
	memset(vis, 0, sizeof(vis));
	reverse(order.begin(), order.end());
	for (auto v: order) {
		if (!vis[v]) {
			dfs2(v, cnt);
			++cnt;
		}
	}
	cout << cnt << "\n";
	for (int i = 1; i <= n; ++i) {
		cout << id[i] << "\n";
	}
}

int main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	// cin >> t
	while (t--) {
		solve();
	}

	return 0;
}
