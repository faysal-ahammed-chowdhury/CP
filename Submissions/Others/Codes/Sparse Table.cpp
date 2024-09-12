#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9, K = 25; // change here
int st[K + 1][N], n;
vector<int> a;

int log2_floor(unsigned long long i) {
  return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

void build() { // 0 index
  copy(a.begin(), a.end(), st[0]);
  for (int i = 1; i <= K; i++) {
    for (int j = 0; j + (1 << i) <= n; j++) {
      st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]); //  change here
    }
  }
}

int query(int l, int r) { // 0 index
  int i = log2_floor(r - l + 1);
  return min(st[i][l], st[i][r - (1 << i) + 1]); // change here
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  a.resize(n);
  for (auto &x : a) {
    cin >> x;
  }
  build();

  return 0;
}