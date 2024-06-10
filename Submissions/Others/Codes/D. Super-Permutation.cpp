#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve() {
  int n; cin >> n;
  if(n == 1) {
    cout << 1 << '\n';
    return;
  }
  if(n & 1) {
    cout << "-1\n";
    return;
  }
  vector<int> v;
  int i = 0, j = n - 1;
  while(i < j) {
    v.push_back(i);
    v.push_back(j);
    i++, j--;
  }
  vector<long long> ans;
  ans.push_back(n);
  for(int i = 1; i < n; i++) {
    if(v[i] > v[i - 1]) {
      ans.push_back(ans[i - 1] + v[i] - v[i - 1]);
    }
    else {
      long long num = (((ans[i - 1] / n) + 1) * n) + v[i];
      ans.push_back(num);
    }
  }
  long long last = 0;
  for(auto i: ans) {
    cout << i - last << ' ';
    last = i;
  }
  cout << '\n';
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