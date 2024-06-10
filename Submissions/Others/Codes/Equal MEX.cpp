#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve() {
  int n; cin >> n;
  int cnt[n + 1];
  memset(cnt, 0, sizeof(cnt));
  for(int i = 1; i <= 2 * n; i++) {
    int x; cin >> x;
    cnt[x]++;
  }

  vector<int> first, second;
  for(int i = 0; i <= n; i++) {
    if(cnt[i] > 1) {
      first.push_back(i);
      second.push_back(i);
    }
    else if(cnt[i] == 1) {
      second.push_back(i);
    }
  }

  sort(first.begin(), first.end());
  sort(second.begin(), second.end());
  int first_mex = 0, second_mex = 0;
  for(auto i: first) {
    if(i == first_mex) first_mex++;
  }
  for(auto i: second) {
    if(i == second_mex) second_mex++;
  }

  if(first_mex == second_mex) {
    cout << "YES\n";
  }
  else {
    cout << "NO\n";
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