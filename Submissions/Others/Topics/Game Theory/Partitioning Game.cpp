#include <bits/stdc++.h>
using namespace std;

const int N = 105, S = 10005;
int dp[S];

int f(int stone) {
  if (stone <= 2) return 0;
  int &ret = dp[stone];
  if (ret != -1) return ret;
  vector<bool> mex(S, false);
  for (int i = 1; i < stone; i++) {
    int l = i, r = stone - i;
    if (l != r) {
      int xr = f(l) ^ f(r);
      mex[xr] = true;
      // cout << stone << ' ' << l << ' ' << r << ' ' << xr << '\n';
    }
  }
  ret = 0;
  while (true) {
    if (mex[ret] == true) ret++;
    else break;
  }
  return ret;
}

int cs;
void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int xr = 0;
  for (int i = 1; i <= n; i++) {
    xr ^= f(a[i]);
  }

  cout << "Case " << ++cs << ": ";
  if (xr) cout << "Alice\n";
  else cout << "Bob\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  memset(dp, -1, sizeof dp);
  while(t--) {
    solve();
  }

  return 0;
}