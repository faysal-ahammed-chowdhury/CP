#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll k; cin >> k;
  string s = "codeforces";
  map<int, int> mp;
  for (int i = 0; i < 10; i++) mp[i]++;
  ll ans = 1;
  while (ans < k) {
    for (auto &[_, cnt] : mp) {
      if (ans >= k) break;
      ans /= cnt;
      cnt++;
      ans *= cnt; 
    }
  }
  for (int i = 0; i < 10; i++) {
    for (int cnt = 0; cnt < mp[i]; cnt++) {
      cout << s[i];
    }
  }
  cout << '\n';

  return 0;
}