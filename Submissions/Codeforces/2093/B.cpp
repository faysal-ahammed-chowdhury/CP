#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  string s; cin >> s;
  int n = s.size();
  int ans = 0;
  bool ok = false;
  for (int i = n - 1; i >= 0; i--) {
    if (ok) {
      if (s[i] != '0') ans++;
    }
    else {
      if (s[i] == '0') ans++;
      else ok = true;
    }
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