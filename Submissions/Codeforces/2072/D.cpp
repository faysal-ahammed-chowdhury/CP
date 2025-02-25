#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int l = -1, r = -1, mx = 0;
  for (int i = 1; i <= n; i++) {
    int boro = 0, choto = 0;
    for (int j = i + 1; j <= n; j++) {
      if (a[j] > a[i]) boro++;
      else if (a[j] < a[i]) choto++;

      int here = choto - boro;
      if (here >= mx) {
        mx = here;
        l = i, r = j; 
      }
    }
  }

  if (l == -1 or r == -1) l = 1, r = 1;
  cout << l << ' ' << r << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}