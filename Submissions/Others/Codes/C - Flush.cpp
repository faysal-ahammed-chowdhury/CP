#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e5 + 9;
ll a[N];
ll pref[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q; cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + a[i];
  }

  while (q--) {
    ll b; cin >> b;
    auto it = lower_bound(a + 1, a + n + 1, b);
    --it;
    int idx = it - a;
    ll x = pref[idx];
    int ase = n - idx;
    if (ase == 0) {
      cout << -1 << '\n';
    }
    else {
      x += 1ll * ase * (b - 1);
      x++;
      cout << x << '\n';
    }
  }

  return 0;
}