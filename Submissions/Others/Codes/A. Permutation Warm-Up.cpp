#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  int ans = 0;
  for (int i = 1, j = n; i <= n; i++, j--) {
    ans += abs(i - j);
  }
  ans /= 2;
  ans++;
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