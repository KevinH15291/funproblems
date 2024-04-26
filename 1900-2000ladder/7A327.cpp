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
#define cpheader
#endif


using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, ini = 0;
  cin >> n;

  if (n == 1) {
    cin >> n;
    cout << !n;

    return 0;
  }

  vi nums(n), dp(n, 0);
  f0r(i, n) {
    cin >> nums[i];
    ini += nums[i];
  }
  f0r(i, n) {
    int count = 0;
    F0R(j, i, n) {
      count += (nums[j]? -1 : 1);
      dp[i] = max(count, dp[i]);
    }
  }
  int a = 0;

  f0r(i, n) {
    a = max(a, dp[i]);
  }

  cout << (ini == n ? n-1 : a+ini);
  
  return 0;
}
