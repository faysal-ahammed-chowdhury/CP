#include <bits/stdc++.h>
using namespace std;

int get_fact(int n) {
  int ans = 1;
  for (int i = 1; i <= n; i++) {
    ans *= i;
  }
  return ans;
}

void solve() {
  string s; getline(cin, s);
  stringstream ss(s);
  map<string, int> mp;
  int tot = 0;
  while (ss >> s) {
    mp[s]++;
    tot++;
  }
  int ans = get_fact(tot);
  for (auto [s, cnt] : mp) {
    ans /= get_fact(cnt);
  }
  cout << "1/" << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  cin.ignore();
  while(t--) {
    solve();
  }

  return 0;
}