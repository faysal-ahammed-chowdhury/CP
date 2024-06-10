#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n];
  map<int, int> freq;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    freq[a[i]]++;
  }

  int mx = -1, mx_cnt = 0;
  for(auto [val, cnt]: freq) {
    if(cnt >= mx_cnt) {
      mx_cnt = cnt;
      mx = val;
    }
  }
  int idx = -1;
  for(int i = 0; i < n; i++) {
    if(a[i] == mx) {
      idx = i;
      break;
    }
  }

  cout << n - mx_cnt << '\n';

  for(int i = idx - 1; i >= 0; i--) {
    if(a[i] != mx) {
      if(a[i] > mx) {
        cout << 2 << ' ';
      }
      else {
        cout << 1 << ' ';
      }
      cout << i + 1 << ' ' << i + 2 << '\n';
    }
  }

  for(int i = idx + 1; i < n; i++) {
    if(a[i] != mx) {
      if(a[i] > mx) {
        cout << 2 << ' ';
      }
      else {
        cout << 1 << ' ';
      }
      cout << i + 1 << ' ' << i << '\n';
    }
  }

  return 0;
}