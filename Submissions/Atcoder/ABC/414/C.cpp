#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

vector<int> v;

bool is_pal(string s) {
  int l = 0, r = s.size(); r--;
  while (l < r) {
    if (s[l] != s[r]) return false;
    l++, r--;
  }
  return true;
}

string convert(int x, int base) {
  string s = "";
  while (x > 0) {
    int now = x % base;
    s.push_back(now + '0');
    x /= base;
  }
  reverse(s.begin(), s.end());
  return (s);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int a, n; cin >> a >> n;

  for (int val = 1; val <= 1000000; val++) {
    string s = to_string(val);
    string t = s;
    reverse(t.begin(), t.end());
    t = s + t;
    v.push_back(atol(t.c_str()));
    t = s; t.pop_back();
    reverse(t.begin(), t.end());
    s = s + t;
    v.push_back(atol(s.c_str()));
  }

  sort(v.begin(), v.end());

  int ans = 0;
  for (auto x : v) {
    if (x > n) break;
    if (is_pal(convert(x, a))) {
      ans += x;
      // cout << x << '\n';
    }
  }

  cout << ans << '\n';

  return 0;
}