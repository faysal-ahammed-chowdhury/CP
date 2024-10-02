#include <bits/stdc++.h>
using namespace std;

const int N = 505;
string s;
int n, k, is_special[N];

int f(int i, int j, int cnt0, int cnt1) {
  if (i > j) return 0;
  if (i == j) return 1;
  int ans = f(i + 1, j, cnt0, cnt1);
  ans = max(ans, f(i, j - 1, cnt0, cnt1));
  if (is_special[i] and is_special[j]) {
    if (cnt0 >= 2) ans = max(ans, 2 + f(i + 1, j - 1, cnt0 - 2, cnt1));
    if (cnt1 >= 2) ans = max(ans, 2 + f(i + 1, j - 1, cnt0, cnt1 - 2));
  }
  else if (is_special[i]) {
    if (s[j] == '1' and cnt1 > 0) ans = max(ans, 2 + f(i + 1, j - 1, cnt0, cnt1 - 1));
    if (s[j] == '0' and cnt0 > 0) ans = max(ans, 2 + f(i + 1, j - 1, cnt0 - 1, cnt1));
  }
  else if (is_special[j]) {
    if (s[i] == '1' and cnt1 > 0) ans = max(ans, 2 + f(i + 1, j - 1, cnt0, cnt1 - 1));
    if (s[i] == '0' and cnt0 > 0) ans = max(ans, 2 + f(i + 1, j - 1, cnt0 - 1, cnt1));
  }
  else if (s[i] == s[j]) {
    ans = max(ans, 2 + f(i + 1, j - 1, cnt0, cnt1));
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> s >> k;
  n = s.size();
  s = '.' + s;
  int cnt0 = 0, cnt1 = 0;
  for (int i = 1; i <= k; i++) {
    int x; cin >> x;
    is_special[x] = 1;
    cnt0 += s[x] == '0';
    cnt1 += s[x] == '1';
  }
  cout << f(1, n, cnt0, cnt1) << '\n';

  return 0;
}