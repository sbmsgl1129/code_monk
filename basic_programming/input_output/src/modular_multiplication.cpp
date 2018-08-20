#include <iostream>

int main(){
  int n;
  unsigned int to_modulo_with = 1000000007;
  
  unsigned long long answer = 1;
  std::cin >> n;
  while(n--){
    int x;
    std::cin >> x;
    answer = (answer*x) % to_modulo_with;
    //std::cout  << n << ": " << answer << "\n"; 
  }
  std::cout << answer;

  return 0;  
}
