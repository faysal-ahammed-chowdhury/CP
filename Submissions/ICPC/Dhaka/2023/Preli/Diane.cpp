#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  if (n <= 26) {
    for (int i = 0; i < n; i++) {
      cout << char(i + 'a');
    }
    cout << '\n';
    return;
  }
  int half = n / 2;
  for (int i = 1; i <= half; i++) cout << 'a';
  if (n & 1) cout << "bc";
  else cout << "b";
  for (int i = 1; i <= half - 1; i++) cout << 'a';
  cout << '\n';
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