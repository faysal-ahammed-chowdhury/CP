#include <bits/stdc++.h>
using namespace std;

const double inf = (double)1e18;

int cs = 0;
void solve() {
  int n; cin >> n;
  int a[n + 1];
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n);
  cout << "Case #" << ++cs << ": ";
  cout << fixed << setprecision(10);
  if(n % 2 == 0) {
    double ans = abs(((a[1] + a[2]) / 2.0) - ((a[n - 1] + a[n]) / 2.0));
    cout << ans << '\n';
    return;
  }

  int min_start = -1, min_end = -1;
  double mn = inf, pos = -1;
  for(int i = 1; i < n; i += 2) {
    double calc = (a[i] + a[i + 2]) / 2.0;
    double dis = max(calc - a[i], a[i + 2] - calc);
    if(dis < mn) {
      min_start = i;
      min_end = i + 2;
      mn = dis;
      pos = calc;
    }
  }

  vector<pair<int, int>> v;
  for(int i = 1; i < n; i += 2) {
    double calc = (a[i] + a[i + 2]) / 2.0;
    double dis = max(calc - a[i], a[i + 2] - calc);
    if(dis == mn) {
      v.push_back({i, i + 2});
    }
  }

  bool flag = false, first = false, last = false;
  for(auto i: v) {
    if(i.first != 1 and i.second != n) {
      flag = true;
    }
    if(i.first == 1) {
      first = true;
    }
    if(i.second == n) {
      last = true;
    }
  }

  if(flag) {
    double ans = abs((a[1] + a[2]) / 2.0 - (a[n - 1] + a[n]) / 2.0);
    cout << ans << '\n';
    return;
  }
  if(first and !last) {
    double ans = abs((a[1] + a[3]) / 2.0 - (a[n - 1] + a[n]) / 2.0);
    cout << ans << '\n';
    return;
  }
  if(!first and last) {
    double ans = abs((a[1] + a[2]) / 2.0 - (a[n - 2] + a[n]) / 2.0);
    cout << ans << '\n';
    return;
  }
  double ans = abs((a[1] + a[3]) / 2.0 - (a[n - 1] + a[n]) / 2.0);
  ans = min(ans, abs((a[1] + a[2]) / 2.0 - (a[n - 2] + a[n]) / 2.0));
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}