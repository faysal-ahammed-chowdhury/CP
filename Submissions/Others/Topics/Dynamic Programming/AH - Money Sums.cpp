#include <bits/stdc++.h>
using namespace std;

const int N = 105, MAX_VAL = 1e5 + 9;
int n, a[N];
bool dp[N][MAX_VAL];
bool vis[N][MAX_VAL];

bool fun(int i, int sum) {
  if (i == n + 1) {
    if (sum == 0) return true;
    return false;
  }
  bool &ans = dp[i][sum];
  if (vis[i][sum]) return ans;
  vis[i][sum] = true;
  if (sum >= a[i]) ans = fun(i + 1, sum - a[i]);
  if (ans) return true;
  ans = fun(i + 1, sum);
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  vector<int> v;
  for (int x = 1; x < MAX_VAL; x++) {
    if (fun(1, x)) {
      v.push_back(x);
    }
  }

  cout << v.size() << '\n';
  for (auto x : v) {
    cout << x << ' ';
  }
  cout << '\n';

  return 0;
}