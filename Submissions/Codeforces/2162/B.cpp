#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  s = '#' + s;
  vector<int> v;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '0') v.push_back(i);
  }

  cout << v.size() << '\n';
  for (auto x : v) {
    cout << x << ' ';
  }
  cout << '\n';
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