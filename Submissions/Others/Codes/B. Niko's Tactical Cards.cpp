#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  int a[n + 1], b[n + 1];
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];

  ll mn_k = 0, mx_k = 0;
  for (int i = 1; i <= n; i++) {
    ll score1 = mn_k - a[i]; 
    ll score2 = mx_k - a[i]; 
    ll score3 = b[i] - mn_k; 
    ll score4 = b[i] - mx_k; 

    mn_k = min({score1, score2, score3, score4});
    mx_k = max({score1, score2, score3, score4});
  }

  cout << mx_k << '\n';
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