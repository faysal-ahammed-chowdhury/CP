#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  int mx = -25, idx = -1, mn = 25, idx2 = -1;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    mx = max(mx, a[i]);
    mn = min(mn, a[i]);
    if(a[i] == mx) idx = i;
    if(a[i] == mn) idx2 = i;
  }
  if(mx <= 0) {
    int k = 5;
    vector<pair<int, int>> ans;
    ans.push_back({idx2, idx2});
    ans.push_back({idx2, idx2});
    ans.push_back({idx2, idx2});
    ans.push_back({idx2, idx2});
    ans.push_back({idx2, idx2});
    a[idx2] += a[idx2];
    a[idx2] += a[idx2];
    a[idx2] += a[idx2];
    a[idx2] += a[idx2];
    a[idx2] += a[idx2];
    for(int i = n - 1; i >= 1; i--) {
      if(a[i] > a[i + 1]) {
        a[i] += a[idx2];
        a[i] += a[idx2];
        k += 2;
        ans.push_back({i, idx2});
        ans.push_back({i, idx2});
        idx2 = i;
      }
    }

    cout << k << '\n';
    for(auto i: ans) {
      cout << i.first << ' ' << i.second << '\n';
    }

    return;
  }

  int k = 5;
  vector<pair<int, int>> ans;
  ans.push_back({idx, idx});
  ans.push_back({idx, idx});
  ans.push_back({idx, idx});
  ans.push_back({idx, idx});
  ans.push_back({idx, idx});
  a[idx] += a[idx];
  a[idx] += a[idx];
  a[idx] += a[idx];
  a[idx] += a[idx];
  a[idx] += a[idx];
  for(int i = 2; i <= n; i++) {
    if(a[i] < a[i - 1]) {
      a[i] += a[idx];
      a[i] += a[idx];
      k += 2;
      ans.push_back({i, idx});
      ans.push_back({i, idx});
      idx = i;
    }
  }

  cout << k << '\n';
  for(auto i: ans) {
    cout << i.first << ' ' << i.second << '\n';
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}