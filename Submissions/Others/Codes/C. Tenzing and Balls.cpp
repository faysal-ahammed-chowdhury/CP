#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9;
int n, a[N], dp[N][2];
vector<int> idx[N];

void clr(int n) {
  for (int i = 0; i <= n; i++) {
    idx[i].clear();
  }
}

int f(int i, bool running) {
  if (i > n) return 0;
  int &ans = dp[i][running];
  if (ans != -1) return ans;
  ans = f(i + 1, false);
  auto it = upper_bound(idx[a[i]].begin(), idx[a[i]].end(), i);
  if (it != idx[a[i]].end()) {
    int len = (*it) - i + (!running);
    ans = max(ans, len + f((*it), true));
  }
  return ans;
}

void solve() {
  cin >> n;
  clr(n);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    idx[a[i]].push_back(i);
  }

  memset(dp, -1, sizeof (dp[0]) * (n + 5));
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