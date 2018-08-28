#include <iostream>
#include <string>
#include <cctype>

int main(){
  std::string str;
  int num;

  std::cin >> str;
  std::cin >> num;
  
  std::string cipher(str);
  int idx = 0;
  for(auto ch : str){
    if(isupper(ch)){
      char new_ch = 'A' + (((ch - 'A') + num)%26);
      cipher[idx] = new_ch;
    }else if(islower(ch)){
      char new_ch = 'a' + (((ch - 'a') + num)%26);
      cipher[idx] = new_ch;
    }else if(isdigit(ch)){
      char new_ch = '0' + (((ch - '0') + num)%10);
      cipher[idx] = new_ch;
    }
    idx++;
  }
  
  std::cout << cipher;
  return 0;  
}
