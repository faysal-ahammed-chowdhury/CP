#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

void solve() {
  int n; cin >> n;
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    sum += max(1ll, x);
  }

  cout << sum << '\n';
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