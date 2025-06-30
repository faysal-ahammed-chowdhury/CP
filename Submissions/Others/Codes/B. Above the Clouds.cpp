#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  s = '.' + s;
  map<char, int> mp;
  for (int i = 1; i < n; i++) {
    mp[s[i]]++;
    if (mp[s[i]] >= 2) {
      cout << "YES\n";
      return;
    }
  }

  mp.clear();
  for (int i = n; i > 1; i--) {
    mp[s[i]]++;
    if (mp[s[i]] >= 2) {
      cout << "YES\n";
      return;
    }
  }

  cout << "NO\n";
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