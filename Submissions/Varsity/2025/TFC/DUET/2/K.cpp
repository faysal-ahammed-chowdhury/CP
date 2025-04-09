#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 1e6 + 9, inf = 1e9;
int dp[N][5];
int n;

bool is_vowel(char c) {
  if (c == 'A' or c == 'E' or c == 'I' or c == 'O' or c == 'U' or c == 'Y') return true;
  return false;
}

int calc(int cnt, string &s) {
  for (auto c : s) {
    if (!is_vowel(c)) cnt++;
    else cnt = 0;
    if (cnt > 2) return inf;
  }
  return cnt;
}

int f(int i, int cnt, vector<string> &s) {
  if (i > n) return 0;

  if (cnt > 2) return inf;
  int &ans = dp[i][cnt];
  if (ans != -1) return ans;

  ans = inf;
  string tmp = "";
  tmp += s[i][0];
  int x = calc(cnt, tmp);
  // cout << i << ' ' << x << '\n';
  if (x <= 2) {
    ans = min(ans, 1 + f(i + 1, x, s));
  }

  if (s.size() >= 2) {
    tmp = "";
    tmp += s[i][0];
    tmp += s[i][1];
    int x = calc(cnt, tmp);
    if (x <= 2) {
      ans = min(ans, 2 + f(i + 1, x, s));
    }
  }

  if (s.size() >= 3) {
    tmp = "";
    tmp += s[i][0];
    tmp += s[i][1];
    tmp += s[i][2];
    int x = calc(cnt, tmp);
    if (x <= 2) {
      ans = min(ans, 3 + f(i + 1, x, s));
    }
  }

  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof dp);

  cin >> n;
  vector<string> s(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    if (s.size() > 3) {
      s[i] = s[i].substr(0, 3);
    }
  }

  int ans = f(1, 0, s);
  if (ans >= inf) cout << "*\n";
  else cout << ans << '\n';

  return 0;
}