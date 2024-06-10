#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
using ll = long long;

void remove(vector<ll> &v, ll l, ll r, ll element) {
  v[l] = element;
  v.erase(v.begin() + l + 1, v.begin() + r + 1);
}

void solve() {
  int n; cin >> n;
  vector<ll> v(n);
  for(int i = 0; i < n; i++) {
    cin >> v[i];
  }

  ll len = n;
  for(int i = 0; i < n; i++) {
    ll mx = INT_MIN;
    ll l = -1, r = -1;
    for(int j = 0; j < len - 2; j++) {
      ll tmp = max({v[j], v[j + 1], v[j + 2]});
      ll tmp2 = max(tmp, v[j] + v[j + 2]);
      if(tmp2 > tmp) {
        if(tmp2 > mx) {
          l = j, r = j + 2;
          mx = tmp2;
        }
      }
    }
    if(mx != INT_MIN) {
      ll element = v[l] + v[r];
      len -= 2;
      remove(v, l, r, element);
    }

  }

  ll ans = INT_MIN;
  for(int i = 0; i < len; i++) {
    ans = max(ans, v[i]);
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