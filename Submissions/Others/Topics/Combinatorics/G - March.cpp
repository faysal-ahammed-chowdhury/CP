#include <bits/stdc++.h>
using namespace std;

#define int long long
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  map<char, int> mp;
  for (int i = 1; i <= n; i++) {
    string s; cin >> s;
    mp[s[0]]++;
  }

  string s = "MARCH";
  int ans = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = i + 1; j < 5; j++) {
      for (int k = j + 1; k < 5; k++) {
        ans += mp[s[i]] * mp[s[j]] * mp[s[k]];
      }
    }
  }

  cout << ans << '\n';

  return 0;
}