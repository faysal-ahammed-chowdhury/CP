#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 9;
string s;
int l, r, n;

int f(int i) {
  return n - i + 1;
}

int get(char c) {
  return c - 'a';
}

bool ok1(int len) {
  int freq[30];
  memset(freq, 0, sizeof freq);
  int to = l + len - 1;
  for (int i = l; i <= to; i++) {
    freq[get(s[i])]++;
  }

  int baad = (r - l + 1) - len;
  baad = min(baad, len);
  for (int i = l, j = 1; j <= baad; i++, j++) {
    if (freq[get(s[f(i)])] > 0) freq[get(s[f(i)])]--;
    else return false;
  }

  int odd = 0;
  for (int i = 0; i < 26; i++) {
    odd += freq[i] % 2;
  }

  if (odd == 0) {
    int ll = l + len, rr = r - len;
    while (ll <= rr) {
      if (ll == rr) return false;
      if (s[ll] != s[rr]) return false;
      ll++, rr--;
    }
    return true;
  }

  return false;
}

bool ok2(int len) {
  int freq[30];
  memset(freq, 0, sizeof freq);

  int baad = (r - l + 1) - len;
  int from = r - len + 1;
  for (int i = from; i <= r; i++) {
    freq[get(s[i])]++;
  }

  for (int i = r, j = 1; j <= baad; i--, j++) {
    if (freq[get(s[f(i)])] > 0) freq[get(s[f(i)])]--;
    else return false;
  }

  int odd = 0;
  for (int i = 0; i < 26; i++) {
    odd += freq[i] % 2;
  }

  if (odd == 0) {
    int ll = l + len, rr = r - len;
    while (ll <= rr) {
      if (ll == rr) return false;
      if (s[ll] != s[rr]) return false;
      ll++, rr--;
    }
    return true;
  }

  return false;
}

bool ok(int len) {
  return ok1(len) or ok2(len);
}

void solve() {
  cin >> s;
  n = s.size();
  s = '.' + s;
  l = 1, r = n;
  while (l <= r) {
    if (s[l] != s[r]) break;
    l++, r--;
  }
  if (l >= r) {
    cout << 0 << '\n';
    return;
  }

  int len = r - l + 1;
  int ll = 0, rr = len, ans = n - 1;
  while (ll <= rr) {
    int mid = (ll + rr) / 2;
    if (ok(mid)) {
      ans = mid;
      rr = mid - 1;
    }
    else {
      ll = mid + 1;
    }
  }

  cout << ans << '\n';
  assert(ans != -1);

  // cout << ok(10) << '\n';
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