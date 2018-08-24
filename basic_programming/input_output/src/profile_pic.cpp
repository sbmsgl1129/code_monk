#include <iostream>

int main(){
  int pic_length_required;
  int test_cases;

  std::cin >> pic_length_required;
  std::cin >> test_cases;

  while(test_cases--){
    int width;
    int height;

    std::cin >> width >> height;
    if((width < pic_length_required) || (height < pic_length_required)){
      std::cout  << "UPLOAD ANOTHER\n";  
    }else if(width == height){
      std::cout  << "ACCEPTED\n";
    }else{
      std::cout  << "CROP IT\n";  
    }
  }
  return 0;  
}
