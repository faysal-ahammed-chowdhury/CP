#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  s = '.' + s;
  int cnt1 = 0, cnt2 = 0, cnt3 = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'L') cnt1++;
    else if (s[i] == 'I') cnt2++;
    else if (s[i] == 'T') cnt3++;
  }
  int op = n + n, tmp = n + n;
  vector<int> v;
  while (op--) {
    if (cnt1 == cnt2 and cnt2 == cnt3) break;
    bool done = false;
    if (cnt1 <= min(cnt2, cnt3)) {
      for (int i = 1; i < n; i++) {
        if ((s[i] == 'I' and s[i + 1] == 'T') or (s[i] == 'T' and s[i + 1] == 'I')) {
          v.push_back(i);
          s = s.substr(0, i + 1) + 'L' + s.substr(i + 1);
          n++;
          cnt1++;
          done = true;
          break;
        }
      }
    }
    else if (cnt2 <= min(cnt1, cnt3)) {
      for (int i = 1; i < n; i++) {
        if ((s[i] == 'L' and s[i + 1] == 'T') or (s[i] == 'T' and s[i + 1] == 'L')) {
          v.push_back(i);
          s = s.substr(0, i + 1) + 'I' + s.substr(i + 1);
          n++;
          cnt2++;
          done = true;
          break;
        }
      }
    }
    else if (cnt3 <= min(cnt1, cnt2)) {
      for (int i = 1; i < n; i++) {
        if ((s[i] == 'L' and s[i + 1] == 'I') or (s[i] == 'I' and s[i + 1] == 'L')) {
          v.push_back(i);
          s = s.substr(0, i + 1) + 'T' + s.substr(i + 1);
          n++;
          cnt3++;
          done = true;
          break;
        }
      }
    }

    if (!done) {
      for (int i = 1; i < n; i++) {
        if ((s[i] == 'I' and s[i + 1] == 'T') or (s[i] == 'T' and s[i + 1] == 'I')) {
          v.push_back(i);
          s = s.substr(0, i + 1) + 'L' + s.substr(i + 1);
          n++;
          cnt1++;
          done = true;
          break;
        }
      }
    }

    if (!done) {
      for (int i = 1; i < n; i++) {
        if ((s[i] == 'L' and s[i + 1] == 'T') or (s[i] == 'T' and s[i + 1] == 'L')) {
          // cout << "eee\n";
          // cout << s << ' ' << i << '\n';
          v.push_back(i);
          s = s.substr(0, i + 1) + 'I' + s.substr(i + 1);
          n++;
          cnt2++;
          done = true;
          break;
        }
      }
    }

    if (!done) {
      for (int i = 1; i < n; i++) {
        if ((s[i] == 'L' and s[i + 1] == 'I') or (s[i] == 'I' and s[i + 1] == 'L')) {
          v.push_back(i);
          s = s.substr(0, i + 1) + 'T' + s.substr(i + 1);
          n++;
          cnt3++;
          done = true;
          break;
        }
      }
    }
    // cout << s.substr(1) << '\n';
  }

  // cout << v.size() << '\n';

  if (cnt1 == cnt2 and cnt2 == cnt3 and v.size() <= tmp) {
    cout << v.size() << '\n';
    for (auto x : v) cout << x << '\n';
  }
  else cout << -1 << '\n';
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