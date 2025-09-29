#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n;
string s; 

ll f(char c1, char c2) {
  int pref[n + 1], suff[n + 2];
  memset(pref, 0, sizeof pref);
  memset(suff, 0, sizeof suff);

  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + (s[i] == c2);
  }
  for (int i = n; i >= 1; i--) {
    suff[i] = suff[i + 1] + (s[i] == c2);
  }

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == c1) {
      ans += min(pref[i], suff[i]);
      // cout << "here: " << i << '\n';
      // cout << pref[i] << ' ' << suff[i] << '\n';
    }
  }

  return ans;
}

void solve() {
  cin >> n;
  cin >> s;
  s = '.' + s;

  ll ans = min(f('a', 'b'), f('b', 'a'));
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