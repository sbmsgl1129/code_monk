#include <iostream>
#include <cmath>
#include <unordered_map>
#include <vector>

/*
 * Seems to have written overkill program which will cover all the ascii chars
 * I guess the problem just wanted alphabets
 * */

void PrimeSieve(unsigned int num, std::unordered_map<int,int>& prime_map){
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
        prime_map[i+1] = 1;
      }
    }
}

char findNearestPrime(char ch, const std::unordered_map<int,int>& prime_map){
  //Currently going for a brute-force kinda method.
  //But we can do binary-search in the list of primes.
  int ch_ascii = ch;
  int i = 1;
  do{
    if(prime_map.find(ch_ascii) != prime_map.end()){
      return (char)ch_ascii;//should find prime b/w 0 and 255
    }
    
    //Updating the variables
    if(i % 2 == 0){
      ch_ascii = ch_ascii + i;  
    }else{
      ch_ascii = ch_ascii - i;  
    }
    i++;  
  }while((ch_ascii >= 0) || (ch_ascii <= 255));//This is more of a dummy condition
                                              //as hopefully we will find a prime
                                              //in between

}

int main(){
  
  //Calculating and Storing Primes b/w 1 to 255 (ASCII range)
  std::unordered_map<int,int> prime_map;
  PrimeSieve(255,prime_map);
  
  int test_cases;
  
  std::cin >> test_cases;
  while(test_cases--){
    int str_len;
    std::string str;
    
    std::cin >> str_len;
    std::cin >> str;

    std::string magical_str(str_len, '0');

    int idx = 0;
    for(auto ch : str){
      char new_ch = findNearestPrime(ch, prime_map);
      magical_str[idx] = new_ch;
      idx++;
    }

    std::cout << magical_str << "\n";
  }
  return 0;  
}
