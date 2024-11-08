/*
  In the name of Allah, The Most Gracious and The Most Merciful.

  Glory be to You(Allah)! We have no knowledge except what You have taught us.
  It is you who are the Knowledgeable, the Wise.
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 100, inf = 2e9 + 9;
int d[N][N], nextof[N][N];
int n;

void init() {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      nextof[i][j] = j;
      d[i][j] = inf;
      if (i == j) d[i][j] = 0;
    }
  }
}

void cal() {
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (d[i][k] + d[k][j] < d[i][j]) {
          d[i][j] = d[i][k] + d[k][j]; 
          nextof[i][j] = nextof[i][k];
        }
      }
    }
  }
}

vector<int> findPath(int i, int j) {
  vector<int> path = {i};
  while(i != j) {
    i = nextof[i][j];
    path.push_back(i);
  }
  return path;
}

int main() {
  ios_base :: sync_with_stdio(0);
  cin.tie(0);
  
  int e;
  cin >> n >> e;
  init();
  while (e--) {
    int u, v, w;
    cin >> u >> v >> w;
    d[u][v] = w;
  }
  
  cal();
  // for (int i = 1; i <= n; ++i) {
  //   for (int j = 1; j <= n; ++j) {
  //     cout << setw(3) << d[i][j] << " \n"[j == n];
  //   }
  // }

  vector<int> path = findPath(1, 3);
  for (auto i: path) {
    cout << i << ' ';
  } 

  return 0;
}
