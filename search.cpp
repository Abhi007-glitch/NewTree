#include<iostream>
#include<vector>
#include<algorithm>
#include<B+tree.h>

using namespace std;


void BPTree :: search(int key)
{
 Node * cur = root;
 
 if (root==NULL)
 {
    cout<<"Tree is empty - no value present"<<endl;
 }

 while(!cur->isLeaf)
 {
    int idx = upper_bound(cur->keys.begin(),cur->keys.end(), key) - cur->keys.begin();
    cur =cur->childNode.treeptr[idx];
 }

 int idx= lower_bound(cur->keys.begin(),cur->keys.end(),key)-cur->keys.begin();

 if (idx==cur->keys.size() || cur->keys[idx]!=key)
 {
    cout<<"Value is not present in the b+Tree"<<endl;
 }

}



vector<int> BPTree :: newSearch(int key,int end)
{
   vector<int>ans;
   bool flag = false;
     if (root == NULL) {
        cout << "Tree is empty" << endl;
        return ans;
    } else {
        Node* cursor = root;
        while (cursor->isLeaf == false) {
            /*
				upper_bound returns an iterator pointing to the first element in the range
				[first,last) which has a value greater than key.(Because we are storing the
				same value in the right node;(STL is doing Binary search at back end)
			*/
            int idx = std::upper_bound(cursor->keys.begin(), cursor->keys.end(), key) - cursor->keys.begin();
            cursor = cursor->childNode.treeptr[idx];  //upper_bound takes care of all the edge cases
        }

        int idx = std::lower_bound(cursor->keys.begin(), cursor->keys.end(), key) - cursor->keys.begin();  //Binary search
      
        if (idx == cursor->keys.size() || cursor->keys[idx] != key) {
            
            cursor=cursor->next;
        }
        else 
        {
          cout<<"Key is present and it's value is : "<<cursor->childNode.dataptr[idx]<<" Key is"<<key<<endl;
          while(idx<cursor->keys.size())
          {
            if (cursor->keys[idx] < end)
            {
               ans.push_back(cursor->childNode.dataptr[idx]);
            }
            else 
            {
              flag=true;
              break;
            }
            idx++;
          }

          if (flag==false)
          {
            cursor=cursor->next;
          }
        }

        if (flag ==false)
        {
          while(cursor!=NULL && flag==false)
          {
            int size = cursor->keys.size();
            for ( int i=0;i<size;i++)
            {
               if (cursor->keys[i] < end)
            {
               ans.push_back(cursor->childNode.dataptr[i]);
            }
            else 
            {
              flag=true;
              break;
            }
            }
            cursor=cursor->next;
          }
        }
        return ans;

}
}