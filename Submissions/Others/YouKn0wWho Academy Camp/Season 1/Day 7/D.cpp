#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s1, s2; cin >> s1 >> s2;
  map<char, int> mp;
  for (auto c : s2) {
    mp[c]++;
  }

  int ans = 0;
  for (auto c : s1) {
    if (mp.find(c) == mp.end()) {
      break;
    }
    else if (mp[c] != 0) {
      mp[c]--;
      ans++;
    }
    else {
      mp.erase(c);
      break;
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