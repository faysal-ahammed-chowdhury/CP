#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  string s; cin >> s;
  int n = s.size();
  s = '.' + s;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    cnt += s[i] == 'Y';
  }
  if (cnt > 1) cout << "NO\n";
  else cout << "YES\n";
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