#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  string s; cin >> s;
  string consec = "";
  consec += s[0];
  map<char, int> mp;
  for (int i = 1; i < n; i++) {
    if (s[i] == consec.back()) {
      consec += s[i];
    }
    else {
      mp[consec.back()] = max((int)consec.size(), mp[consec.back()]);
      consec = s[i];
    }
  }
  mp[consec.back()] = max((int)consec.size(), mp[consec.back()]);

  int ans = 0;
  for (auto [_, cnt] : mp) {
    ans += cnt;
  }
  cout << ans << '\n';

  return 0;
}