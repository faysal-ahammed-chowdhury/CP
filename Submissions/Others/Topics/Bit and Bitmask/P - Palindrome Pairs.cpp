#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7, N = 1e5 + 9;
int mask[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int n; cin >> n;
  for(int i = 0; i < n; i++) {
    string s; cin >> s;
    vector<int> freq(26, 0);
    for(auto c: s) {
      freq[c - 'a']++;
    }
    for(int j = 0; j < 26; j++) {
      if(freq[j] & 1) {
        mask[i] += (1 << j);
      }
    }
  }

  long long ans = 0;
  map<int, int> mp;
  for(int i = 0; i < n; i++) {
    ans += mp[mask[i]];
    for(int j = 0; j < 26; j++) {
      ans += mp[mask[i] ^ (1 << j)];
    }
    mp[mask[i]]++;
  }

  cout << ans << '\n';

  return 0;
}