#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9;
int n, prv[N];
string s;
int dp[N][2];

int f(int i, bool last_right) {
  if (i > n) {
    if (last_right) return s[n] == '0';
    return true;
  }
  int &ans = dp[i][last_right];
  if (ans != -1) return ans;
  ans = false;
  if (s[i] == '1') ans |= f(i + 1, last_right);
  else {
    int idx = prv[i];


    if (idx == -1) {
      ans |= f(i + 1, true);
      if (i == 1) ans |= f(i + 1, false);
    }
    else {
      int dis = i - idx;
      if (dis == 1) {
        ans |= f(i + 1, true);
        ans |= f(i + 1, false);
      }
      else if (dis == 2) {
        if (last_right) {
          ans |= f(i + 1, false);
        }
        else {
          ans |= f(i + 1, true);
        }
      }
      else {
        if (last_right == false) {
          ans |= f(i + 1, true);
        }
      }
    }
  }

  return ans;
}

void solve() {
  cin >> n;
  cin >> s;
  s = '#' + s;

  prv[0] = -1;
  for (int i = 1; i <= n; i++) {
    prv[i] = prv[i - 1];
    if (s[i - 1] == '0') prv[i] = i - 1;
  }

  for (int i = 1; i <= n; i++) {
    dp[i][0] = -1;
    dp[i][1] = -1;
  }

  if (f(1, false)) cout << "YES\n";
  else cout << "NO\n";
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