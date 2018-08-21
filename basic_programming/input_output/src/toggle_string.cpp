#include <iostream>
#include <cctype>

int main(){
  std::string str;

  std::cin >> str;
  for(auto ch: str){
    if(isupper(ch)){
      std::cout << (char)tolower(ch);  
    }else{
      std::cout << (char)toupper(ch);  
    }
  }
  return 0;  
}
