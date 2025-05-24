#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  int first_odd = -1;
  int first_even = -1;
  int last_odd = -1;
  int last_even = -1;
  for (int i = 1; i <= n; i++) {
    if (a[i] % 2 == 0) {
      if (first_even == -1) first_even = i;
      last_even = i;
    }
    else {
      if (first_odd == -1) first_odd = i;
      last_odd = i;
    }
  }

  int ans1 = (first_odd - 1) + (n - last_odd);
  int ans2 = (first_even - 1) + (n - last_even);
  cout << min(ans1, ans2) << '\n';
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