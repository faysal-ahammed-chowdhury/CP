#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e5 + 9, inf = 2e18;
int n, k, a[N];

void solve() {
  cin >> n >> k;
  set<int> se1, se2;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    se1.insert(i);
    se2.insert(i);
  }
  sort(a + 1, a + n + 1);
  int ans1 = 0, ans2 = 0, done1 = 0, done2 = 0, ans3 = inf;

  for (int i = 1; i <= n; i++) {
    if (se1.find(i) == se1.end()) continue;
    for (auto j : se1) {
      if (i >= j) continue;
      if ((a[j] - a[i]) % k == 0) {
        ans1 += (a[j] - a[i]) / k;
        se1.erase(i);
        se1.erase(j);
        done1 += 2;
        break;
      }
    }
  }

  for (int j = 1; j <= n; j++) {
    for (int i = 1; i <= n; i++) {
      se2.insert(i);
    }
    ans2 = 0, done2 = 0;
    for (int i = 1; i <= n; i++) {
      if (i == j) continue;
      if (se2.find(i) == se2.end()) continue;
      for (auto j : se2) {
        if (i >= j) continue;
        if ((a[j] - a[i]) % k == 0) {
          ans2 += (a[j] - a[i]) / k;
          se2.erase(i);
          se2.erase(j);
          done2 += 2;
          break;
        }
      }
    }
    if (ans2 == 14) {
      cout << j << '\n';
      return;
    }
    if (n % 2 == 0 and done2 == n) ans3 = min(ans3, ans2);
    else if (done2 == n - 1) ans3 = min(ans3, ans2);
  }

  int ans = inf;
  if (n % 2 == 0 and done1 == n) ans = min(ans, ans1);
  else if (done1 == n - 1) ans = min(ans, ans1);
  if (n & 1 and ans3 != inf) ans = min(ans, ans3);
  if (ans == inf) ans = -1;

  cout << ans << '\n';
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