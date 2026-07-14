#include <queue>
#include <vector>
int bfs_minimum_moves(int starting_node, int target, Graph& graph, int total_vertices) {
    std::vector<bool> is_visited(total_vertices, false);
    std::vector<int> steps(total_vertices, -1);

    std::queue<int> vertex;
    is_visited[starting_node] = true; //mark visited
    steps[starting_node] = 0; // set the starting vertex steps to 0
    vertex.push(starting_node); // push the starting vertex
    if (vertex.front() == target) { //stop immediately if the starting vertex and target vertex is already in the same position
        return steps[target];
    }
    while(!vertex.empty()) { 
        int current = vertex.front();
        vertex.pop();

      

        Node* temp_node = graph.getAdjacencylist()[current]; // get the edges of each vertex
        while(temp_node != nullptr) {
            if (is_visited[temp_node->getID()] == false) { //check if visited
                is_visited[temp_node->getID()] = true; //mark visited
                steps[temp_node->getID()] = steps[current] + 1; // record the steps for each vertex
                vertex.push(temp_node->getID());// push the vertex number 
            }
            temp_node = temp_node->getNext(); // iterates until it finds the target vertex
        }
    }
    return steps[target]; //returns the total steps of the target vertex


}