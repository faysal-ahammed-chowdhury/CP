#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7, N = 2e5 + 9, MAX = 2e5 + 9;
int n, k, arr[N]; 
map<int, vector<int>> mp;

bool ok(int step) {
  step++;
  for(auto i: mp) {
    int now = -1, cnt = 0, val;
    for(auto j: i.second) {
      if(now + step < j) {
        val = j - now - 1;
        cnt++;
        now = j;
      }
      else {
        now = j;
      }
    }
    if(cnt == 0) {
      return true;
    }
    else if(cnt == 1) {
      if((val / 2) <= (step - 1)) {
        return true;
      }
    }
  }
  return false;
}

void solve() {
  mp.clear();
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    mp[arr[i]].push_back(i);
  }
  for(auto i: mp) {
    mp[i.first].push_back(n);
  }
  int l = 0, r = MAX, ans = -1;
  while(l <= r) {
    int mid = (l + r) / 2;
    if(ok(mid)) {
      ans = mid;
      r = mid - 1;
    }
    else {
      l = mid + 1;
    }
  }
  cout << ans << '\n';
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