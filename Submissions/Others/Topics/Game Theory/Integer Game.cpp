#include <bits/stdc++.h>
using namespace std;

int cs;
void solve() {
  string s; cin >> s;
  int sum = 0, zero = 0, one = 0, two = 0;
  for (auto c : s) {
    int x = c - '0';
    sum += c;
    sum %= 3;

    zero += (x % 3) == 0;
    one += (x % 3) == 1;
    two += (x % 3) == 2;
  }
  cout << "Case " << ++cs << ": ";
  if (sum == 0) {
    if (zero & 1) cout << "S\n";
    else cout << "T\n";
  }
  else if (sum == 1) {
    if (one == 0) {
      cout << "T\n";
      return;
    }
    if (zero & 1) cout << "T\n";
    else cout << "S\n";
  }
  else if (sum == 2) {
    if (two == 0) {
      cout << "T\n";
      return;
    }
    if (zero & 1) cout << "T\n";
    else cout << "S\n";
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