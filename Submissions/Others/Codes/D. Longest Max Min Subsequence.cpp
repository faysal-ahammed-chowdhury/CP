#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9, inf = 1e9;

void solve() {
  int n; cin >> n;
  int a[n + 1], last[n + 1], under[n + 1];
  memset(last, 0, sizeof last);
  map<int, queue<int>> indices;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    last[a[i]] = i;
    under[i] = a[i];
    indices[a[i]].push(i);
  }
  int k = 0;
  set<int> lasts;
  for (int i = 1; i <= n; i++) {
    if (last[i] != 0) {
      lasts.insert(last[i]);
      k++;
    }
  }

  map<int, int> cnt;
  set<int> taken, se;
  int i = 1, ii = 1;
  cout << k << '\n';
  for (int j = 1; j <= k; j++) {
    int idx = *lasts.begin();
    while (i <= idx) {
      if (taken.find(a[i]) == taken.end()) {
        cnt[a[i]]++;
        se.insert(a[i]);
      }
      i++;
    }

    int mx = *se.rbegin();
    int mn = *se.begin();
    int val = (j & 1 ? mx : mn);
    idx = -1;
    cout << val << ' ';
    idx = indices[val].front();
    se.erase(val);
    taken.insert(val);
    lasts.erase(last[val]);

    while (ii <= idx) {
      cnt[a[ii]]--;
      if (cnt[a[ii]] == 0) se.erase(a[ii]);
      indices[under[ii]].pop();
      ii++;
    }
  }
  cout << '\n';
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