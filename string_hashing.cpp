/*
  In the name of Allah, The Most Gracious and The Most Merciful.

  Glory be to You(Allah)! We have no knowledge except what You have taught us.
  It is you who are the Knowledgeable, the Wise.
*/

#include <bits/stdc++.h>
using namespace std;

const int p1 = 137, mod1 = 127657753, p2 = 277, mod2 = 987654319;
const int N = 1e6 + 3;
array<int, 2> pref[N], pref2[N];
int pw1[N], pw2[N], ipw1[N], ipw2[N];

int power(int a, int n, int mod) {
  int ans = 1 % mod;
  while (n) {
    if (n & 1) ans = 1LL * ans * a % mod;
    a = 1LL * a * a % mod;
    n >>= 1;
  }
  return ans;
}

void prec() {
  pw1[0] = pw2[0] = ipw1[0] = ipw2[0] = 1;
  int ip1 = power(p1, mod1 - 2, mod1);
  int ip2 = power(p2, mod2 - 2, mod2);
  for (int i = 1; i < N; ++i) {
    pw1[i] = 1LL * pw1[i - 1] * p1 % mod1;
    pw2[i] = 1LL * pw2[i - 1] * p2 % mod2;
    ipw1[i] = 1LL * ipw1[i - 1] * ip1 % mod1;
    ipw2[i] = 1LL * ipw2[i - 1] * ip2 % mod2;
  }
}

array<int, 2> str_hash(string& s) {
  int n = s.size();
  int hs1 = 0;
  for (int i = 0; i < n; ++i) {
    hs1 = (hs1 + (1LL * s[i] * pw1[i]) % mod1) % mod1;
  }
  int hs2 = 0;
  for (int i = 0; i < n; ++i) {
    hs2 = (hs2 + (1LL * s[i] * pw2[i]) % mod2) % mod2;
  }
  return {hs1, hs2};
}

void build(string& s, string& s2) {
  int n = s.size();
  for (int i = 0; i < n; ++i) {
    pref[i][0] = 1LL * s[i] * pw1[i] % mod1;
    if (i) pref[i][0] = (pref[i][0] + pref[i - 1][0]) % mod1;
    pref[i][1] = 1LL * s[i] * pw2[i] % mod2;
    if (i) pref[i][1] = (pref[i][1] + pref[i - 1][1]) % mod2;
  }
  int m = s2.size();
  for (int i = 0; i < m; ++i) {
    pref2[i][0] = 1LL * s2[i] * pw1[i] % mod1;
    if (i) pref2[i][0] = (pref2[i][0] + pref2[i - 1][0]) % mod1;
    pref2[i][1] = 1LL * s2[i] * pw2[i] % mod2;
    if (i) pref2[i][1] = (pref2[i][1] + pref2[i - 1][1]) % mod2;
  }
}

array<int, 2> get_hash(int i, int j) {
  array<int, 2> ans = {0, 0};
  ans[0] = pref[j][0];
  if (i) ans[0] = (pref[j][0] - pref[i - 1][0] + mod1) % mod1;
  ans[0] = 1LL * ans[0] * ipw1[i] % mod1;

  ans[1] = pref[j][1];
  if (i) ans[1] = (pref[j][1] - pref[i - 1][1] + mod2) % mod2;
  ans[1] = 1LL * ans[1] * ipw2[i] % mod2;
  return ans;
}
 
int main() {
  ios_base :: sync_with_stdio(0);
  cin.tie(0);
  
  prec();

  string s1, s2;
  cin >> s1 >> s2;
  build(s1, s2);


  return 0;
}