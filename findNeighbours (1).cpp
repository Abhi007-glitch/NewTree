#include <iostream>
#include <array>
#include <vector>


// INDEX representation

    // 0 -> xStart
    // 1 -> yEnd
    // 2 -> xEnd
    // 3 -> yEnd
    // 4 -> xStart
    // 5 -> yStart
    // 6 -> xEnd
    // 7 -> yStart


// checkY function will be used for leftNeighbors & rightNeighbors vector.
// checkX function will be used for topNeighbors & bottomNeighbors vector.

// vector arr represents the vector over which we will be iterating.

// zIndex represents the index of the box for which we are finding the neighbors.

// boxCoordinate is a table i.e vector of vectors that stores the coordinates of the boxes.

// resultArray is the vector that stores the indexes of all the boxes that are the neighbors of zIndex.




void checkY(std::vector <int>& arr, int zIndex, std::vector<std::vector<int>>& boxCoordinates, std::vector <int>& resultArray){

    for(int i = 0; i < sizeof(arr); i++){

        int checkIndex = arr[i];

        if(
            boxCoordinates[zIndex][7] <= boxCoordinates[checkIndex][1] <= boxCoordinates[zIndex][1] ||
            boxCoordinates[zIndex][7] <= boxCoordinates[checkIndex][7] <= boxCoordinates[zIndex][1]
            ){
                resultArray.push_back(i);
            }

    }
}

void checkX(std::vector <int>& arr, int zIndex, std::vector<std::vector<int>>& boxCoordinates, std::vector <int>& resultArray){

    for(int i = 0; i < sizeof(arr); i++){

        int checkIndex = arr[i];

        if(
            boxCoordinates[zIndex][0] <= boxCoordinates[checkIndex][0] <= boxCoordinates[zIndex][2] ||
            boxCoordinates[zIndex][0] <= boxCoordinates[checkIndex][2] <= boxCoordinates[zIndex][2]
            ){
                resultArray.push_back(i);
            }
            
    }
}

