#include <bits/stdc++.h>
using namespace std;

bool is_vowel(char c) {
  return c == 'A' or c == 'E' or c == 'I' or c == 'O' or c == 'U';
}

const int N = 55;
string s;
int n;
bool dp[N][6][6], vis[N][6][6];

bool f1(int i, int cnt3, int cnt5) {
  if (cnt3 > 2 or cnt5 > 4) return true;
  if (i > n) return false;
  if (vis[i][cnt3][cnt5]) return dp[i][cnt3][cnt5];
  vis[i][cnt3][cnt5] = true;
  bool ans = false;
  if (is_vowel(s[i])) ans |= f1(i + 1, cnt3 + 1, 0);
  else ans |= f1(i + 1, 0, cnt5 + 1);
  if (s[i] == '?') {
    ans |= f1(i + 1, cnt3 + 1, 0);
    ans |= f1(i + 1, 0, cnt5 + 1);
  }
  return dp[i][cnt3][cnt5] = ans;
}

bool f2(int i, int cnt3, int cnt5) {
  if (cnt3 > 2 or cnt5 > 4) return false;
  if (i > n) return true;
  if (vis[i][cnt3][cnt5]) return dp[i][cnt3][cnt5];
  vis[i][cnt3][cnt5] = true;
  bool ans = false;
  if (is_vowel(s[i])) ans |= f2(i + 1, cnt3 + 1, 0);
  else ans |= f2(i + 1, 0, cnt5 + 1);
  if (s[i] == '?') {
    ans |= f2(i + 1, cnt3 + 1, 0);
    ans |= f2(i + 1, 0, cnt5 + 1);
  }
  return dp[i][cnt3][cnt5] = ans;
}

int cs;
void solve() {
  cin >> s;
  n = s.size();
  s = '.' + s;
  memset(vis, 0, sizeof vis);
  bool bad = f1(1, 0, 0);
  memset(vis, 0, sizeof vis);
  bool good = f2(1, 0, 0);
  cout << "Case " << ++cs << ": ";
  if (bad and good) cout << "MIXED\n";
  else if (bad) cout << "BAD\n";
  else cout << "GOOD\n";
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