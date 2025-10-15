#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 2e5 + 9, inf = 1e18;
int n, a[N];
map<int, int> mp;
int dp[N][7];

int f(int i, int start_state) {
  if (i > mp[start_state]) return 0;
  int &ans = dp[i][start_state];
  if (ans != -1) return ans;
  ans = inf;
  if (i + 1 <= mp[start_state]) ans = min(ans, abs(a[i] - a[i + 1]) + f(i + 2, start_state));
  if (i + 2 <= mp[start_state]) {
    vector<int> v;
    v.push_back(a[i]);
    v.push_back(a[i + 1]);
    v.push_back(a[i + 2]);
    sort(v.begin(), v.end());
    int x = abs(v[1] - v[0]) + abs(v[1] - v[2]);
    ans = min(ans, x + f(i + 3, start_state));
  }

  return ans;
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  mp[0] = n;
  mp[1] = n;
  mp[2] = n - 1;
  mp[3] = n - 1;
  mp[4] = n - 2;

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 4; j++) {
      dp[i][j] = -1;
    }
  }

  int ans = inf;
  ans = min(ans, abs(a[1] - a[2]) + f(3, 0));

  vector<int> v;
  v.push_back(a[1]);
  v.push_back(a[2]);
  v.push_back(a[3]);
  sort(v.begin(), v.end());
  int x = abs(v[1] - v[0]) + abs(v[1] - v[2]);
  ans = min(ans, x + f(4, 1));

  ans = min(ans, abs(a[1] - a[n]) + f(2, 2));

  v.clear();
  v.push_back(a[1]);
  v.push_back(a[2]);
  v.push_back(a[n]);
  sort(v.begin(), v.end());
  x = abs(v[1] - v[0]) + abs(v[1] - v[2]);
  ans = min(ans, x + f(3, 3));

  v.clear();
  v.push_back(a[1]);
  v.push_back(a[n - 1]);
  v.push_back(a[n]);
  sort(v.begin(), v.end());
  x = abs(v[1] - v[0]) + abs(v[1] - v[2]);
  ans = min(ans, x + f(2, 4));

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