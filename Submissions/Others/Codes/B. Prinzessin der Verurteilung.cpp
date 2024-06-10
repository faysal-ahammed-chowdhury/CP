#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  string s; cin >> s;

  for (char i = 'a'; i <= 'z'; i++) {
    if (s.find(i) == -1) {
      cout << i << '\n';
      return;
    }
  }

  for (char i = 'a'; i <= 'z'; i++) {
    for (char j = 'a'; j <= 'z'; j++) {
      string x; x += i; x += j;
      if (s.find(x) == -1) {
        cout << x << '\n';
        return;
      }
    }
  }

  for (char i = 'a'; i <= 'z'; i++) {
    for (char j = 'a'; j <= 'z'; j++) {
      for (char k = 'a'; k <= 'z'; k++) {
        string x; x += i; x += j; x += k;
        if (s.find(x) == -1) {
          cout << x << '\n';
          return;
        }
      }
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}