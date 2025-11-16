#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

int a, b, n;

void solve() {
  cin >> a >> b >> n;
  if (b == a) {
    cout << 1 << '\n';
    return;
  }
  if (b * n <= a) cout << 1 << '\n';
  else cout << 2 << '\n';
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