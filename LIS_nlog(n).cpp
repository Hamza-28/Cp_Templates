/*
	In the name of Allah, The Most Gracious and The Most Merciful.

	Glory be to You(Allah)! We have no knowledge except what You have taught us.
	It is you who are the Knowledgeable, the Wise.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> lis;
	for (int i = 0; i < n; ++i) {
		int x; 
		cin >> x;
		if (lis.empty() or lis.back() < x) {
			lis.push_back(x);
		} else {
			int j = lower_bound(lis.begin(), lis.end(), x) - lis.begin();
			lis[j] = x;
		}
	}
	cout << lis.size() << '\n';

	return 0;
}
