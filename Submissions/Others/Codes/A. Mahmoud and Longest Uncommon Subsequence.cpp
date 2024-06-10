#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string a, b; cin >> a >> b;
  if (a == b) {
    cout << -1 << '\n';
  }
  else {
    cout << max(a.size(), b.size()) << '\n';
  }

  return 0;
}