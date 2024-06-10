#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

#define int long long
map<char, int> mp;

bool is_prime(int n) {
  if (n == 1) return true;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int id = 0;
  mp[' '] = id;
  for(char c = 'a'; c <= 'z'; c++) {
    mp[c] = ++id;
  }
  for(char c = 'A'; c <= 'Z'; c++) {
    mp[c] = ++id;
  }

  string s;
  while(getline(cin, s)) {
    int x = 0;
    for(auto i: s) {
      x += mp[i];
    }
    if(is_prime(x)) {
      cout << "It is a prime word.\n";
    }
    else {
      cout << "It is not a prime word.\n";
    }
  }

  return 0;
}