Implement and simulate algorithm for Distance Vector Routing protocol or Link State Routing protocol

### Explanation for the Program:

This program implements the Distance Vector Routing algorithm to calculate and display the routing table for a network of routers. Here's an explanation of the program:

1. The program begins with the declaration of the necessary variables, including a 2D array `costMatrix` to store the cost between routers, an integer `n` to represent the number of routers, and a structure `routers` to store distance and adjacent node information for each router.

2. The function `readCostMatrix()` is responsible for taking input from the user for the cost matrix, which represents the cost between routers. It uses nested loops to iterate over each element in the matrix, reads the cost value, and populates the `costMatrix` array. It also initializes the distance and adjacent nodes arrays within the `node` structure.

3. The function `calcRoutingTable()` calculates the routing table using the Distance Vector Routing algorithm. It uses three nested loops to iterate over all possible paths between routers and compares the cost of the current path with the cost of the path via an intermediate router. If the intermediate path has a lower cost, it updates the distance and adjacent node information in the `node` structure.

4. The function `displayRoutes()` is responsible for displaying the routing table. It iterates over each router and prints the distance and adjacent node information for each destination node.

5. In the `main()` function, the user is prompted to enter the number of nodes (routers) in the network. Then, the `readCostMatrix()` function is called to input the cost matrix. Next, the `calcRoutingTable()` function is called to calculate the routing table. Finally, the `displayRoutes()` function is called to display the routing table.

The program takes input from the user, calculates the shortest paths using the Distance Vector Routing algorithm, and displays the routing table for the given network of routers.

In this program, the cost matrix represents the cost of communication between routers in a network. It is a 2D array `costMatrix[20][20]` where each element `costMatrix[i][j]` represents the cost of communication from router `i` to router `j`. 




When the user inputs the cost matrix, they provide the cost values for each pair of routers. For example, if there are three routers (0, 1, 2), the user would input the cost values for the following connections:

- Cost from router 0 to router 0: `costMatrix[0][0]`
- Cost from router 0 to router 1: `costMatrix[0][1]`
- Cost from router 0 to router 2: `costMatrix[0][2]`
- Cost from router 1 to router 0: `costMatrix[1][0]`
- Cost from router 1 to router 1: `costMatrix[1][1]`
- Cost from router 1 to router 2: `costMatrix[1][2]`
- Cost from router 2 to router 0: `costMatrix[2][0]`
- Cost from router 2 to router 1: `costMatrix[2][1]`
- Cost from router 2 to router 2: `costMatrix[2][2]`

The cost values represent the metric used to determine the best path between routers. The program then uses the Distance Vector Routing algorithm to calculate the shortest paths and populate the `node` structure with distance and adjacent node information.
