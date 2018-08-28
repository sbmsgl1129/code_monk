#include <iostream>
#include <cmath>
#include <unordered_map>
#include <vector>

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

//Understood problem the HARD way.
//So Solution may be little convoluted
//Not Readable I agree
//Will think and write later decent solution for this

char findNearestPrime(char ch, const std::unordered_map<int,int>& prime_map){
  
  //For chars other than Alphabets
  char first_prime_in_upper_alphabets = 'C';
  char last_prime_in_upper_alphabets  = 'Y';
  char first_prime_in_lower_alphabets = 'a';
  char last_prime_in_lower_alphabets  = 'q';

  if(ch < 'A'){
    return first_prime_in_upper_alphabets;  
  }else if(ch > 'Z' && ch < 'a'){
    return ((ch - last_prime_in_upper_alphabets) <= (first_prime_in_lower_alphabets - ch) ? last_prime_in_upper_alphabets
                                                                                      : first_prime_in_lower_alphabets);
  }else if(ch > 'z'){
    return last_prime_in_lower_alphabets;  
  }
  
  //For chars b/w alphabets
  //Although it is good, some optimised code can be written

  int start_char;
  int end_char;

  if(isupper(ch)){
    start_char = 'A';
    end_char   = 'Z';
  }else if(islower(ch)){
    start_char = 'a';
    end_char   = 'z';
  }
  
  int ch_ascii = ch;
  
  //nearest_prime in backwards direction
  int nearest_prime_back = 0;
  int distance_nearest_prime_back = 0;
  for(int i = ch_ascii;i >= start_char; i--){
    if(prime_map.find(i) != prime_map.end()){
      nearest_prime_back = i; 
      break;  
    }
    distance_nearest_prime_back++;
  }  
  
  //nearest_prime in forward direction
  int nearest_prime_ahead = 0;
  int distance_nearest_prime_ahead = 0;
  for(int i = ch_ascii;i <= end_char; i++){
    if(prime_map.find(i) != prime_map.end()){
      nearest_prime_ahead = i;
      break;  
    }
    distance_nearest_prime_ahead++;
  }  
  
  if(nearest_prime_ahead == 0){
    return (char)nearest_prime_back;  
  }else if(nearest_prime_back == 0){
   return  (char)nearest_prime_ahead;  
  }else{
    return (distance_nearest_prime_back <= distance_nearest_prime_ahead ? (char)nearest_prime_back : 
                                                                          (char)nearest_prime_ahead);
  }
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
