#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

#define int long long
const int INF = 1e18;

int func(int x1, int y1, int x2, int y2) {
  return abs(x1 - x2) + abs(y1 - y2);
}

void solve() {
  int n, k, a, b; cin >> n >> k >> a >> b;
  pair<int, int> arr[n + 1];
  for(int i = 1; i <= n; i++) {
    cin >> arr[i].first >> arr[i].second;
  }
  if(a <= k && b <= k) {
    cout << 0 << '\n';
    return;
  }
  if(a > k && b > k) {
    int ans1 = func(arr[a].first, arr[a].second, arr[b].first, arr[b].second); // direct
    int ans2, d1_min = INF, d2_min = INF;
    for(int i = 1; i <= k; i++) {
      int d1 = func(arr[a].first, arr[a].second, arr[i].first, arr[i].second);
      int d2 = func(arr[i].first, arr[i].second, arr[b].first, arr[b].second);
      d1_min = min(d1_min, d1);
      d2_min = min(d2_min, d2);
    }
    ans2 = d1_min + d2_min;
    int ans = min(ans1, ans2);
    cout << ans << '\n';
    return;
  }
  if(a > k) {
    int ans1 = func(arr[a].first, arr[a].second, arr[b].first, arr[b].second); // direct
    int ans2 = INF;
    for(int i = 1; i <= k; i++) {
      int d = func(arr[i].first, arr[i].second, arr[a].first, arr[a].second);
      ans2 = min(ans2, d);
    }
    int ans = min(ans1, ans2);
    cout << ans << '\n';
  }
  else {
    int ans1 = func(arr[a].first, arr[a].second, arr[b].first, arr[b].second); // direct
    int ans2 = INF;
    for(int i = 1; i <= k; i++) {
      int d = func(arr[i].first, arr[i].second, arr[b].first, arr[b].second);
      ans2 = min(ans2, d);
    }
    int ans = min(ans1, ans2);
    cout << ans << '\n';
  }
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