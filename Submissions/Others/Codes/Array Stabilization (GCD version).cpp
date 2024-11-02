#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9, K = 20; 
int a[N], tree[N][K], n;

int log2_floor(unsigned long long i) {
  return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

void build(int n) {
  for (int i = 1; i <= n; i++) {
    tree[i][0] = a[i];
  }
  for (int k = 1; k < K; k++) {
    for (int i = 1; i + (1 << k) - 1 <= n; i++) {
      tree[i][k] = __gcd(tree[i][k - 1], tree[i + (1 << (k - 1))][k - 1]); 
    }
  }
}

int query(int l, int r) {
  int k = log2_floor(r - l + 1);
  return __gcd(tree[l][k], tree[r - (1 << k) + 1][k]); 
}

bool ok(int x, int gc) {
  for (int i = 1; i <= n; i++) {
    int g = query(i, min(n, i + x));
    if (i + x > n) {
      g = __gcd(g, query(1, (i + x) - n));
    }
    if (g != gc) return false;
  }
  return true;
}

void solve() {
  cin >> n;
  int gc = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    gc = __gcd(gc, a[i]);
  }
  build(n + 1);
  int l = 0, r = n - 1, ans = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (ok(mid, gc)) {
      ans = mid;
      r = mid - 1;
    }
    else {
      l = mid + 1;
    }
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}