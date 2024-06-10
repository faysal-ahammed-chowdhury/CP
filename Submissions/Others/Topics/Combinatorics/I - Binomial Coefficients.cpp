#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  a[0] = 0;
  sort(a + 1, a + n + 1);
  int last = a[n];
  int half = last / 2;
  auto it = lower_bound(a + 1, a + n + 1, half);
  auto it2 = (it - 1);
  int ans;
  int x = last - *it2;
  if (x <= *it) {
    ans = *it2;
  }
  else {
    ans = *it;
  }
  cout << last << ' ' << ans << '\n'; 

  return 0;
}