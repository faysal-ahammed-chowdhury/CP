#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

int get(char c) {
  if (c == 'R') return 0;
  if (c == 'G') return 1;
  return 2;
}

void solve() {
  int n, k; cin >> n >> k;
  string s; cin >> s;
  s = '.' + s;
  int freq[n + 1][3];
  memset(freq, 0, sizeof freq);
  for (int i = 1; i <= n; i++) {
    freq[i][get(s[i])]++;
    for (int j = 0; i - 3 >= 1 and j < 3; j++) {
      freq[i][j] += freq[i - 3][j];
    }
  }

  int ans = 1e7;
  for (int i = 1; i + k - 1 <= n; i++) {
    for (int j = 0; j < 3; j++) {
      int rem = k % 3;
      int l = i, r = (i + k - 1) - rem - 2;
      // cout << l << ' ' << r << '\n';
      int good = 0;
      if (j == 0) {
        if (l <= r) {
          good += freq[r][get('R')] - (l - 3 >= 1 ? freq[l - 3][get('R')] : 0);
          good += freq[r + 1][get('G')] - ((l + 1) - 3 >= 1 ? freq[(l + 1) - 3][get('G')] : 0);
          good += freq[r + 2][get('B')] - ((l + 2) - 3 >= 1 ? freq[(l + 2) - 3][get('B')] : 0);
        }
        if (rem == 2) {
          good += s[i + k - 1] == 'G';
          good += s[i + k - 2] == 'R';
        }
        else if (rem == 1) {
          good += s[i + k - 1] == 'R';
        }
      }
      else if (j == 1) {
        if (l <= r) {
          good += freq[r][get('G')] - (l - 3 >= 1 ? freq[l - 3][get('G')] : 0);
          good += freq[r + 1][get('B')] - ((l + 1) - 3 >= 1 ? freq[(l + 1) - 3][get('B')] : 0);
          good += freq[r + 2][get('R')] - ((l + 2) - 3 >= 1 ? freq[(l + 2) - 3][get('R')] : 0);
        }
        if (rem == 2) {
          good += s[i + k - 1] == 'B';
          good += s[i + k - 2] == 'G';
        }
        else if (rem == 1) {
          good += s[i + k - 1] == 'G';
        }
      }
      else {
        if (l <= r) {
          good += freq[r][get('B')] - (l - 3 >= 1 ? freq[l - 3][get('B')] : 0);
          good += freq[r + 1][get('R')] - ((l + 1) - 3 >= 1 ? freq[(l + 1) - 3][get('R')] : 0);
          good += freq[r + 2][get('G')] - ((l + 2) - 3 >= 1 ? freq[(l + 2) - 3][get('G')] : 0);
        }
        if (rem == 2) {
          good += s[i + k - 1] == 'R';
          good += s[i + k - 2] == 'B';
        }
        else if (rem == 1) {
          good += s[i + k - 1] == 'B';
        }
      }

      int tot = (i + k - 1) - i + 1;
      int need = tot - good;
      ans = min(ans, need);
    }
  }

  cout << ans << '\n';
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