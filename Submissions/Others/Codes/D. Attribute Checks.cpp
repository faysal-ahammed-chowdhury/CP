#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 9, M = 5005, inf = 1e9;
int n, m, sz, pos[N], neg[N], dp[M][M];
vector<int> zeroes;

int f(int i, int intel, int strength) {
  if (i > sz) return 0;

  int &ans = dp[i][intel];
  if (ans != -1) return ans;

  int st = 1, en = n;
  if (i > 0) st = zeroes[i - 1] + 1;
  if (i < sz) en = zeroes[i] - 1;

  int val1 = 0, val2 = 0;
  if (st <= en) {
    val1 = upper_bound(pos + st, pos + en + 1, intel) - &pos[st];
    val2 = upper_bound(neg + st, neg + en + 1, strength) - &neg[st];
  }
  int ans1 = val1 + val2 + f(i + 1, intel + 1, strength);
  int ans2 = val1 + val2 + f(i + 1, intel, strength + 1);

  ans = max(ans1, ans2);
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    if (x == 0) {
      zeroes.push_back(i);
      pos[i] = inf;
      neg[i] = inf;
    }
    else if (x > 0) {
      pos[i] = x;
      neg[i] = inf;
    }
    else {
      pos[i] = inf;
      neg[i] = abs(x);
    }
  }

  sz = zeroes.size();
  for (int i = 0; i < sz; i++) {
    int st = zeroes[i] + 1, en = n;
    if (i + 1 < sz) en = zeroes[i + 1] - 1;
    // cout << st << ' ' << en << '\n';
    if (st > en) continue;
    sort(pos + st, pos + en + 1);
    sort(neg + st, neg + en + 1);
  }

  // for (int i = 1; i <= n; i++) {
  //   cout << pos[i] << ' ';
  // }
  // cout << '\n';

  memset(dp, -1, sizeof dp);
  cout << f(0, 0, 0) << '\n';

  return 0;
}