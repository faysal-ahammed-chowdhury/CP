#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, k; cin >> n >> k;
  string s; cin >> s;
  s = '.' + s;

  int i = 1, j = n;
  while (i < j) {
    if (s[i] < s[j]) {
      cout << "YES\n";
      return;
    }
    else if (s[i] > s[j]) {
      if (k > 0) cout << "YES\n";
      else cout << "NO\n";
      return;
    }
    i++, j--;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (s[j] < s[i] and k > 0) {
        cout << "YES\n";
        return;
      }
    }
  }

  cout << "NO\n";
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