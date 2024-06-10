#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  map<int, vector<char>> mp;
  for (char c = 'a'; c <= 'z'; c++) {
    mp[0].push_back(c);
  }

  string s = "";
  for (int i = 1; i <= n; i++) {
    char c = mp[a[i]].back();
    mp[a[i]].pop_back();
    mp[a[i] + 1].push_back(c);
    s += c;
  }
  cout << s << '\n';
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