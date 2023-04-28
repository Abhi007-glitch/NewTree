#include <iostream>
#include <vector>
#include<algorithm>
#include<string>
#include "B+tree.h"
#include <cstdlib>
#include <array>

using namespace std;




void insertionMethod(BPTree** bPTree) {
    int key;   // id
    int value;  // age


    cout << "Please provide the key: ";
    cin >> key;

    cout << "\nEnter your value";
    cin >> value;

    

    (*bPTree)->insert(key, value);
    
    cout << "Insertion of roll No: " << key << " Successful"<<endl;
}

void searchMethod(BPTree* tree) {
    int id;
    cout << "What's the id to Search? ";
    cin >> id;

    tree->search(id);
}



void printMethod(BPTree* bPTree) {
    int type;
    cout<<"1.Level Order Traversal"<<endl;
    cout<<"2.Seqential Traversal "<<endl;

    
    cin>>type;
    if (type==1)
    {
    cout << "\nHere is your Tree Structure" << endl;
    bPTree->printTreeLevelOrder(bPTree->root);

    }
    else{
            cout << "\nHere is your Tree Structure" << endl;
   bPTree->printTree(bPTree->root);
    }   
        
}


void deleteMethod(BPTree* bPTree) {
    cout << "Showing you the Tree, Choose a key from here: " << endl;
    bPTree->printTree(bPTree->root);
 
    int keyTodelete;
    cout << "Enter a key to delete: " << endl;
    cin >> keyTodelete;
    bPTree->remove(keyTodelete);

    //Displaying
    bPTree->printTree(bPTree->root);
}


 
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

void checkY(std::vector <int> arr, int zIndex, std::vector<std::vector<int>> boxCoordinates, std::vector <int>& resultArray){

    for(int i = 0; i < arr.size(); i++){

        int checkIndex = arr[i];

        if(
            (boxCoordinates[zIndex][7] <= boxCoordinates[checkIndex][1]  &&  boxCoordinates[checkIndex][1] <= boxCoordinates[zIndex][1] )||
            (boxCoordinates[zIndex][7] <= boxCoordinates[checkIndex][7] &&  boxCoordinates[checkIndex][7] <= boxCoordinates[zIndex][1])
            ){
                resultArray.push_back(checkIndex);
            }

    }
}




void checkX(std::vector <int>& arr, int zIndex, std::vector<std::vector<int>>& boxCoordinates, std::vector <int>& resultArray){

    for(int i = 0; i < (arr.size()); i++){

        int checkIndex = arr[i];

        if(
        //    ( boxCoordinates[zIndex][0] <= boxCoordinates[checkIndex][0] &&  boxCoordinates[checkIndex][0]<= boxCoordinates[zIndex][2]) ||
        //     (boxCoordinates[zIndex][0] <= boxCoordinates[checkIndex][2]  &&  boxCoordinates[checkIndex][2]<= boxCoordinates[zIndex][2])
        ( boxCoordinates[zIndex][0] <= boxCoordinates[checkIndex][0] &&  boxCoordinates[checkIndex][0]<= boxCoordinates[zIndex][2]) ||
            (boxCoordinates[zIndex][0] <= boxCoordinates[checkIndex][2]  &&  boxCoordinates[checkIndex][2]<= boxCoordinates[zIndex][2])
            ){
                resultArray.push_back(checkIndex);
            }
            
    }
}

