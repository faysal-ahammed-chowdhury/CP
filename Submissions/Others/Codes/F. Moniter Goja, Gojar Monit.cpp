#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using i128 = __int128;
const int N = 65;
const ll inf = 1e18;
ll a[N][N];
bool overflow;

ll power(int a, int b) {
  i128 ans = 1;
  for (int i = 0; i < b; i++) {
    ans *= a;
    if (ans > inf) {
      overflow = true;
      return -1;
    }
  }
  return ans;
}

void prec() {
  for (int x = 1; x <= 60; x++) {
    for (int y = 1; y <= 60; y++) {
      overflow = false;
      ll ans = power(x, y);
      if (overflow) ans = inf + 1;
      a[x][y] = ans;
    }
  }
}

void solve() {
  ll k; cin >> k;
  for (int x = 2; x <= 60; x++) {
    for (int y = 2; y <= 60; y++) {
      ll first = a[x][y], second = a[y][x];
      if (((__int128)first + second) > inf) continue;
      if (first + second == k) {
        cout << x << ' ' << y << '\n';
        return;
      }
    }
  }
  cout << 1 << ' ' << k - 1 << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  prec();

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}