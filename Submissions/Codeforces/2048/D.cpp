#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, m; cin >> n >> m;
  int a[n + 1], b[m + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }

  int my_rating = a[1];
  int mx_rating = *max_element(a + 1, a + n + 1);

  if (my_rating == mx_rating) {
    for (int k = 1; k <= m; k++) {
      int ans = m / k;
      cout << ans << ' ';
    }
    cout << '\n';
    return;
  }

  sort(a + 1, a + n + 1);
  sort(b + 1, b + m + 1);

  int choto = upper_bound(b + 1, b + m + 1, my_rating) - &b[1];
  int boro = &b[m] - upper_bound(b + 1, b + m + 1, mx_rating) + 1;
  
  int diff[m + 5] = {};
  int idx = -1;
  for (int i = 1; i <= n; i++) {
    if (a[i] > my_rating) {
      idx = i;
      break;
    }
  }

  for (int i = idx; i <= n; i++) {
    auto it = upper_bound(b + 1, b + m + 1, a[i]) - &b[1];
    diff[choto + 1]++;
    diff[it + 1]--;
  }
  for (int i = 1; i <= m; i++) {
    diff[i] += diff[i - 1];
    // cout << diff[i] << ' ';
  }
  // cout << '\n';

  for (int k = 1; k <= m; k++) {
    int cnt = choto + boro;
    ll ans = (cnt / k);
    int baki = cnt % k;
    int st = m - boro - k + 1 + baki;
    // cout << st << '\n';
    for (int j = st; j > choto; j -= k) {
      ans++;
      ans += diff[j];
    }
    cout << ans << ' ';
  }
  cout << '\n';
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