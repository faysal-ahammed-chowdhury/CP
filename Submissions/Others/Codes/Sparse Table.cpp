#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9, K = 20; // change here
int a[N], tree[N][K];

int log2_floor(unsigned long long i) {
  return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

void build(int n) {
  for (int i = 1; i <= n; i++) {
    tree[i][0] = a[i];
  }
  for (int k = 1; k < K; k++) {
    for (int i = 1; i + (1 << k) - 1 <= n; i++) {
      tree[i][k] = min(tree[i][k - 1], tree[i + (1 << (k - 1))][k - 1]); // change here
    }
  }
}

int query(int l, int r) {
  int k = log2_floor(r - l + 1);
  return min(tree[l][k], tree[r - (1 << k) + 1][k]); // change here
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q; cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  build(n);
  while (q--) {
    int l, r; cin >> l >> r;
    cout << query(l, r) << '\n';
  }

  return 0;
}
// https://cses.fi/problemset/task/1647/