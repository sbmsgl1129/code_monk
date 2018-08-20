#include <iostream>
#include <cmath>
 
int main(){
  int l,r,k;
  int count = 0;
 
  std::cin >> l;
  std::cin >> r;
  std::cin >> k;
  
  if(l == r){
    if(l%k == 0){
        count = 1;
    }
  }else{
    if(l < k){
      l = k;
    }
    count  = std::ceil((r - l + 1.0)/k);
  }
  
  std::cout  << count;
  return 0;
 
}
