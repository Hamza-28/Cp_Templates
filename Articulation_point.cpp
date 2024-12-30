vector<vector<int>> adj;
vector<bool> vis, is_cutpoint;
vector<int> tin, low;
int timer;

void dfs(int u, int p = -1) {
	vis[u] = true;
	tin[u] = low[u] = timer++;
	int children = 0;
	for (int v : adj[u]) {
		if (v == p) continue;
		if (vis[v]) {
			low[u] = min(low[u], tin[v]);
		} else {
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] >= tin[u] && p != -1) {
				is_cutpoint[u] = true;
			}
			++children;
		}
	}
	if(p == -1 && children > 1) {
		is_cutpoint[u] = true;
	}
}

void find_cutpoints(int n) {
	timer = 0;
	vis.assign(n + 1, false);
	is_cutpoint.assign(n + 1, false);
	tin.assign(n + 1, -1);
	low.assign(n + 1, -1);
	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) {
			dfs (i);
		}
	}
}
