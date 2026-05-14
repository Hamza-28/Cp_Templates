const int N = 1e7 + 3;
vector<int> pr;
int spf[N];

for (int i = 2; i < N; ++i) {
  if (spf[i] == 0) {
    spf[i] = i;
    pr.push_back(i);
  }
  for (int j = 0; i * pr[j] < N; ++j) {
    spf[i * pr[j]] = pr[j];
    if (pr[j] == spf[i]) {
      break;
    }
  }
}
