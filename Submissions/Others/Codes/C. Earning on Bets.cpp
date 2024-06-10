#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 52;
int n, k[N];

ll lcm(ll a, ll b) {
  return (a * b) / __gcd(a, b);
}

bool ok(ll tot) {
  ll sum = 0;
  for (int i = 1; i <= n; i++) {
    if ((tot + k[i]) / k[i] > 1e9) return false;
    sum += (tot + k[i]) / k[i];
  }
  return tot >= sum;
}

void solve() {
  cin >> n;
  ll lc = 1;
  for (int i = 1; i <= n; i++) {
    cin >> k[i];
    lc = lcm(lc, k[i]);
  }
  if (ok(lc - 1)) {
    for (int i = 1; i <= n; i++) {
      cout << ((lc - 1) + k[i]) / k[i] << ' ';
    }
    cout << '\n';
    return;
  }
  cout << -1 << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}