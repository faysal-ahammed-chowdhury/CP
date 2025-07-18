#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

int lcm(int a, int b) {
  return (a * b) / __gcd(a, b);
}

void solve() {
  int n; cin >> n;
  int a[n + 1], b[n + 1], c[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    c[i] = lcm(a[i], b[i]);
  }
  int pref = 0;
  for (int i = 1; i <= n; i++) {
    pref = __gcd(pref, c[i]);
    if (a[i] != pref) {
      cout << "NO\n";
      return;
    }
  }

  int suff = 0;
  for (int i = n; i >= 1; i--) {
    suff = __gcd(suff, c[i]);
    if (b[i] != suff) {
      cout << "NO\n";
      return;
    }
  }

  cout << "YES\n";
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