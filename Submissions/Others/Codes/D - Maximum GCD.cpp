#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int a = (n & 1) ? n - 1 : n;
  int b = a / 2;
  cout << b << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}