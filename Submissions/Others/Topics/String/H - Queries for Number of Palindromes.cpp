#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
string s;
int n, dp[N][N], dp2[N][N];

int is_palindrome(int i, int j) { // O(n^2)
  if (i > j) return 1;
  int &ans = dp2[i][j];
  if (ans != -1) return ans;
  ans = 1;
  if (s[i] == s[j]) {
    ans &= is_palindrome(i + 1, j - 1);
  }
  else {
    ans = 0;
  }
  return ans;
}

int fun(int i, int j) { // O(n^2)
  if (i > j) return 0;
  int &ans = dp[i][j];
  if (ans != -1) return ans;
  ans = is_palindrome(i, j) + fun(i + 1, j) + fun(i, j - 1) - fun(i + 1, j - 1);
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> s;
  n = s.size();
  memset(dp, -1, sizeof(dp));
  memset(dp2, -1, sizeof(dp2));
  int q; cin >> q;
  while (q--) {
    int l, r; cin >> l >> r;
    l--, r--;
    cout << fun(l, r) << '\n';
  }

  return 0;
}
// O((n^2) + q)