#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int gcd(int a, int b) {
  if(a == 0) return b;
  if(b == 0) return a;
  if(a < b) swap(a, b);
  return gcd(a % b, b);
}

int lcm(int a, int b) {
  return (a * b) / gcd(a, b);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cout << lcm(4, 6) << '\n';
        
  return 0;
}