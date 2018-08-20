#include <iostream>
#include <unordered_map>
#include <string>

void printFacingSeatAndType(int seat_num){
  
  std::unordered_map<int, int> facing_seats = { {1,12}, {2,11}, {3,10}, 
                                                {4,9},  {5,8},  {6,7},
                                                {7,6},  {8,5},  {9,4},
                                                {10,3}, {11,2}, {12,1}
                                              };
  std::unordered_map<int,std::string> seat_type = { {1,"WS"},  {2,"MS"},  {3,"AS"},
                                               {4,"AS"},  {5,"MS"},  {6,"WS"},
                                               {7,"WS"},  {8,"MS"},  {9,"AS"},
                                               {10,"AS"}, {11,"MS"}, {12,"WS"}
                                              };
  
  int compartment_num    = seat_num/12;
  int compartment_offset = seat_num%12;
  if(compartment_offset == 0){
    compartment_offset = 12;
    compartment_num    = compartment_num - 1;
  }

  int facing_seat_offset  = facing_seats[compartment_offset];
  int facing_seat = compartment_num*12 + facing_seat_offset;
  
  std::string facing_seat_type    = seat_type[facing_seat_offset];

  std::cout << facing_seat << " " << facing_seat_type << "\n";
}

int main(){
  int test_cases;
  int seat_num;

  std::cin >> test_cases;

  while(test_cases--){
    std::cin >> seat_num;
    printFacingSeatAndType(seat_num);  
  }

  return 0;
}
