ll gcd(ll a, ll b) { // binary GCD uses about 60% fewer bit operations
  if (!a) return b;

  int shift = __builtin_ctz(a | b);
  a >>= __builtin_ctz(a);

  while (b) {
    b >>= __builtin_ctz(b);

    if (a > b)
      swap(a, b);
    b -= a;
  }
  return a << shift;
}

ll lcm(ll a, ll b) {
  return a / gcd(a, b) * b;
}
	
