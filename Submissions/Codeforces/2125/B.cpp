#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 

void solve() {
  int a, b, k; cin >> a >> b >> k;
  if (a == b) cout << 1 << '\n';
  else {
    int x = __gcd(a, b);
    a /= x;
    b /= x;

    if (a <= k and b <= k) {
      cout << 1 << '\n';
      return;
    }

    cout << 2 << '\n';
  }
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