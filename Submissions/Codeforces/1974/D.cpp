#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  int cnt1 = 0, cnt2 = 0;
  map<char, int> mp;
  for (auto c : s) {
    mp[c]++;
    if (c == 'N' or c == 'S') cnt1++;
    else cnt2++;
  }

  if (cnt1 % 2 or cnt2 % 2) {
    cout << "NO\n";
    return;
  }

  int mn1 = (mp['S'] / 2) * 2;
  int mn2 = (mp['N'] / 2) * 2;
  int mn3 = (mp['E'] / 2) * 2;
  int mn4 = (mp['W'] / 2) * 2;

  mn1 /= 2, mn2 /= 2, mn3 /= 2, mn4 /= 2;

  char ans[n];
  vector<bool> done(n, false);

  cnt1 = 0, cnt2 = 0;
  int cnt3 = 0, cnt4 = 0;

  for (int i = 0; i < n; i++) {
    if (s[i] == 'S' and cnt1 < mn1) {
      ans[i] = 'R';
      done[i] = true;
      cnt1++;
    }
    else if (s[i] == 'S' and cnt2 < mn1) {
      ans[i] = 'H';
      done[i] = true;
      cnt2++;
    }
    else if (s[i] == 'N' and cnt3 < mn2) {
      ans[i] = 'H';
      done[i] = true;
      cnt3++;
    }
    else if (s[i] == 'N' and cnt4 < mn2) {
      ans[i] = 'R';
      done[i] = true;
      cnt4++;
    }
  }

  cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'E' and cnt1 < mn3) {
      ans[i] = 'H';
      done[i] = true;
      cnt1++;
    }
    else if (s[i] == 'E' and cnt2 < mn3) {
      ans[i] = 'R';
      done[i] = true;
      cnt2++;
    }
    else if (s[i] == 'W' and cnt3 < mn4) {
      ans[i] = 'R';
      done[i] = true;
      cnt3++;
    }
    else if (s[i] == 'W' and cnt4 < mn4) {
      ans[i] = 'H';
      done[i] = true;
      cnt4++;
    }
  }

  for (int i = 0; i < n; i++) {
    if (!done[i]) {
      if (s[i] == 'E' or s[i] == 'W') ans[i] = 'R';
      else ans[i] = 'H';
    }
  }

  bool all_same = true;
  for (int i = 1; i < n; i++) {
    all_same &= ans[i] == ans[i - 1];
  }

  if (all_same) {
    cout << "NO\n";
  }
  else {
    for (int i = 0; i < n; i++) {
      cout << ans[i];
    }
    cout << '\n';
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