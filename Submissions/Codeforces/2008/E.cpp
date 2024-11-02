#include <bits/stdc++.h>
using namespace std;

int get(char c) {
  return c - 'a';
}

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  if (n == 1) {
    cout << 1 << '\n';
    return;
  }
  s = '.' + s;
  int freq[n + 1][26];
  memset(freq, 0, sizeof freq);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 26; j++) {
      if (i - 2 >= 1) {
        freq[i][j] = freq[i - 2][j];
      }
    }
    freq[i][get(s[i])]++;
  }

  if (n % 2 == 0) {
    int odd_max = 0, even_max = 0;
    for (int j = 0; j < 26; j++) {
      odd_max = max(odd_max, freq[n - 1][j]);
      even_max = max(even_max, freq[n][j]);
    }
    int half = n / 2;
    int ans = (half - odd_max) + (half - even_max);
    cout << ans << '\n';
  }
  else {
    int ans = 1e9;
    for (int i = 1; i <= n; i++) {
      if (i % 2 == 0) {
        int odd_max = 0, even_max = 0;
        for (int j = 0; j < 26; j++) {
          int x = 0;
          if (n - 1 > i) {
            x = freq[n - 1][j] - freq[i][j];
          }
          int cnt_odd = freq[i - 1][j] + x;
          int cnt_even = freq[i - 2][j] + (freq[n][j] - freq[i - 1][j]);
          // cout << j << ": " << cnt_odd << '\n';
          // cout << j << ": " << cnt_even << '\n';
          odd_max = max(odd_max, cnt_odd);
          even_max = max(even_max, cnt_even);
        }
        int half = n / 2;
        ans = min(ans, (half - odd_max) + (half - even_max));
        // cout << ans << '\n';
      }
      else {
        int odd_max = 0, even_max = 0;
        for (int j = 0; j < 26; j++) {
          int x = 0;
          int cnt_odd = (i - 2 >= 1 ? freq[i - 2][j] : 0) + (freq[n - 1][j] - freq[i - 1][j]);
          int cnt_even = freq[i - 1][j] + (freq[n][j] - freq[i][j]);
          // cout << j << ": " << cnt_odd << '\n';
          // cout << j << ": " << cnt_even << '\n';
          odd_max = max(odd_max, cnt_odd);
          even_max = max(even_max, cnt_even);
        }
        int half = n / 2;
        ans = min(ans, (half - odd_max) + (half - even_max));
      }
    }
    cout << ++ans << '\n';
  }
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