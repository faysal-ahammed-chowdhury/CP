#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  string s; cin >> s;
  int n = s.size();
  s = '.' + s;
  int ans = 0;
  for (int i = 1; i + 3 <= n; i++) {
    if (s[i] == '1' and s[i + 1] == '1' and s[i + 2] == '0' and s[i + 3] == '0') {
      ans++;
    }
  }

  int q; cin >> q;
  while (q--) {
    int i; cin >> i;
    char c; cin >> c;
    if (s[i] != c) {
      if (s[i] == '1') {
        if (i + 3 <= n and s[i + 1] == '1' and s[i + 2] == '0' and s[i + 3] == '0') {
          ans--;
        }
        else if (i - 1 >= 1 and i + 2 <= n and s[i - 1] == '1' and s[i + 1] == '0' and s[i + 2] == '0') {
          ans--;
        }

        if (i - 2 >= 1 and i + 1 <= n and s[i - 2] == '1' and s[i - 1] == '1' and s[i + 1] == '0') {
          ans++;
        }
        if (i - 3 >= 1 and s[i - 3] == '1' and s[i - 2] == '1' and s[i - 1] == '0') {
          ans++;
        }
        s[i] = c;
      }
      else {
        if (i - 2 >= 1 and i + 1 <= n and s[i - 2] == '1' and s[i - 1] == '1' and s[i + 1] == '0') {
          ans--;
        }
        if (i - 3 >= 1 and s[i - 3] == '1' and s[i - 2] == '1' and s[i - 1] == '0') {
          ans--;
        }

        if (i + 3 <= n and s[i + 1] == '1' and s[i + 2] == '0' and s[i + 3] == '0') {
          ans++;
        }
        else if (i - 1 >= 1 and i + 2 <= n and s[i - 1] == '1' and s[i + 1] == '0' and s[i + 2] == '0') {
          ans++;
        }
        s[i] = c;
      }
    }

    if (ans > 0) cout << "YES\n";
    else cout << "NO\n";
  }
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