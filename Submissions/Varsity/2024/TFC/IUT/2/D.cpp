#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, c; cin >> n >> c;
  int a[n + 1], b[n + 1];
  ll sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = -a[i];
    sum += a[i];
  }

  ll prefix[n + 1];
  prefix[0] = 0;
  for (int i = 1; i <= n; i++) {
    prefix[i] = prefix[i - 1] + a[i];
  }

  ll ans1 = INT64_MIN;
  ll low = 0;
  for (int i = 1; i <= n; i++) {
    ans1 = max(ans1, prefix[i] - low);
    low = min(low, prefix[i]);
  }
  ans1 = max(ans1, 0ll);

  if (c > 0) {
    ll x = sum - ans1;
    x += ans1 * c;
    cout << x << '\n';
    return 0;
  }

  prefix[0] = 0;
  for (int i = 1; i <= n; i++) {
    prefix[i] = prefix[i - 1] + b[i];
  }

  ll ans2 = INT64_MIN;
  low = 0;
  for (int i = 1; i <= n; i++) {
    ans2 = max(ans2, prefix[i] - low);
    low = min(low, prefix[i]);
  }
  ans2 = max(ans2, 0ll);
  c = abs(c);
  ll x = sum + ans2;
  x += ans2 * c;
  cout << x << '\n';

  return 0;
}