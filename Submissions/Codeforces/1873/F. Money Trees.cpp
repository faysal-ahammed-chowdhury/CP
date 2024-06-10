#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

#define int unsigned long long
const int N = 2e5 + 9;
int a[N], h[N];
vector<vector<int>> vec;
int n, k; 

bool ok(int len) {
  for(auto i: vec) {
    int x = (int) i.size();
    if(x >= len) {
      for(int j = 0; j + len - 1 < x; j++) {
        if(j == 0) {
          if(i[j + len - 1] <= k) {
            return true;
          }
        }
        else {
          int sum = i[j + len - 1] - i[j - 1];
          if(sum <= k) {
            return true;
          }
        }
      }
    }
  }
  return false;
}

void solve() {
  vec.clear();

  cin >> n >> k;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for(int i = 1; i <= n; i++) {
    cin >> h[i];
  }

  for(int i = 2; i <= n + 1; i++) {
    vector<int> v;
    v.push_back(a[i - 1]);
    while(i <= n && (h[i - 1] % h[i]) == 0) {
      v.push_back(a[i]);
      i++;
    }
    vec.push_back(v);
  }

  for(auto &i: vec) {
    int x = (int)i.size();
    for(int j = 1; j < x; j++) {
      i[j] += i[j - 1];
    }
  }

  if(ok(1) == 0) {
    cout << 0 << '\n';
    return;
  }

  int l = 1, r = N - 1, ans = -1;
  while(l <= r) {
    int mid = (l + r) / 2;
    if(ok(mid)) {
      ans = mid;
      l = mid + 1;
    }
    else {
      r = mid - 1;
    }
  } 
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}