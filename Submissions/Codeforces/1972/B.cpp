#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int left(int i) {
  for (int j = i - 1; j >= 1; j--) {
    if (s[j] != '.') return j;
  }
  for (int j = n; j > i; j--) {
    if (s[j] != '.') return j;
  }
  return -1;
}
int right(int i) {
  for (int j = i + 1; j <= n; j++) {
    if (s[j] != '.') return j;
  }
  for (int j = 1; j < i; j++) {
    if (s[j] != '.') return j;
  }
  return -1;
}

void flip(int i) {
  if (s[i] == 'U') s[i] = 'D';
  else s[i] = 'U';
}

void solve() {
  cin >> n;
  cin >> s;
  s = '.' + s;
  set<int> done;
  bool my_turn = true;
  while (true) {
    bool ok = false;
    for (int i = 1; i <= n; i++) {
      if (done.find(i) == done.end() and s[i] == 'U') {
        done.insert(i);
        s[i] = '.';
        int sz = done.size();
        if (sz < n - 2) {
          flip(left(i));
          flip(right(i));
        }
        ok = true;
        break;
      }
    }
    if (ok == false) {
      if (my_turn) {
        cout << "NO\n";
      }
      else {
        cout << "YES\n";
      }
      return;
    }
    my_turn = !my_turn;
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