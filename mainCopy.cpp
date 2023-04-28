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


int main ()
{
    
    bool flag = true;
    int option;

    int internalNodeLen = 4, leafNodeLen = 3;  // some random intial value
    
    
    BPTree* co_ordinate_BPTree = new BPTree(leafNodeLen, internalNodeLen);
    BPTree* start_x_Co_ordinate_BPTree = new BPTree(leafNodeLen, internalNodeLen);
    BPTree* end_x_Co_ordinate_BPTree = new BPTree(leafNodeLen, internalNodeLen);
    BPTree* start_y_Co_ordinate_BPTree = new BPTree(leafNodeLen, internalNodeLen);
    BPTree* end_y_Co_ordinate_BPTree = new BPTree(leafNodeLen, internalNodeLen);

    // do {
    //     cout << "\nPlease provide the queries with respective keys : " << endl;
    //     cout << "\tPress 1: Insertion \n\tPress 2: Search \n\tPress 3: Print Tree\n\tPress 4: Delete! \n\tPress 5: End the program"<<endl;
    //     cin >> option;

    //     switch (option) {
    //         case 1:
    //             insertionMethod(&bPTree);
    //             break;
    //         case 2:
    //             searchMethod(bPTree);
    //             break;
    //         case 3:
    //             printMethod(bPTree);
    //             break;
    //         case 4:
    //             deleteMethod(bPTree);
    //             break;
    //         case 5:
    //             flag = false;
    //             break;
    //         default :
    //            cout<<"Please enter a vaild command "<<endl;
    //            break;
    //     }
    // }while (flag);

    
    vector<array<int,8>> co_ordinates;

    array<int,8> p1 = {{-4,2,0,2,-4,0,0,0}};
    array<int,8> p2 = {{-2,0,2,0,-2,-2,2,-2}};
    array<int,8> p3 ={{2,2,4,2,2,0,4,0}};

    co_ordinates.push_back(p1);
    co_ordinates.push_back(p2);
    co_ordinates.push_back(p3);


   int idx=0;
   cout<<"WHile inserting"<<endl;
   for ( array<int,8> i :co_ordinates )
   {
    //  co_ordinate_BPTree->insert(idx,idx);
     start_x_Co_ordinate_BPTree->insert(i[0],idx);
    //  end_x_Co_ordinate_BPTree->insert(i[2],idx);
    //  start_y_Co_ordinate_BPTree->insert(i[5],idx);
    //  end_y_Co_ordinate_BPTree->insert(i[1],idx);
     cout<<i[0]<<" "<<idx<<endl;
     idx++;
   }

   printMethod(start_x_Co_ordinate_BPTree);
//    printMethod(end_x_Co_ordinate_BPTree);
//    printMethod(start_y_Co_ordinate_BPTree);
//    printMethod(end_y_Co_ordinate_BPTree);
   
//    searchMethod(start_x_Co_ordinate_BPTree);

   
  vector<int> ans = start_x_Co_ordinate_BPTree->newSearch(-3,0);
  cout<<"VECTOR Size : "<<ans.size()<<endl;

  for ( int i : ans)
  {
    cout<<i<<""<<endl;
  }

    // vector<int>arr = {1,4,9,10,15,16,20,25,11,12,13};

    // for ( int i =0;i<arr.size();i++)
    // {
    //     bPTree->insert(arr[i],arr[i]);
    // }


   
    // int n ;
    // cin>>n;
    // int temp=0;
    // for ( int i =0;i<n;i++)
    // {
    //     temp = rand()%10000;
    //    (bPTree)->insert(temp, temp);
    // }

    // printMethod(bPTree);
    // // printMethod(bPTree);


    // for (int i=0;i<arr.size()-1;i++)
    // {
    //      bPTree->remove(arr[i]);
    // bPTree->printTreeLevelOrder(bPTree->root);
    // }
   
    
    // //  bPTree->remove(20);
    // // bPTree->printTreeLevelOrder(bPTree->root);
    return 0;

}





