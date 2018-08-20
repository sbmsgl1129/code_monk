#include <iostream>
#include <cmath>

bool IsPrime(unsigned int num){
  unsigned int uint_sqrt_of_num = static_cast<int>(sqrt(num));
  for(unsigned int i = 2; i <= uint_sqrt_of_num; i++){
    if(num % i  == 0){
      return false;  
    }
  }
  return true;
}

int main(){
  unsigned int input;

  std::cin >> input;
  for(unsigned int i = 2; i <= input; i++){
    if(IsPrime(i)){
      std::cout << i << " ";  
    }
  }
  return 0;
}
