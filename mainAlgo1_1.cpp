#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <string>

#include "graph_1_.cpp"
#include "contruct_graph_1_.cpp"
#include "bfs_1_.cpp"

bool starting_position(int rows, int columns, std::string& starting_x, std::string& starting_y, std::vector<std::vector<int>>& matrix);
bool target_position(int rows, int columns, std::string& target_x, std::string& target_y, std::vector<std::vector<int>>& matrix);
int main() {
  int rows;
  int columns;
  std::vector<std::vector<int>> matrix;
  std::string starting_x = "0";
  std::string starting_y = "0";
  std::string target_x = "0";
  std::string target_y = "0";
  bool has_path = false;
  //Enter rows
  std::cout << "=============Welcome to Project 2 Maze============="
            << std::endl;

  while (true) {
    std::cout << "Enter Number of Rows: ";
    if (std::cin >> rows) {
      break;
    } else {
      std::cout << "Invalid Input! Try Again\n" << std::endl;
      std::cin.clear();
      std::cin.ignore(9999, '\n');
    }
  }
  //Enter columns
  while (true) {
    std::cout << "Enter Number of columns: ";
    if (std::cin >> columns) {
      break;
    } else {
      std::cout << "Invalid Input! Try Again\n" << std::endl;
      std::cin.clear();
      std::cin.ignore(9999, '\n');
    }
  }

  //Create a matrix grid
  matrix = std::vector<std::vector<int>>(rows,std::vector<int>(columns, 0)); // first initialize the matrix with zeros before putting something
   std::cout << "\n";
  std::cout << "=================Input 1s and 0s (1 = wall) and (0 for path)=================\n";
  for (int i = 0; i < columns; i++) {
    for (int j = 0; j < rows; j++) {
        int value;

        std::cout << "Enter value for postion [row][columns] = [" << i << "]" << "[" << j << "]: ";

        if (std::cin >> value && (value == 0 || value == 1)) {
        matrix[i][j] = value;
        } else if (!(value == 0 || value == 1)) {
            std::cout << "Invalid Input! Only 0s and 1s\n" << std::endl;
            std::cin.clear();
            std::cin.ignore(9999, '\n');
            j--; // redo this row
        } else {
            std::cout << "Invalid Input! Try Again\n" << std::endl;
            std::cin.clear();
            std::cin.ignore(9999, '\n');
            j--; // redo this row
        }
    }
    
  }
  std::cout << "\nMatrix:\n";

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < columns; c++) {
            std::cout << matrix[r][c] << " ";
            if (matrix[r][c] == 0) {
              has_path = true;
            }
        }
        std::cout << "\n";
    }

    if(has_path == false) {
      std::cout << "The matrix has no available paths" << std::endl;
      std::cout << "Aborting..." << std::endl;
      return 0;
    }
  
  // Set starting position
  std::cout << "\n=================Enter the Starting Position (sx, sy)=================\n";
  bool again = true;
  bool again2 = true;
  while (again) {
    bool try_ = starting_position(rows, columns, starting_x, starting_y, matrix);
    again = try_;
  } 
  // Set Target position
  std::cout << "\n\n=================Enter the Target Position (tx, ty)=================\n";
  while (again2) {
    bool try_2 = target_position(rows, columns, target_x, target_y, matrix);
    again2 = try_2;
  }

  Graph graph(rows * columns);
  graph.initialization(); // O(n)
  //conversion of matrix indexes to vertex numbers in graph from 0 to n - 1 (n = total # of vertices)
  contruct_graph(rows, columns, graph, matrix); // O(n^2) because it checks every index in the matrix

  int sx = std::stoi(starting_x);
  int sy = std::stoi(starting_y);
  int tx = std::stoi(target_x);
  int ty = std::stoi(target_y);

  int starting_num = sx * columns + sy; //convert [][] into node number 
  int target_num = tx * columns + ty; //convert [][] into node number 
  int number_moves = bfs_minimum_moves(starting_num, target_num, graph, rows * columns);

  std::cout << "\n\nTotal of Minimum Number of Moves: " << number_moves << std::endl;


  //int num = graph.checkEdge(0, 1);

 // std::cout << num << std::endl;
   return 0;
  
}
//=====================================================================================================================
  bool starting_position(int rows, int columns, std::string& starting_x, std::string& starting_y, std::vector<std::vector<int>>& matrix) {
  int x = std::stoi(starting_x);
  int y = std::stoi(starting_y);

     while (true) {
    
    std::cout << "Enter the Starting Position for x (e.g x = 0): ";
    if (std::cin >> x && x < rows) {
      break;
    } else if(x >= rows){
      std::cout << "Out of Bounds! Try Again\n" << std::endl;
      std::cin.clear();
      std::cin.ignore(9999, '\n');
    } else {
      std::cout << "Invalid Input! Try Again\n" << std::endl;
      std::cin.clear();
      std::cin.ignore(9999, '\n');
    }
  }
    while (true) {
      
      std::cout << "Enter the Starting Position for y (e.g y = 0): ";
      if (std::cin >> y && y < columns) {
        break;
      } else if(y >= columns){
        std::cout << "Out of Bounds! Try Again\n" << std::endl;
        std::cin.clear();
        std::cin.ignore(9999, '\n');
      } else {
        std::cout << "Invalid Input! Try Again\n" << std::endl;
        std::cin.clear();
        std::cin.ignore(9999, '\n');
      }
    }

    if (matrix[x][y] == 0 ) {
        starting_x = std::to_string(x); 
        starting_y = std::to_string(y);
      return false;
    } else {
      std::cout << "\nCannot position to wall. Try again!\n\n";
        std::cin.clear();
        std::cin.ignore(9999, '\n');
      return true;
    }
  }
  bool target_position(int rows, int columns, std::string& target_x, std::string& target_y, std::vector<std::vector<int>>& matrix) {
    int x = std::stoi(target_x);
    int y = std::stoi(target_y);
     while (true) {
    
    std::cout << "Enter the Target Position for x (e.g x = 0): ";
    if (std::cin >> x && x < rows) {
      break;
    } else if(x >= rows){
      std::cout << "Out of Bounds! Try Again\n" << std::endl;
      std::cin.clear();
      std::cin.ignore(9999, '\n');
    } else {
      std::cout << "Invalid Input! Try Again\n" << std::endl;
      std::cin.clear();
      std::cin.ignore(9999, '\n');
    }
  }
    while (true) {
      
      std::cout << "Enter the Target Position for y (e.g y = 0): ";
      if (std::cin >> y && y < columns) {
        break;
      } else if(y >= columns){
        std::cout << "Out of Bounds! Try Again\n" << std::endl;
        std::cin.clear();
        std::cin.ignore(9999, '\n');
      } else {
        std::cout << "Invalid Input! Try Again\n" << std::endl;
        std::cin.clear();
        std::cin.ignore(9999, '\n');
      }
    }

    if (matrix[x][y] == 0 ) {
        target_x = std::to_string(x); 
        target_y = std::to_string(y);
      return false;
    } else {
      std::cout << "\nCannot position to wall. Try again!\n\n";
        std::cin.clear();
        std::cin.ignore(9999, '\n');
      return true;
    }
  }