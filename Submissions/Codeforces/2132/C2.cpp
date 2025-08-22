#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int inf = 1e18;
pair<int, int> cnt_cost[22];

int power(int a, int b) {
  int ans = 1;
  for (int i = 0; i < b; i++) {
    ans *= a;
    if (ans > inf) {
      return -1;
    }
  }
  return ans;
}

int cost(int x) {
  int ans = power(3, x + 1);
  ans += x * power(3, x - 1);
  return ans;
}

void solve() {
  int n, k; cin >> n >> k;
  int deal = 0;
  vector<int> v;
  for (int i = 20; i >= 0; i--) {
    int koybar = n / cnt_cost[i].first;
    n -= koybar * cnt_cost[i].first;

    v.push_back(koybar);

    deal += koybar;
  }

  if (deal > k) {
    cout << -1 << '\n';
    return;
  }

  k -= deal;

  for (int i = 1; i < (int)v.size(); i++) {
    int cnt = v[i - 1];
    int possible = k / 2;
    int mn = min(cnt, possible);
    k -= mn * 2;
    v[i - 1] -= mn;
    v[i] += mn * 3;
  }

  int cur = 20;
  int ans = 0;
  for (auto x : v) {
    // cout << x << '\n';
    ans += cnt_cost[cur].second * x;
    cur--;
  }

  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i <= 20; i++) {
    int a  = power(3, i);
    int b = cost(i);
    // double c = b / double(a);
    // cout << a << ' ' << b << ' ' << c << '\n';

    cnt_cost[i] = {a, b};
  }

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}