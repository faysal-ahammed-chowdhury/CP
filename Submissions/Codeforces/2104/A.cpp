#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

void solve() {
  int a, b, c; cin >> a >> b >> c;
  int tot = a + b + c;
  if (tot % 3 != 0) {
    cout << "NO\n";
    return;
  }
  int avg = tot / 3;
  if (a <= avg and b <= avg) {
    cout << "YES\n";
    return;
  }
  cout << "NO\n";
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