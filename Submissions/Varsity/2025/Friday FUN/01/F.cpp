#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int cs;
void solve() {
  ll n; cin >> n;

  cout << "Case " << ++cs << ": ";

  ll extra = n - 3;
  ll ans = 2;
  ans += extra * 2;
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