#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

int pref[70];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;

  if (n == 1) {
    cout << 1 << '\n';
    return 0;
  }

  if (__builtin_popcountll(n) == 1) {
    cout << n - 1 << '\n';
    return 0;
  }

  int org_n = n;
  string s = "";
  while (n > 0) {
    int last = n % 2;
    n /= 2;
    s += char(last + '0');
  }

  reverse(s.begin(), s.end());
  n = s.size();
  s = '#' + s;

  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + (s[i] == '1');
  }

  int l = 1, r = n;
  bool flag = false;
  bool free = false;
  while (l <= r) {
    if (free) {

      s[l] = '1';
      s[r] = '1';
      l++, r--;
      continue;
    }
    if (flag) {
      if (s[l] == '0' and s[r] == '0') {
        l++, r--;
        continue;
      }
      if (s[l] == s[r] and s[l] == '1') {
        int cnt = 0;
        if (l + 1 <= r - 1) {
          cnt = pref[r - 1] - pref[l];
        }
        if (cnt == 0) {
          s[l] = '0';
          s[r] = '0';
          flag = false;
          free = true;
        }
        l++, r--;
        continue;
      }
      else {
        if (s[l] == '1') {
          int cnt = 0;
          if (l + 1 <= r - 1) {
            cnt = pref[r - 1] - pref[l];
          }
          if (cnt) {
            s[r] = '1';
            flag = true;
          }
          else {
            s[l] = '0';
            flag = false;
            free = true;
          }
          l++, r--;
          continue;
        }
        else {
          s[r] = '0';
          flag = false;
        }
      }
    }
    else {
      if (s[l] == s[r]) {
        l++, r--;
        continue;
      }
      else {
        if (s[l] == '1') {
          int cnt = 0;
          if (l + 1 <= r - 1) {
            cnt = pref[r - 1] - pref[l];
          }
          if (cnt) {
            s[r] = '1';
            flag = true;
          }
          else {
            s[l] = '0';
            free = true;
          }
          l++, r--;
          continue;
        }
        else {
          s[r] = '0';
          flag = false;
        }
      }
    }
  }

  l = 1, r = n;
  while (l <= r) {
    assert(s[l] == s[r]);
    l++, r--;
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '1') {
      ans += (1ll << (i - 1));
    }
  }

  assert(ans <= org_n);
  cout << ans << '\n';

  return 0;
}