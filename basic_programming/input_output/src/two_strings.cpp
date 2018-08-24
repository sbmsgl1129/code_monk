#include <iostream>
#include <unordered_map>
#include <algorithm>

int main(){
  int test_cases;

  std::cin >> test_cases;
  while(test_cases--){
    std::string str1, str2;
    std::cin >> str1 >> str2;
    
    if(str1.length() != str2.length()){
      std::cout << "NO\n";
      continue;
    }
    
    std::unordered_map<char, int> char_count;
    
    for(auto ch : str1){
      char_count[ch]++;  
    }

    bool is_char_present = true;
    for(auto ch : str2){
      if(char_count.find(ch) == char_count.end()){
        std::cout << "NO\n";
        is_char_present = false;
        break;
      }else{
        char_count[ch]--;  
      }
    }
    if(!is_char_present){
      continue;  
    }

    if(std::all_of(char_count.begin(), char_count.end(), 
                [](auto umap_it){return (umap_it.second == 0);})){
      std::cout << "YES\n";  
    }else{
      std::cout << "NO\n";  
    }
  }
  return 0;  
}
