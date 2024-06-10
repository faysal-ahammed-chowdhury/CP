#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

const int mod = 998244353, N = 2e6 + 9;
pair<int, int> a[N], b[N];
int n, m;

int cnt = 0;

bool ok(pair<int, int> p) {
  int l = 1, r = n, x = p.first;
  while(l <= r) {
    int mid = (l + r) / 2;
    if(a[mid].first == x) {
      if(a[mid].second > p.second) {
        cnt++;
        return true;
      }
      if(a[mid].second == p.second) {
        return true;
      }
      return false;
    }
    else if(a[mid].first < x) {
      l = mid + 1;
    }
    else {
      r = mid - 1;
    }
  }
  return false;
}

bool check() {
  for(int i = 1; i <= m; i++) {
    if(!ok(b[i])) return false;
  }
  return true;
}

int power(int b, int p) {
  if(p == 0) return 1 % mod;
  if(p & 1) {
    int val = power(b, p / 2);
    return ((1LL * val * val) % mod) * b % mod;
  }
  else {
    int val = power(b, p / 2);
    return (1LL * val * val) % mod;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = i = 1; i <= n; i++) {
    cin >> a[i].first;
  }
  for(int i = i = 1; i <= n; i++) {
    cin >> a[i].second;
  }
  cin >> m;
  for(int i = i = 1; i <= m; i++) {
    cin >> b[i].first;
  }
  for(int i = i = 1; i <= m; i++) {
    cin >> b[i].second;
  }

  sort(a + 1, a + n + 1);
  sort(b + 1, b + m + 1);

  if(!check()) {
    cout << 0 << '\n';
    return 0;
  }

  int ans = power(2, (n - m) + cnt);
  cout << ans << '\n';

  return 0;
}