#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 3, M = __bit_width(N) + 1;
int maxTable[N][M], minTable[N][M], a[N];

void buildTable(int n) {
	for (int i = 0; i < n; ++i) {
		maxTable[i][0] = a[i];
		minTable[i][0] = a[i];
	}
	for (int k = 1; k < M; ++k) {
		for (int i = 0; i + (1 << k) <= n; ++i) {
			maxTable[i][k] = max(maxTable[i][k - 1], maxTable[i + (1 << (k - 1))][k - 1]);
			minTable[i][k] = min(minTable[i][k - 1], minTable[i + (1 << (k - 1))][k - 1]);
		}
	}
}

int maxQuery(int i, int j, int n) {
	if (j < 0 or i >= n) return INT32_MIN;
	int k = __bit_width(j - i + 1) - 1;
	return max(maxTable[i][k], maxTable[j - (1 << k) + 1][k]);
}
int minQuery(int i, int j, int n) {
	if (j < 0 or i >= n) return INT32_MAX;
	int k = __bit_width(j - i + 1) - 1;
	return min(minTable[i][k], minTable[j - (1 << k) + 1][k]);
}

int main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);

  

	return 0;
}