#include<string>
using namespace std;

// Faster string to integer conversion
int fastStoi(const string &s) {
  int num = 0, i = 0, sign = 1;
  if(s[0] == '-') { 
    sign = -1; 
    i = 1; 
  }
  for(; i < s.size(); i++) {
    num = num * 10 + (s[i] - '0');
  }
  return num * sign;
}

int main() {
  
}