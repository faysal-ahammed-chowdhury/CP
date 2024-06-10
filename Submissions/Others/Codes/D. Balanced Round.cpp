#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7, N = 1e5 + 9;
int n, k;

int get_con(vector<int> &a) {
  int ans = 1;
  int cnt = 1;
  for(int i = 1; i < n; i++) {
    if(a[i] - a[i - 1] <= k) {
      cnt++;
    }
    else {
      ans = max(ans, cnt);
      cnt = 1;
    }
  }
  ans = max(ans, cnt);
  return ans;
}

void solve() {
  cin >> n >> k;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());

  int consecutive = get_con(a);
  int cnt = n - consecutive;
  cout << cnt << '\n';
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