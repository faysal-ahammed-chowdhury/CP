#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, k; cin >> n >> k;
  string s; cin >> s;
  s = '.' + s;
  k--;

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '0') continue;
    int one = 0;
    int l = max(1, i - k), r = i - 1;
    for (int j = l; j <= r; j++) {
      one += s[j] == '1';
    }

    ans += one == 0;
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