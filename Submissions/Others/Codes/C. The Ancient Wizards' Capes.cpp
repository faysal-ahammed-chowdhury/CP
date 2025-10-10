#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<pair<char, char>, int> mp;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  char b[n + 1];
  b[1] = 'L';

  char last = 'L';
  int way1 = 1;
  for (int i = 2; i <= n; i++) {
    if (mp[{last, 'R'}] == a[i] - a[i - 1]) {
      last = 'R';
      b[i] = 'R';
    }
    else if (mp[{last, 'L'}] == a[i] - a[i - 1]) {
      last = 'L';
      b[i] = 'L';
    }
    else {
      way1 = 0;
      break;
    }
  }

  char c[n + 1];
  c[1] = 'R';

  last = 'R';
  int way2 = 1;
  for (int i = 2; i <= n; i++) {
    if (mp[{last, 'R'}] == a[i] - a[i - 1]) {
      last = 'R';
      c[i] = 'R';
    }
    else if (mp[{last, 'L'}] == a[i] - a[i - 1]) {
      last = 'L';
      c[i] = 'L';
    }
    else {
      way2 = 0;
      break;
    }
  }

  if (way1) {
    int pref[n + 1];
    memset(pref, 0, sizeof pref);
    for (int i = 1; i <= n; i++) {
      pref[i] = pref[i - 1] + (b[i] == 'L');
    }

    for (int i = 1; i <= n; i++) {
      int see = 1 + pref[i - 1] + ((n - i) - (pref[n] - pref[i]));
      if (see != a[i]) way1 = 0;
    }
  }

  if (way2) {
    int pref[n + 1];
    memset(pref, 0, sizeof pref);
    for (int i = 1; i <= n; i++) {
      pref[i] = pref[i - 1] + (c[i] == 'L');
    }

    for (int i = 1; i <= n; i++) {
      int see = 1 + pref[i - 1] + ((n - i) - (pref[n] - pref[i]));
      if (see != a[i]) way2 = 0;
    }
  }

  cout << way1 + way2 << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  mp[{'L', 'L'}] = 1;
  mp[{'L', 'R'}] = 0;
  mp[{'R', 'L'}] = 0;
  mp[{'R', 'R'}] = -1;

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}