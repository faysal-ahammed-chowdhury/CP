#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  map<int, int> mp;
  for(int i = 0; i < n; i++) {
    int x; cin >> x;
    mp[x]++;
  }

  if(n == 1) {
    cout << "N\n";
    return 0;
  }
  
  for(auto i: mp) {
    int go = i.second / 2;
    if(go > 0) {
      mp[i.first + 1] += go;
      mp[i.first] -= (go * 2);
    }
  }

  int cnt = 0;
  for(auto i: mp) {
    if(i.second > 0) {
      cnt++;
    }
  }

  if(cnt > 2) {
    cout << "N\n";
  } 
  else {
    cout << "Y\n";
  }


  return 0;
}