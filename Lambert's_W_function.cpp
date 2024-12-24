/*
  In the name of Allah, The Most Gracious and The Most Merciful.

  Glory be to You(Allah)! We have no knowledge except what You have taught us.
  It is you who are the Knowledgeable, the Wise.
*/

#include <bits/stdc++.h>
using namespace std;

const double e = exp(1);

// Lambert's W function
// W(a * e ^ a) = a
double W(double x) {
  double l = 0, r = log2(x);
  for (int i = 0; i < 100; ++i) {
    double mid = (l + r) / 2;
    if (mid * exp(mid) > x) {
      r = mid;
    } else {
      l = mid;
    }
  }
  return l;
}

void solve() {
  cout << fixed << setprecision(10) << exp(W(log(25))) << "\n";
}

int main() {
  ios_base :: sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
