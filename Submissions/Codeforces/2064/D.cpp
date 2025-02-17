#include <bits/stdc++.h>
using namespace std;

bool CHECK(int N, int pos) { return (bool)(N & (1 << pos)); }
void SET(int &N, int pos) { (N |= (1 << pos)); }
const int N = 2e5 + 9, K = 30;
int a[N], msb[N], pref_xor[N], tree[N][K];
int n;

int log2_floor(unsigned long long i) {
  return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

void build(int n) {
  for (int i = 1; i <= n; i++) {
    tree[i][0] = msb[i];
  }
  for (int k = 1; k < K; k++) {
    for (int i = 1; i + (1 << k) - 1 <= n; i++) {
      tree[i][k] = max(tree[i][k - 1], tree[i + (1 << (k - 1))][k - 1]);
    }
  }
}

int query(int l, int r) {
  int k = log2_floor(r - l + 1);
  return max(tree[l][k], tree[r - (1 << k) + 1][k]); 
}

bool ok(int l, int r, int mymsb) {
  return query(l, r) < mymsb;
}

void solve() {
  int q; cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  reverse(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    msb[i] = __lg(a[i]);
    pref_xor[i] = pref_xor[i - 1] ^ a[i];
  }

  build(n);

  while (q--) {
    int x; cin >> x;
    int ans = 0;
    while (true) {
      int tmp = __lg(x ^ pref_xor[ans]);
      int l = ans + 1, r = n, idx = ans;
      while (l <= r) {
        int mid = (l + r) >> 1;
        if (ok(ans + 1, mid, tmp)) {
          idx = mid;
          l = mid + 1;
        }
        else r = mid - 1;
      }
      ans = idx;
      if (ans == n) break;
      int cur = x ^ pref_xor[ans];
      if (a[ans + 1] <= cur) ans++;
      else break;
    }
    cout << ans << ' ';
  }
  cout << '\n';
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