/*
	In the name of Allah, The Most Gracious and The Most Merciful.

	Glory be to You(Allah)! We have no knowledge except what You have taught us.
	It is you who are the Knowledgeable, the Wise.
*/

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Edge {
	int u, v, w;
};

void solve() {
	int n, m;
	cin >> n >> m;
	vector<Edge> e(m);
	for (int i = 0; i < m; ++i) {
		cin >> e[i].u >> e[i].v >> e[i].w;
	}

	vector<int> d(n + 1, INF);
	d[1] = 0; 	// distance of source node
	vector<int> p(n + 1, -1); 	// parent vector
	int x;
	for (int i = 1; i <= n; ++i) {
		x = -1;
		for (auto [u, v, w]: e)
			if (d[u] < INF and d[u] + w < d[v]) {
				d[v] = d[u] + w;
				p[v] = u;
				x = v;
			}
	}

	if (x == -1) cout << "No negative cycle found\n";
	else {
		int y = x;
		for (int i = 0; i < n; ++i) y = p[y];

		vector<int> path;
		for (int cur = y; ; cur = p[cur]) {
			path.push_back(cur);
			if (cur == y && path.size() > 1) break;
		}
		reverse(path.begin(), path.end());

		cout << "Negative cycle: ";
		for (int u : path) cout << u << " ";
		cout << "\n";
	}
}

int main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);

	solve();

	return 0;
}
