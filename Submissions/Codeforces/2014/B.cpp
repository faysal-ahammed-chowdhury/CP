#include <bits/stdc++.h>
using namespace std;

#define int long long

int get(int n) {
  return (n + 1) / 2;
}

void solve() {
  int n, k; cin >> n >> k;
  int l = n - k + 1, r = n;
  int cnt = get(r) - get(l - 1);
  if (cnt & 1) cout << "NO\n";
  else cout << "YES\n";
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