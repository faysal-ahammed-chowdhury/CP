#include <bits/stdc++.h>
using namespace std;

string s, t;
int n, m, freq[26], freq2[26], cnt, replace_cnt[26];

bool ok(int repeat_cnt) {
  int rem = cnt;
  for (int i = 0; i < 26; i++) {
    int need = (freq2[i] * repeat_cnt) - freq[i];
    need = max(0, need);
    rem -= need;
    replace_cnt[i] = need;
  }
  return rem >= 0;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> s >> t;
  n = s.size(), m = t.size();
  for (auto c : s) {
    if (c == '?') cnt ++;
    else freq[c - 'a']++;
  }
  for (auto c : t) freq2[c - 'a']++;
  int l = 0, r = n / m, ans = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (ok(mid)) {
      ans = mid;
      l = mid + 1;
    }
    else {
      r = mid - 1;
    }
  }
  ok(ans);
  for (auto &c : s) {
    if (c == '?') {
      for (int i = 0; i < 26; i++) {
        if (replace_cnt[i]) {
          replace_cnt[i]--;
          c = char(i + 'a');
          break;
        }
      }
    }
  }
  for (auto &c : s) if (c == '?') c = 'x';
  cout << s << '\n';

  return 0;
}