#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int a[N][N], dp[N][6];
int n, m;

int get(char c) {
  if (c == 'n') return 0;
  if (c == 'a') return 1;
  if (c == 'r') return 2;
  if (c == 'e') return 3;
  if (c == 'k') return 4;
  return 9;
}

int f(int i, int last) {
  if (i > n) {
    if (last == -1) return 0;
    return -(last + 1) * 2;
  }
  int &ans = dp[i][(last == -1 ? 5 : last)];
  if (ans != -1) return ans;
  ans = f(i + 1, last);
  int contrib = 0, now = last + 1;
  for (int j = 1; j <= m; j++) {
    if (a[i][j] == now) {
      // cout << contrib << '\n';
      contrib++;
      now++;
      now %= 5;
    }
    else if (a[i][j] >= 0 and a[i][j] <= 4) {
      contrib--;
    }
  }
  ans = max(ans, contrib + f(i + 1, now - 1));
  return ans;
}

void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 5; j++) {
      dp[i][j] = -1;
    }
  }

  for (int i = 1; i <= n; i++) {
    string s; cin >> s;
    for (int j = 1; j <= m; j++) {
      a[i][j] = get(s[j - 1]);
    }
  }
  cout << f(1, -1) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}