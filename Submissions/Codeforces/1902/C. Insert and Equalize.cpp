#include <bits/stdc++.h>
using namespace std;

#define int long long
void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for (auto &x : a) {
    cin >> x;
  }
  if (n == 1) {
    cout << 1 << '\n';
    return;
  }
  sort(a.begin(), a.end());
  int diff = 0;
  for (int i = 1; i < n; i++) {
    diff = __gcd(diff, a[i] - a[i - 1]);
  }
  int ans = 0;
  int largest = a.back();
  for (auto x : a) {
    ans += (largest - x) / diff;
  }
  int last_elem = largest;
  int cost1 = n, cost2 = n;
  for (int i = n - 1; i >= 0; i--) {
    if (i == 0) {
      last_elem = a[i] - diff;
      break;
    }
    if (a[i] - a[i - 1] > diff) {
      last_elem = a[i] - diff;
      break;
    }
  }
  cost2 = (largest - last_elem) / diff;
  ans += min(cost1, cost2);
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}