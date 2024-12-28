/*
	In the name of Allah, The Most Gracious and The Most Merciful.

	Glory be to You(Allah)! We have no knowledge except what You have taught us.
	It is you who are the Knowledgeable, the Wise.
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;

vector<int> adj[N];
int degree[N];

void solve() {
	int n, m;
	cin >> n >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		degree[v]++;
		adj[u].push_back(v);
	}

	queue<int> q;
	for (int i = 1; i <= n; ++i) {
		if (degree[i] == 0) q.push(i);
	}

	vector<int> list;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		list.push_back(u);
		for (auto v: adj[u]) {
			degree[v]--;
			if (degree[v] == 0) q.push(v);
		}
	}

	if (list.size() < n) {
		cout << "IMPOSSIBLE\n";
		return;
	}

	for (auto x: list) {
		cout << x << " ";
	}
	cout << "\n";
}

int main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	while (t--) {
		solve();
	}

	return 0;
}


// using DFS
	


#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<int> adj[N];
vector<int> ans;
bool vis[N];

void dfs(int v) {
	vis[v] = true;
	for (int u : adj[v]) {
		if (!vis[u]) dfs(u);
	}
	ans.push_back(v);
}

void topological_sort() {
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) dfs(i);
	}
	reverse(ans.begin(), ans.end());
}

int main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);

	return 0;
}