int main ()
{
    
    bool flag = true;
    int option;

    int internalNodeLen = 2, leafNodeLen = 2;  // some random intial value
    
   /// ******************* Intialize Trees **************************************** 
    BPTree* co_ordinate_BPTree = new BPTree(leafNodeLen, internalNodeLen);
    BPTree* start_x_Co_ordinate_BPTree = new BPTree(leafNodeLen, internalNodeLen);
    BPTree* end_x_Co_ordinate_BPTree = new BPTree(leafNodeLen, internalNodeLen);
    BPTree* start_y_Co_ordinate_BPTree = new BPTree(leafNodeLen, internalNodeLen);
    BPTree* end_y_Co_ordinate_BPTree = new BPTree(leafNodeLen, internalNodeLen);

  
    
    // **************** Inserting Spatial Data *****************************************
    vector<vector<int>> co_ordinates;

    // vector<int> p1 = {-4,2,0,2,-4,0,0,0};
    // vector<int> p2 = {-2,0,2,0,-2,-2,2,-2};
    // vector<int> p3 ={2,2,4,2,2,0,4,0};
    
    vector<int>p1 = {-6,6,2,6,-6,0,2,0};
    vector<int>p2 = {2,6,8,6,2,0,8,0};
    vector<int>p3 = {6,4,10,4,6,0,10,0};
    vector<int>p4 = {-10,2,-8,2,-10,0,-8,0};
    vector<int>p5 = {-4,0,0,0,-4,-6,0,-6};
    vector<int>p6 = {-12,-6,-4,-6,-12,-12,-4,-12};
    


    co_ordinates.push_back(p1);
    co_ordinates.push_back(p2);
    co_ordinates.push_back(p3);
    co_ordinates.push_back(p4);
    co_ordinates.push_back(p5);
    co_ordinates.push_back(p6);
    

   int idx=0;
  
   for ( vector<int> i :co_ordinates )
   {
     co_ordinate_BPTree->insert(idx,idx);
     start_x_Co_ordinate_BPTree->insert(i[0],idx);
     end_x_Co_ordinate_BPTree->insert(i[2],idx);
     start_y_Co_ordinate_BPTree->insert(i[5],idx);
     end_y_Co_ordinate_BPTree->insert(i[1],idx);
     
     idx++;
   }
   




//***************************************** Looking at B+Tree Formed for each start and end cordinates of all boxes *******************
// cout<<"Start X tree "<<endl;

// printMethod(start_x_Co_ordinate_BPTree);


// cout<<"end X tree "<<endl;
// printMethod(end_x_Co_ordinate_BPTree);

// cout<<"Start Y tree "<<endl;

// printMethod(start_y_Co_ordinate_BPTree);


// cout<<"end Y tree "<<endl;
// printMethod(end_y_Co_ordinate_BPTree);




 vector<int> end_X = end_x_Co_ordinate_BPTree->newSearch(-4,0);
 vector<int> end_Y = end_y_Co_ordinate_BPTree->newSearch(-6,0);
 vector<int> start_X = start_x_Co_ordinate_BPTree->newSearch(-4,0);
 vector<int> start_Y = start_y_Co_ordinate_BPTree->newSearch(-6,0);
  


//*****************************************Printing Match boxes in range of target box in each direction***************************


cout<<"Start Y : elements "<< start_Y.size()<<endl;
  for ( int i  : start_Y)
  {
     cout<<i<<" ";
  }

  cout<<endl;

  cout<<"end Y : elemets "<<end_Y.size()<<endl;
  for (int i: end_Y)
  {
    cout<<i<<" ";
  }
  cout<<endl;

  cout<<"start_X : elements "<<start_X.size()<<endl;
  
  for (int i: start_X)
  {
    cout<<i<<" ";
  }
  cout<<endl;

  cout<<" end_x : elements "<<end_X.size()<<endl;

  for ( int i : end_X)
  {
    cout<<i<< " ";
  }
  cout<<endl;
  


// /**
//  * left -X_end
//  * right - X_start
//  * Top - y-Start
//  * Bottom - y-end
//  * 
//  * **/


// **************** Generating Matching Boxes and printing box index*****************************************


vector<int> Xstart_selected ;

checkY(start_X,4,co_ordinates,Xstart_selected);
    
cout<<"Xstart_selected boxes : "<<Xstart_selected.size()<<endl;
for ( int i : Xstart_selected)
{
    cout<<i<<" , ";
}
cout<<endl;




vector<int>Xend_selected;
checkY(end_X,4,co_ordinates,Xend_selected);
cout<<"Xend_selected boxes : "<<Xend_selected.size()<<endl;
for ( int i : Xend_selected)
{
    cout<<i<<" , ";
}
cout<<endl;



vector<int>Ystart_Selected;
checkX(start_Y,4,co_ordinates,Ystart_Selected);
cout<<"Ystart_Selected boxes "<<Ystart_Selected.size()<<endl;
for ( int i : Ystart_Selected)
{
    cout<<i<<" , ";
}
cout<<endl;

vector<int>Yend_Selected;
checkX(end_Y,4,co_ordinates,Yend_Selected);
cout<<"Yend_Selected boxes "<<Yend_Selected.size()<<endl;
for ( int i : Yend_Selected)
{
    cout<<i<<" , ";
}
cout<<endl;

    return 0;

}





