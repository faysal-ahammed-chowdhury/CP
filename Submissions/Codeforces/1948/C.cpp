#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  char a[3][n + 1];
  for (int i = 1; i <= n; i++) {
    char c; cin >> c;
    a[1][i] = c;
  }
  for (int i = 1; i <= n; i++) {
    char c; cin >> c;
    a[2][i] = c;
  }

  if (a[2][n - 1] == '<') {
    cout << "NO\n";
    return;
  }

  bool niche = false;
  for (int i = 1; i <= n;) {
    if (i == n and niche) {
      cout << "YES\n";
      return;
    }
    if (!niche) {
      if (a[2][i] == '>') {
        niche = true;
        i++;
      }
      else if (a[1][i + 1] == '>') {
        i += 2;
      }
      else {
        break;
      }
    }
    else {
      if (a[2][i + 1] == '>') {
        i += 2;
      }
      else if (a[1][i] == '>') {
        niche = false;
        i++;
      }
      else {
        break;
      }
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