#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  if (n == 2) {
    cout << "2\n";
  }
  else if (n == 3) {
    cout << "3\n";
  }
  else if (n % 2 == 0) {
    cout << 0 << '\n';
  }
  else if (n % 3 == 0) {
    int cnt = n / 3;
    if (cnt & 1) cout << 1 << '\n';
    else cout << 0 << '\n';
  }
  else cout << "1\n";
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