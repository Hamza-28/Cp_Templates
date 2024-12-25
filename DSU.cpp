/*
  In the name of Allah, The Most Gracious and The Most Merciful.

  Glory be to You(Allah)! We have no knowledge except what You have taught us.
  It is you who are the Knowledgeable, the Wise.
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
int parent[N], sz[N];

void make_set(int v) {
  parent[v] = v;
  sz[v] = 1;
}

int find_set(int v) {
  if (v == parent[v]) return v;
  return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (sz[a] < sz[b]) swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];
  }
}

int main() {
  ios_base :: sync_with_stdio(0);
  cin.tie(0);

  

  return 0;
}
