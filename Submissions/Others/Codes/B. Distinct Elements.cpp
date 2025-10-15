#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

void solve() {
  int n; cin >> n;
  int b[n + 1], a[n + 1];
  int cur = 1;
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    if (i > 1) {
      int extra = b[i] - b[i - 1];
      if (extra == i) a[i] = cur++;
      else {
        a[i] = a[i - extra];
      }
    }
    else {
      a[i] = cur++;
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << a[i] << ' ';
  }
  cout << '\n';
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