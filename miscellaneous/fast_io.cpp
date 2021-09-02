/**
   Fast Input/Output method for C++:
   1. cin(with sync_with_stdio(false) & cin.tie(nullptr)):
   - int: 
   - |n = 5e6| => 420ms
   - |n = 1e7| => 742ms
   - ll:
   - |n = 5e6| => 895ms

   2. read (using getchar()):
   - int:
   - |n = 5e6| => 173ms
   - |n = 1e7| => 172ms
   - ll:
   - |n = 5e6| => 340ms
**/

ll readll () {
  bool minus = false;
  unsigned long long result = 0;
  char ch;
  ch = getchar();
  
  while (true) {
    if (ch == '-') break;
    if (ch >= '0' && ch <= '9') break;
    ch = getchar();
  }

  if (ch == '-') minus = true;
  else result = ch - '0';

  while (true) {
    ch = getchar();
    if (ch < '0' || ch > '9') break;
    result = result * 10 + (ch - '0');
  }

  if (minus) return -(ll)result;
  return result;
}

int readi () {
  bool minus = false;
  unsigned int result = 0;
  char ch;
  ch = getchar();
  
  while (true) {
    if (ch == '-') break;
    if (ch >= '0' && ch <= '9') break;
    ch = getchar();
  }

  if (ch == '-') minus = true;
  else result = ch - '0';

  while (true) {
    ch = getchar();
    if (ch < '0' || ch > '9') break;
    result = result * 10 + (ch - '0');
  }

  if (minus) return -(int)result;
  return result;
}
