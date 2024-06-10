#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

void solve() {
  int n, k; cin >> n >> k;
  string s; cin >> s;
  int ans = 0;
  for(int i = 0; i < n; i++) {
    if(s[i] == 'B') {
      ans++;
      for(int j = 1; j < k && i < n; j++) {
        i++;
      }
    }
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}