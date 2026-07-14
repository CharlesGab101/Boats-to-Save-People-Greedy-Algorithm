#include <iostream>
#include <vector>
#include "save_the_people_2_.cpp"
int main() {
  std::vector<int> people;
  int total_people = 0;

  std::cout << "Welcome to Boats to Save People Algorithm" << std::endl;
  while (true) {
    std::cout << "Enter the Maximum number of people: ";
    if (std::cin >> total_people) {
      break;
    } else {
      std::cout << "Invalid Input! Try Again\n" << std::endl;
      std::cin.clear();
      std::cin.ignore(9999, '\n');
    }
    
  }
  std::cout << "Enter the weights of each person" << std::endl;
    for (int i = 0; i < total_people; i++) {
      int temp_weights = 0;
      std::cout << "Person #" << i << ": ";
      if (std::cin >> temp_weights) {
        people.push_back(temp_weights);
      } else {
        std::cout << "Invalid Input! Try Again\n" << std::endl;
        std::cin.clear();
        std::cin.ignore(9999, '\n');
        i--;
      }
    }
    
     while (true) {
         std::cout << "Enter the limit weight of the boat: ";
    if (std::cin >> total_people) {
      break;
    } else {
      std::cout << "Invalid Input! Try Again\n" << std::endl;
      std::cin.clear();
      std::cin.ignore(9999, '\n');
    }
    
   
    }
    int output = save_the_people(people, total_people);
    
    std::cout << "Number of boats needed: " << output << std::endl; 
   
}