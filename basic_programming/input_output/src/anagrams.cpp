#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
#include <cstdlib>

void countForAnagrams(const std::string& str1, const std::string& str2){
  std::unordered_map<char, int> str1_char_count;
  std::unordered_map<char, int> str2_char_count;

  std::set<char> all_chars;

  int num_chars_to_delete = 0;

  for(auto ch: str1){
    str1_char_count[ch]++;
    all_chars.insert(ch);
  }

  for(auto ch: str2){
    str2_char_count[ch]++; 
    all_chars.insert(ch);
  }

  
  for(auto ch: all_chars){
     
     int ch_str1_count = 0;
     int ch_str2_count = 0;

     if(str1_char_count.find(ch) != str1_char_count.end()){
       ch_str1_count = str1_char_count[ch];  
     }

     if(str2_char_count.find(ch) != str2_char_count.end()){
       ch_str2_count = str2_char_count[ch];  
     }
     
     num_chars_to_delete += std::abs(ch_str1_count - ch_str2_count);
  }
  
  std::cout << num_chars_to_delete << "\n";
}

int main(){
  int test_cases;
  
  std::cin >> test_cases;
  while(test_cases--){
    std::string str1, str2;

    std::cin >> str1;
    std::cin >> str2;
    
    countForAnagrams(str1,str2);
  }
  return 0;
}
