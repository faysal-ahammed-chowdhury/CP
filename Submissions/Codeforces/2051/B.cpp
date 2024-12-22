#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, a, b, c; cin >> n >> a >> b >> c;
  int sum = a + b + c;

  int ans = n / sum;
  n %= sum;

  ans *= 3;

  if (n > 0) {
    ans++;
    n -= a;
  }
  if (n > 0) {
    ans++;
    n -= b;
  }
  if (n > 0) {
    ans++;
    n -= c;
  }

  cout << ans << '\n';
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