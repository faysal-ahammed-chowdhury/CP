#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int calc(int x) {
  int ans = __lg(x);
  if (__builtin_popcount(x) > 1) ans++;
  return ans;
}

void solve() {
  int n, q; cin >> n >> q;
  int a[n + 1];
  int ans[n + 1];
  int cnt[n + 1];
  cnt[0] = 0;
  ans[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    ans[i] = ans[i - 1] + calc(a[i]);
    cnt[i] = cnt[i - 1] + (__builtin_popcount(a[i]) == 2 and (a[i] & 1)); 
  }

  while (q--) {
    int l, r; cin >> l >> r;
    int here = ans[r] - ans[l - 1];
    int x = (cnt[r] - cnt[l - 1]);
    here -= (x + 1) / 2;
    cout << here << '\n';
  }
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