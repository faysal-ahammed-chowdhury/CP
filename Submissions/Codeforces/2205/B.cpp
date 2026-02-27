#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

void solve() {
  int n; cin >> n;
  int lim = sqrt(n + 1);
  int ans = 1;
  for (int i = 2; i <= lim; i++) {
    if (n % i == 0) {
      ans *= i;
    }
    while (n % i == 0) {
      n /= i;
    }
  }
  if (n > 1) ans *= n;

  cout << ans << '\n';
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