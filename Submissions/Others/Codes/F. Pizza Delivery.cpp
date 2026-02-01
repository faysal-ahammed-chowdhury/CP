#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 2e5 + 9, inf = 1e18;
int n, x[N], y[N], mn[N], mx[N];
map<int, int> mp;
int to;
ll dp[N][2];

ll f(int i, bool last_mn) {
  if (i > to) return 0;

  int curx = mp[i];
  int lastx = mp[i - 1];

  ll &ans = dp[i][last_mn];
  if (ans != -1) return ans;
  ans = inf;
  if (i == 1) {
    ans = min(ans, (mx[i] - mn[i]) + f(i + 1, true));
    ans = min(ans, (mx[i] - mn[i]) + f(i + 1, false));
  }
  else {
    int cost = (curx - lastx) + (mx[i] - mn[i]);
    int lasty = last_mn ? mn[i - 1] : mx[i - 1];
    ans = min(ans, cost + abs(lasty - mx[i]) + f(i + 1, true));
    ans = min(ans, cost + abs(lasty - mn[i]) + f(i + 1, false));
  }

  return ans;
}

void solve() {
  mp.clear();
  cin >> n >> x[1] >> y[1] >> x[n + 2] >> y[n + 2];
  n += 2;
  mn[1] = inf, mn[n] = inf;
  mx[1] = inf, mn[n] = -inf;
  for (int i = 2; i < n; i++) {
    cin >> x[i];
  }
  vector<int> v;
  for (int i = 1; i <= n; i++) {
    v.push_back(x[i]);
    mn[i] = inf;
    mx[i] = -inf;
    dp[i][0] = -1;
    dp[i][1] = -1;
  }
  for (int i = 2; i < n; i++) {
    cin >> y[i];
  }

  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
  to = v.size();

  for (int i = 1; i <= n; i++) {
    int val = lower_bound(v.begin(), v.end(), x[i]) - v.begin() + 1;
    mp[val] = x[i];
    mn[val] = min(mn[val], y[i]);
    mx[val] = max(mx[val], y[i]);
  }

  cout << f(1, false) << '\n';
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