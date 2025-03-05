#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9;
int n, a[N], pref[N];
ll l, r;

int f(ll x) {
  if (x <= n) return pref[x];
  if (x & 1) {
    return pref[n];
  }
  return f(x / 2) ^ f(x - 1);
}

void solve() {
  cin >> n >> l >> r;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pref[i] = pref[i - 1] ^ a[i];
  }

  if (r <= n) {
    cout << a[r] << '\n';
    return;
  }

  if (n % 2 == 0) {
    a[n + 1] = pref[(n + 1) / 2];
    n++;

    for (int i = 1; i <= n; i++) {
      pref[i] = pref[i - 1] ^ a[i];
    }
  }

  cout << f(r / 2) << '\n';
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