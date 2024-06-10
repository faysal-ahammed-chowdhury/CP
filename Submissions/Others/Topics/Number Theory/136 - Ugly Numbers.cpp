#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll N = 1e6 + 9, MAX = 1e18;


int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  vector<ll> ans;

  for(ll i = 1; i <= MAX; i *= 2) {
    for(ll j = 1; i * j <= MAX; j *= 3) {
      for(ll k = 1; i * j * k <= MAX; k *= 5) {
        ans.push_back(i * j * k);
      }
    }    
  }


  sort(ans.begin(), ans.end());
  cout << "The 1500'th ugly number is " << ans[1499] << ".\n";
        
  return 0;
}