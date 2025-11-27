#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9, K = 20;
int n, a[N], tree[N][K];

int log2_floor(unsigned long long i) {
  return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

void build(int n) {
  for (int i = 1; i <= n; i++) {
    tree[i][0] = a[i];
  }
  for (int k = 1; k < K; k++) {
    for (int i = 1; i + (1 << k) - 1 <= n; i++) {
      tree[i][k] = min(tree[i][k - 1], tree[i + (1 << (k - 1))][k - 1]); 
    }
  }
}

int query(int l, int r) {
  int k = log2_floor(r - l + 1);
  return min(tree[l][k], tree[r - (1 << k) + 1][k]); 
}

bool ok(int idx, int val) {
  int x = query(1, idx);
  return x <= val;
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  build(n);
  int ok_idx = n;
  for (int i = n; i >= ok_idx; i--) {
    if (ok_idx - 1 < 1) continue;
    int l = 1, r = ok_idx - 1, idx = -1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (ok(mid, a[i])) {
        idx = mid;
        r = mid - 1;
      }
      else {
        l = mid + 1;
      }
    }

    if (idx == -1) continue;
    ok_idx = idx;
  }

  if (ok_idx == 1) cout << "YES\n";
  else cout << "NO\n";
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