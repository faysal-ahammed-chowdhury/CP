#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 9;
int n, q, a[N];
ll psum[N];

ll get(int i, int cnt) {
  if (i + cnt - 1 <= n) {
    return psum[i + cnt - 1] - psum[i - 1];
  }
  else {
    int extra = (i + cnt - 1) - n;
    return (psum[n] - psum[i - 1]) + psum[extra];
  }
}

ll f(ll r) {
  int extra = r % n;
  int tot = r / n;
  ll ans = psum[n] * tot;
  if (extra) {
    int i = (r / n) + 1;
    ans += get(i, extra);
  }
  return ans;
}

void solve() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    psum[i] = psum[i - 1] + a[i];
  }
  while (q--) {
    ll l, r; cin >> l >> r;
    cout << f(r) - f(l - 1) << '\n';
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