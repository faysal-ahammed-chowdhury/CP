#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  if (s.front() == '1' or s.back() == '1') {
    cout << "YES\n";
    return;
  }

  for (int i = 1; i < n; i++) {
    if (s[i] == s[i - 1] and s[i] == '1') {
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
  while (t--) {
    solve();
  }

  return 0;
}