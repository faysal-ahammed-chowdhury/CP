#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int N = 2e5 + 9, K = 20, inf = 1e18;
int a[N], b[N], n;

int tree[N][K];

int log2_floor(unsigned long long i) {
  return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

void build(int n) {
  for (int i = 1; i <= n; i++) {
    tree[i][0] = a[i];
  }
  for (int k = 1; k < K; k++) {
    for (int i = 1; i + (1 << k) - 1 <= n; i++) {
      tree[i][k] = max(tree[i][k - 1], tree[i + (1 << (k - 1))][k - 1]); // change here
    }
  }
}

int query(int l, int r) {
  int k = log2_floor(r - l + 1);
  return max(tree[l][k], tree[r - (1 << k) + 1][k]); // change here
}

bool ok(int from, int to, int val) {
  return query(from, to) >= val;
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }

  build(n);

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    int x = a[i], y = b[i];
    int mx = max(x, y);

    int l = 1, r = i - 1, idx = -1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (ok(mid, i - 1, mx)) {
        idx = mid;
        l = mid + 1;
      }
      else {
        r = mid - 1;
      }
    }

    if (idx == -1) idx = 0;

    ans += 1ll * idx * (n - i + 1);

    if (x == y) {
      ans += 1ll * (i - idx) * (n - i + 1);
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