#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

using i128 = __int128;
const ll inf = 1e9 + 2;
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

void solve() {
  int n, c; cin >> n >> c;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  int ans = 0;
  for (int k = 1; k <= n; k++) {
    if (a[k] > c) break;
    bool ok = true;
    for (int i = k, j = 1; i >= 1; i--, j++) {
      overflow = false;
      int pw = power(2, j - 1);
      if (overflow) {
        ok = false;
        break;
      }
      int x = a[i] * pw;
      if (x > c) {
        ok = false;
        break;
      }
    }

    if (ok) ans = max(ans, k);
  }

  cout << n - ans << '\n';
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