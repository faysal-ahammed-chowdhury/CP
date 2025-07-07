#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

int lcm(int a, int b) {
  return (a * b) / __gcd(a, b);
}

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int ans = 1;
  for (int i = n - 1; i >= 1; i--) {
    int gc = __gcd(a[i], a[i + 1]);
    int x = a[i] / gc;
    ans = lcm(ans, x);
  }

  cout << ans << '\n';
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