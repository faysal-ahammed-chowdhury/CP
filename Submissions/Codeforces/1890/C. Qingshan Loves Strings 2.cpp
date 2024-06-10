#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  string s; cin >> s;

  if (n & 1) {
    cout << -1 << '\n';
    return;
  }

  s = 'a' + s;

  vector<int> v;
  int op = 0;
  for (int i = 1; i <= n / 2; i++) {
    if (op >= 300) break;
    if (s[i] == s[n - i + 1]) {
      int k;
      if (s[i] == '1') {
        k = i - 1;
        v.push_back(k);
      }
      else {
        k = n - i + 1;
        v.push_back(k);
      }
      string s2 = "";
      for (int j = 0; j <= n; j++) {
        s2 += s[j];
        if (j == k) {
          s2 += "01";
        }
      }
      s = s2;
      n += 2, op++;
    }
  }

  for (int i = 1; i <= n / 2; i++) {
    if (s[i] == s[n - i + 1]) {
      cout << -1 << '\n';
      return;
    }
  }

  cout << v.size() << "\n";
  for (auto x : v) {
    cout << x << ' ';
  }
  cout << '\n';
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