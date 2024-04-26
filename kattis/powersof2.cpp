#include <bits/stdc++.h>

#ifndef cpheader
#define F0R(i,a,b) for (int i = a; i < b; ++i)
#define f0r(i,b) F0R(i,0,b)
#define F0Rd(i,a,b) for (int i = a; i >= b; --i)
typedef long long ll;
typedef std::vector<int> vi;
template <class T, class U>
constexpr bool chmax(T& a, U&& b) {
  return a < b ? a = std::forward<U>(b), true : false;
}
template <typename T, typename U>
constexpr long long powi(T a, U b) {
  long long x = 1;
  f0r(i, b) x*=a;
  return x;
}
#define cpheader
#endif


using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  unsigned long long n, e, other;
  cin >> n >> e;

  if (powi(2, e) > n) {
    cout << 0; // edge case remover
    return 0;
  }

  //dp
  vector<unsigned long long> dp(62, 0);
  int twopow = to_string(powi(2, e)).length();
  dp[0] = 1;
  F0R(i, 1, 62){
    dp[i] = 10*dp[i-1] + powi(10, i) - ((i-twopow >= 0) ? dp[i-twopow] : 0);
  }
  // f0r(i, 62) {
  //   cout << "dp[" << i << "]: " << dp[i] << '\n';
  // }

  //conversion of thing into chunk 5321 would be 5 * 1000 + 3 * 100 etc
  // problem is, 132 is converted into 
  string ns = to_string(n);

  if (n > powi(2, e)*powi(10, ns.length()-twopow)) {
    unsigned long long b = n;
    n = powi(10, ns.length()-twopow)-b;
  }
  ns = to_string(n);

  unsigned long long a = 0;
  if (ns.length() > 0)
  for(int i = 0; i < ns.length()-twopow; ++i) {
    a+=dp[ns.length()-twopow-i-1]*((ns[i] - '0'));
    n -= (ns[i] - '0')*powi(10, ns.length()-1-i);
  }
  if (powi(2, e) <= n) {a++;} 

  cout << a;
}