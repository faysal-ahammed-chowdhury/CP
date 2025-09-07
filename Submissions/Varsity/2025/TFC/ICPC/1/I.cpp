#include <bits/stdc++.h>
using namespace std;

using ll = long long;

map<int, string, greater<int>> mp;

void solve() {
  int n; cin >> n;
  string ans = "";
  for (auto [x, s] : mp) {
    int cnt = n / x;
    n %= x;
    for (int i = 1; i <= cnt; i++) {
      ans += s;
    }
  }

  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  mp[1000] = "M";
  mp[500] = "D";
  mp[100] = "C";
  mp[50] = "L";
  mp[10] = "X";
  mp[5] = "V";
  mp[1] = "I";

  mp[900] = "CM";
  mp[400] = "CD";
  mp[90] = "XC";
  mp[40] = "XL";
  mp[9] = "IX";
  mp[4] = "IV";

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}