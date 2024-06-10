#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int curr = 1;
  for(int i = 1; i <= n; i++) {
    cout << curr << ' ';
    curr += 2;
  }
  cout << '\n';
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