#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
using ll = long long;

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll n, k; cin >> n >> k;
  pair<ll, ll> arr[n + 1];
  for(int i = 1; i <= n; i++) {
    int a, b; cin >> a >> b;
    arr[i] = {a, b};
  }

  sort(arr + 1, arr + n + 1);

  ll prefix[n + 1];
  prefix[0] = 0;

  for(int i = 1; i <= n; i++) {
    prefix[i] = prefix[i - 1] + arr[i].second;
  }


  if(prefix[n] <= k) {
    cout << "1\n";
    return 0;
  }

  for(int i = 2; i <= n; i++) {
    if(prefix[n] - prefix[i - 1] <= k) {
      cout << arr[i - 1].first + 1 << '\n';
      return 0;
    }
  }

  cout << arr[n].first + 1 << '\n';
        
  return 0;
}