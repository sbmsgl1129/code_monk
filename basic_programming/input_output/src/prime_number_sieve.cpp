#include <iostream>
#include <cmath>

#include <vector>

void PrimeSieve(unsigned int num){
    std::vector<bool> isPrime(num, true);
    
    //'1' is not prime
    isPrime[0] = false;

    unsigned int uint_sqrt_of_num = static_cast<int>(sqrt(num));
    for(unsigned int i = 2; i <= uint_sqrt_of_num; i++){
      if(isPrime[i - 1]){
        int j = i*i;
        while(j <= num){
          isPrime[j - 1] = false;
          j += i;  
        }
      }  
    }

    for(unsigned int i = 0; i < num; i++){
      if(isPrime[i]){
        std::cout << i+1 << " ";
      }
    }
}

int main(){
  unsigned int input;

  std::cin >> input;
  PrimeSieve(input);

  return 0;
}
