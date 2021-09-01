/*
  Constraints:
  1 <= n <= 1e7
	
  Time Complexity:
  Phi_sieve takes O(n * ln(ln(n)))
	
  Space Complexity:
  MaxN
*/

int EulerPhi[N];

void Phi_sieve(int n) {
  for (int i = 1; i <= n; ++i) {
    EulerPhi[i] = i;
  }
  for (int i = 2; i <= n; ++i) {
    if (EulerPhi[i] == i)
      for (int j = i; j <= n; j += i) {
	EulerPhi[j] -= EulerPhi[j] / i;
      }
  }
}
