#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9, mod = 10000019;
vector<bool> is_prime(N, true);
vector<int> primes;

void sieve() {
  is_prime[1] = false;
  int lim = sqrt(N + 1);
  for(int i = 2; i <= lim; i++) {
    if(is_prime[i]) {
      for(int j = i + i; j <= N; j += i) {
        is_prime[j] = false;
      }
    }
  }

  for(int i = 2; i < N; i++) {
    if(is_prime[i]) {
      primes.push_back(i);
    }
  }
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

int legendre(int n, int p) {
  int ex = 0;
  while(n) {
    ex += (n / p);
    n /= p;
  }
  return ex;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  sieve();

  int t, cs = 0; cin >> t;
  while(t--) {
    int n, zeroes; cin >> n >> zeroes;
    vector<pair<int, int>> ans;
    for(auto p: primes) {
      if(p > n) break;
      int pw = legendre(n, p);
      if(pw / zeroes != 0) {
        ans.push_back({p, pw/ zeroes});
      }
    }
    int max_base = 1;
    for(auto i: ans) {
      max_base = 1LL * max_base * power(i.first, i.second) % mod;
    }
    cout << "Case " << ++cs << ": "; 
    cout << (ans.size() == 0 ? -1 : max_base) << '\n';
  }

  return 0;
}




// #include <bits/stdc++.h>
// using namespace std;

// const int N = 1e5 + 9, mod = 10000019;
// vector<bool> is_prime(N, true);
// vector<int> primes;

// void sieve() {
//   is_prime[1] = false;
//   int lim = sqrt(N + 1);
//   for(int i = 2; i <= lim; i++) {
//     if(is_prime[i]) {
//       for(int j = i + i; j <= N; j += i) {
//         is_prime[j] = false;
//       }
//     }
//   }

//   for(int i = 2; i < N; i++) {
//     if(is_prime[i]) {
//       primes.push_back(i);
//     }
//   }
// }

// int power(int b, int p) {
//   if(p == 0) return 1 % mod;
//   if(p & 1) {
//     int val = power(b, p / 2);
//     return ((1LL * val * val) % mod) * b % mod;
//   }
//   else {
//     int val = power(b, p / 2);
//     return (1LL * val * val) % mod;
//   }
// }

// vector<pair<int, int>> ans;

// void solve(vector<pair<int, int>> prime_factors, int t) {
//   for(auto i: prime_factors) {
//     int p = i.first, e = i.second;
//     int pw = e / t;
//     if(pw != 0) {
//       ans.push_back({p, pw});
//     }
//   }
// }

// int main() {
//   ios_base::sync_with_stdio(0);
//   cin.tie(0);

//   sieve();

//   int t, cs = 0; cin >> t;
//   while(t--) {
//     ans.clear();
//     int n, zeroes; cin >> n >> zeroes;
//     vector<pair<int, int>> prime_factors;
//     for(auto p: primes) {
//       if(p > n) break;
//       int x = n, ex = 0;
//       while(x) {
//         ex += (x / p);
//         x /= p;
//       }
//       prime_factors.push_back({p, ex});
//     }
//     solve(prime_factors, zeroes);
//     int max_base = 1;
//     for(auto i: ans) {
//       max_base = 1LL * max_base * power(i.first, i.second) % mod;
//     }
//     cout << "Case " << ++cs << ": "; 
//     cout << (ans.size() == 0 ? -1 : max_base) << '\n';
//   }

//   return 0;
// }