#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n = 12;
  map<int, int> mp;
  int lim = sqrt(n + 1);
  for(int i = 2; i <= lim; i++) {
    while(n % i == 0) {
      mp[i]++;
      n /= i;
    }
  }
  if(n > 1) mp[n]++;

  int nod = 1;
  for(auto i: mp) {
    nod *= (i.second + 1);
  }
  cout << nod << '\n';
        
  return 0;
}