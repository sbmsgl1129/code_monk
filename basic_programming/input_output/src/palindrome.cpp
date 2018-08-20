#include <iostream>

int main(){
  std::string s;
  bool is_palindrome = true;

  std::cin >> s;
  
  auto sbegin  = s.cbegin();
  auto send    = s.cend();

  while(sbegin <= send){
    --send;
    if((*sbegin) != (*send)){
      is_palindrome = false;
      break;
    }
    ++sbegin;
  }

  if(is_palindrome){
    std::cout << "YES";  
  }else{
    std::cout << "NO";  
  }

  return 0;  
}
