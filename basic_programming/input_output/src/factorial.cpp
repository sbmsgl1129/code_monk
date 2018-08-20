#include <iostream>

int main(){
  int num;
  int num_factorial = 1;

  std::cin >> num;
  for(int i = num; i >= 2; i--){
    num_factorial *= i;
  }

  std::cout  << num_factorial;
  return 0;  
}
