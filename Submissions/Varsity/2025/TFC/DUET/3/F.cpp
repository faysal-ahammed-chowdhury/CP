#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool CHECK(int N, int pos) { return (bool)(N & (1 << pos)); }
void SET(int &N, int pos) { (N |= (1 << pos)); }

const int N = 17;
string s[N];
int n;
bool dp[(1 << N)][N][5];
bool vis[(1 << N)][N][5];

bool f(int mask, int last, int who) {
  if (__builtin_popcount(mask) == n) {
    if (n & 1) return true;
    return false;
  }

  if (vis[mask][last][who]) return dp[mask][last][who];
  vis[mask][last][who] = true;

  if (who == 1) {
    bool ans = false;
    for (int j = 1; j <= n; j++) {
      if (!CHECK(mask, j) and (last == 0 or (last > 0 and s[last].back() == s[j].front()))) {
        int nw_mask = mask;
        SET(nw_mask, j);
        ans |= f(nw_mask, j, 2);
      }
    }
    return dp[mask][last][who] = ans;
  }
  bool ans = true;
  for (int j = 1; j <= n; j++) {
    if (!CHECK(mask, j) and (last == 0 or (last > 0 and s[last].back() == s[j].front()))) {
      int nw_mask = mask;
      SET(nw_mask, j);
      ans &= f(nw_mask, j, 1);
    }
  }
  return dp[mask][last][who] = ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }

  bool ans = f(0, 0, 1);
  cout << (ans ? "First" : "Second") << '\n';

  return 0;
}