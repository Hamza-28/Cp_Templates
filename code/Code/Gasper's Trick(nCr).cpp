vector<int> masks;
void gen(int n, int r) {
  int mask = (1 << r) - 1;
  do {
    masks.push_back(mask);
    int x = mask & -mask;
    int y = mask + x;
    mask = ((mask & ~y) / x >> 1) | y;
  } while (mask < (1 << n));
}
