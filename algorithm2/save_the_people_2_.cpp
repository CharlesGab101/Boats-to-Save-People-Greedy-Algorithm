#include <vector>
#include <algorithm>
//Note: This is greedy approach
int save_the_people(std::vector<int> people, int max_weight) {
    std::vector<int> A = people; //assign to A
    int total_size = A.size(); // get the size
    std::sort(A.begin(), A.end()); //sort the array
    std::reverse(A.begin(), A.end()); //reverse the array
    int total_weight = 0;
    int count = 1;
    for (int i = 0; i < total_size; i++) {
        if(total_weight + A[i] <= max_weight) { // compare the weights less than the max_weight
            total_weight += A[i]; //add weights
        } else { //if the weight is already full 
            count++; // count the boat need after full
            total_weight = A[i]; // reset for the next batch of people
        }
    }
    return count;
    
}   