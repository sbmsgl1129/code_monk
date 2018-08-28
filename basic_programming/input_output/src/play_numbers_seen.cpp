#include <iostream>
#include <vector>


int main(){
  int size, num_queries;

  std::cin >> size;
  std::cin >> num_queries;

  std::vector<int> array(size,0);
  for(int i = 0; i < size; i++){
    int element;
    std::cin >> element;
    array[i] = element;
  }

  std::vector<long long> sum_array(size+1,0);
  sum_array[0] = array[0];
  for(int i = 1; i <= size; i++){
    sum_array[i] = sum_array[i-1] + array[i-1];
  }

  while(num_queries--){
    int left;
    int right;

    std::cin >> left >> right;
    std::cout << (sum_array[right] - sum_array[left - 1])/(right - left + 1) << "\n";
  }
  return 0;  
}
