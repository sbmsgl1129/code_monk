#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main(){
  unsigned int num_elements;
  int distance;

  std::cin >> num_elements;
  std::cin >> distance;

  std::vector<int> array(num_elements, 0);
  for(unsigned int i = 0; i < num_elements; i++){
    std::cin >> array[i];  
  }

  int check_array_from = 1;
  for(int i = 0; i < num_elements; i++){
    //Traverse from (current - distance) to (current + distance)
    //But we will do a bit intelligently using check_array_from
    if(array[i] > 0 && check_array_from <= (i + distance)){
      int start = std::max(check_array_from, i - distance);
      int end   = std::min(i + distance,(int)num_elements - 1);
      
      int j;
      for(j = start; j <= end; j++){
        if(array[j] < 0){
          int abs_value = (int)std::abs(array[j]);
          int min_index = (array[i] > abs_value) ? j : i;
          int max_index = (min_index == i) ? j : i;
          
          array[max_index] += array[min_index];
          array[min_index]  = 0;
        }
        //Moving the condition from for-loop header to here
        //as we need the j index
        if(array[i] <= 0){
          break;  
        }
      }
      check_array_from = j;
    }
  }
  
  long long sum = 0; 
  for(auto i : array){
    sum = sum + (int)std::abs(i); 
  }
  std::cout << sum;
  
  return 0;
}
