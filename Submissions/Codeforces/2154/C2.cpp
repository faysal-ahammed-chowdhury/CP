#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 4e5 + 19, inf = 1e18;
vector<int> divs[N];

void sieve() {
  for (int i = 2; i < N; i++) {
    for (int j = i; j < N; j += i) {
      divs[j].push_back(i);
    }
  }
}

void solve() {
  int n; cin >> n;
  int a[n + 1], b[n + 1], even = 0;
  set<int> se;
  bool done = false;
  vector<pair<int, int>> costs;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] != 1 and se.find(a[i]) != se.end()) {
      done = true;
    }
    else se.insert(a[i]);
    even += (a[i] % 2) == 0;
  }

  int mn_even = inf, idx_even;
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    if (a[i] % 2 != 0) {
      costs.push_back({b[i], i});
    }
    else {
      mn_even = min(mn_even, b[i]);
      idx_even = i;
    }
  }

  if (done) {
    cout << 0 << '\n';
    return;
  }

  se.clear();

  for (int i = 1; i <= n; i++) {
    for (auto d : divs[a[i]]) {
      if (se.find(d) != se.end()) {
        cout << 0 << '\n';
        return;
      }
      se.insert(d);
    }
  }

  sort(costs.begin(), costs.end());
  int ans = inf;

  if (even > 0) {
    ans = costs[0].first;
    for (int i = 1; i <= n; i++) {
      if (i == idx_even) continue;
      for (auto d : divs[a[i]]) {
        int rem = d - (a[idx_even] % d);
        // cout << d << ' ' << a[i] << '\n';
        ans = min(ans, rem * b[idx_even]);
      }
    }

    cout << ans << '\n';
    return;
  }

  ans = min(ans, costs[0].first + costs[1].first);
  int idx = costs[0].second;

  for (int i = 1; i <= n; i++) {
    if (i == idx) continue;
    for (auto d : divs[a[i]]) {
      int rem = d - (a[idx] % d);
      // cout << d << ' ' << a[i] << '\n';
      ans = min(ans, rem * b[idx]);
    }
  }

  for (int i = 1; i <= n; i++) {
    for (auto d : divs[a[i] + 1]) {
      if (se.find(d) != se.end()) {
        ans = min(ans, b[i]);
      }
    }
  }

  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  sieve();

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}