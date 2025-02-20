#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 2e5 + 9, inf = 1e9;
string s[3];
int n, dp[N][2][2];

int score(pii a, pii b, pii c, pii d, pii e, pii f) {
  int cnt1 = 0, cnt2 = 0;
  if (s[a.first][a.second] == 'A') cnt1++;
  else cnt2++;

  if (s[b.first][b.second] == 'A') cnt1++;
  else cnt2++;

  if (s[c.first][c.second] == 'A') cnt1++;
  else cnt2++;

  int score = cnt1 > cnt2;


  if (d.first == -1) return score;

  cnt1 = 0, cnt2 = 0;
  if (s[d.first][d.second] == 'A') cnt1++;
  else cnt2++;

  if (s[e.first][e.second] == 'A') cnt1++;
  else cnt2++;

  if (s[f.first][f.second] == 'A') cnt1++;
  else cnt2++;

  score += cnt1 > cnt2;

  return score;
}

int f(int i, bool open1, bool open2) {
  if (i > n) return (!open1 & !open2) ? 0 : -inf;
  int &ans = dp[i][open1][open2];
  if (ans != -1) return ans;
  ans = 0;
  if (open1) {
    if (i + 2 <= n) {
      int x = score({1, i}, {1, i + 1}, {1, i + 2}, {2, i - 1}, {2, i}, {2, i + 1});
      ans = max(ans, x + f(i + 3, open1, open2));
    }
    int x = score({1, i}, {2, i}, {2, i - 1}, { -1, -1}, { -1, -1}, { -1, -1});
    ans = max(ans, x + f(i + 1, false, false));
  }
  else if (open2) {
    if (i + 3 <= n) {
      int x = score({1, i}, {1, i + 1}, {1, i + 2}, {2, i + 1}, {2, i + 2}, {2, i + 3});
      ans = max(ans, x + f(i + 3, open1, open2));
    }
    if (i + 1 <= n) {
      int x = score({1, i}, {1, i + 1}, {2, i + 1}, { -1, -1}, { -1, -1}, { -1, -1});
      ans = max(ans, x + f(i + 2, false, false));
    }
  }
  else {
    if (i + 2 <= n) {
      int x = score({1, i}, {1, i + 1}, {1, i + 2}, {2, i}, {2, i + 1}, {2, i + 2});
      ans = max(ans, x + f(i + 3, open1, open2));
    }
    if (i + 2 <= n) {
      int x = score({1, i}, {2, i}, {1, i + 1}, { -1, -1}, { -1, -1}, { -1, -1});
      ans = max(ans, x + f(i + 2, true, false));
    }
    if (i + 2 <= n) {
      int x = score({1, i}, {2, i}, {2, i + 1}, { -1, -1}, { -1, -1}, { -1, -1});
      ans = max(ans, x + f(i + 1, false, true));
    }
  }

  return ans;
}

void solve() {
  cin >> n >> s[1] >> s[2];
  s[1] = '.' + s[1], s[2] = '.' + s[2];

  // cout << score({1, 1}, {2, 1}, {1, 2}, { -1, -1}, { -1, -1}, { -1, -1}) << '\n';
  // cout << score({1, 3}, {2, 3}, {2, 2}, { -1, -1}, { -1, -1}, { -1, -1}) << '\n';

  for (int i = 0; i <= n; i++) {
    dp[i][0][0] = dp[i][0][1] = -1;
    dp[i][1][0] = dp[i][1][1] = -1;
  }
  cout << f(1, false, false) << '\n';
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