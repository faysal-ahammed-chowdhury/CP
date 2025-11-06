#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 105;
string s;
int n, dp[N][10][2];

int f(int i, int remainder, bool is_started) {
  if (i > n) return remainder == 0 and is_started;
  int &ans = dp[i][remainder][is_started];
  if (ans != -1) return ans;
  ans = f(i + 1, remainder, is_started);
  ans |= f(i + 1, ((remainder * 10) + (s[i] - '0')) % 8, true);
  return ans;
}

void print(int i, int remainder, bool is_started) {
  if (i > n) return;
  int ans = f(i, remainder, is_started);
  int ans1 = f(i + 1, remainder, is_started);
  if (ans1 == ans) {
    print(i + 1, remainder, is_started);
  }
  else {
    cout << s[i];
    print(i + 1, ((remainder * 10) + (s[i] - '0')) % 8, true);
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> s;
  n = s.size();
  s = '.' + s;
  memset(dp, -1, sizeof dp);
  int ans = f(1, 0, false);
  if (!ans) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  print(1, 0, false);

  return 0;
}