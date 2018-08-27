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

  while(num_queries--){
    int left;
    int right;

    std::cin >> left >> right;
    long long sum = 0;
    for(int i = left-1; i < right; i++){
      sum += array[i];
    }
    std::cout << sum/(right - left + 1) << "\n";
  }
  return 0;  
}
