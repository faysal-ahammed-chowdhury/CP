#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool CHECK(int N, int pos) { return (bool)(N & (1ll << pos)); }
void SET(int &N, int pos) { (N |= (1ll << pos)); }
void CLEAR(int &N, int pos) { (N &= ~(1ll << pos)); }

void solve() {
  int n, x; cin >> n >> x;
  if (n == 1) {
    if (x == 0) cout << -1 << '\n';
    else cout << x << '\n';
    return;
  }
  int cnt = 0;
  for (int k = 0; k < 30; k++) {
    if (CHECK(x, k)) cnt++;
  }
  if (x == 0) {
    if (n % 2 == 0) {
      cout << n << '\n';
      return;
    }
    cout << n - 1 + 4 << '\n';
    return;
  }
  if (x == 1) {
    if (n % 2 == 1) cout << n << '\n';
    else cout << n + 3 << '\n';
    return;
  }

  if (cnt >= n) {
    cout << x << '\n';
    return;
  }

  int need = n - cnt;
  if (need % 2 == 0) {
    cout << x + need << '\n';
    return;
  }
  cout << x + need + 1 << '\n';
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