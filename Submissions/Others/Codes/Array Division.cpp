#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef long long ll;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n + 1];
  ll psum[n + 1];
  psum[0] = 0;
  multiset<ll> left, right;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    psum[i] = psum[i - 1] + a[i];
    right.insert(a[i]);
  }
  ll tot = psum[n];
  if (tot & 1) {
    cout << "NO\n";
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    left.insert(a[i]);
    right.erase(right.find(a[i]));
    ll sum1 = psum[i], sum2 = tot - sum1;
    ll diff = sum1 - sum2;
    if (diff & 1) continue;
    diff /= 2;
    if (diff == 0) {
      cout << "YES\n";
      return 0;
    }
    if (diff > 0 and left.find(abs(diff)) != left.end()) {
      cout << "YES\n";
      return 0;
    }
    else if (diff < 0 and right.find(abs(diff)) != right.end()) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";

  return 0;
}