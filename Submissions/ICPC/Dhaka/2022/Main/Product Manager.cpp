#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int cs;
void solve() {
  int n, k; cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
  }
  ll ans = 1;
  for (int i = 1; i <= n; i++) {
    ans = ans * i;
  }
  cout << "Case " << ++cs << ": " << ans << '\n'; 
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