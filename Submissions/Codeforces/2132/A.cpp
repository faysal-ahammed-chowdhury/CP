#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  int m; cin >> m;
  string t; cin >> t;
  string x; cin >> x;
  for (int i = 0; i < m; i++) {
    if (x[i] == 'V') {
      s = t[i] + s;
    }
    else {
      s += t[i];
    }
  }

  cout << s << '\n';
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