#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 2e5 + 9, K = 20; 
int a[N], tree[N][K], pref[N];

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
  if (l > r) return 0;
  int k = log2_floor(r - l + 1);
  return max(tree[l][k], tree[r - (1 << k) + 1][k]); // change here
}

void solve() {
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pref[i] = pref[i - 1] + a[i];
  }

  build(n);

  for (int i = 1; i <= n; i++) {
    int l = 1, r = n - i + 1;
    int mx = query(l, r);
    // cout << mx << '\n';
    int ans = 0;
    if (r + 1 <= n) ans = pref[n] - pref[r];
    ans += mx;
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