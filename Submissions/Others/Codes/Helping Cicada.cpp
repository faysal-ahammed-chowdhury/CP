#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
bool CHECK(int N, int pos) { return (bool)(N & (1 << pos)); }
void SET(int &N, int pos) { (N |= (1 << pos)); }

ll lcm(int a, int b) {
  return (1ll * a * b) / __gcd(a, b);
}

int cs;
void solve() {
  int n, m; cin >> n >> m;
  int a[m];
  for (int i = 0; i < m; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for (int mask = 0; mask < (1 << m); mask++) {
    int cnt = 0;
    ll lc = 1;
    for (int i = 0; i < m; i++) {
      if (CHECK(mask, i)) {
        lc = lcm(lc, a[i]);
        cnt++;
        if (lc > (1ll << 31)) break;
      }
    }
    if (cnt & 1) ans -= n / lc;
    else ans += n / lc;
  }
  cout << "Case " << ++cs << ": " << ans << '\n';
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