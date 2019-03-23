
#include <iostream>


namespace ariel{//Tree class is in 'ariel' namespace;

class Tree {

struct Node { //Node struct present 1 node in a tree
public: 

 int data;
 Node *left;
 Node *right;
 
 Node(int key){
     data=key;
     left=nullptr;
     right=nullptr;
 }
};//end of struct Node

    private://must be private.

    Node *Troot;
    int sizeOf;

    int removeHelper(Node *node, Node *parent, int key){//private method in use of the standart 'remove' method

        int data=node->data;//value to return 
        char child; //determine if left child, right child or root 
        

        if(parent->right==node)
        child='r';

        else if (parent->left==node) child='l';

        else child='s' ; //root==node==parent

    if(node->left==nullptr&&node->right==nullptr){//a leaf node -can't just remove but to update parent node again
   
    if(child=='r')
               parent->right=nullptr;
    
    else if(child=='l') 
                parent->left=nullptr;

    else Troot=nullptr;

    sizeOf--;

    delete node;

    }

    else if(node->left==nullptr){ //left side is null - we want the parent to connet his right sub tree

        if(child=='r')
            parent->right=node->right;
        else if(child=='l')
               parent->left=node->right;
        else
            Troot=Troot->right;
        

    sizeOf--;
    delete node;

    }

    else if(node->right==nullptr){//same as left side
         if(child=='r')
              parent->right=node->left;
         else if(child=='l')
               parent->left=node->left;
          else Troot=Troot->left;

       sizeOf--;
       delete node;
    }

    else {//this node has two children

    int min=findMin(node->right);//return the min value in his right sud-tree
    remove(min);//remove the min value node in the right sub-tree
    node->data=min;//change the current node to have this value
    }
        return data;//return the value of the node that was removed
    }

/* the next private method is print helper - we need it in order to match the print defintion in the header file.
this is a recursive method which traverse the tree Inorder. In case of binary search trees (BST), Inorder traversal
 gives nodes in non-decreasing order*/


void printHelper(Node *node){

if(node==nullptr)
return ;

printHelper(node->left);

std::cout<<"Value: " << node->data <<" ";

printHelper(node->right);
}

 //called by the three destructor.
 //implemented by recursion

void deleteHelper(Node *node){

if(node==nullptr)
return;

deleteHelper(node->left);
deleteHelper(node->right);

delete node;
}

    //public method declarations
    
   public:

    Tree();
    ~Tree(); 
    void insert(int key);
    int remove(int key); 
    int size() const; 
    bool contains (int key) const;
    int root() const;
    int parent(int key) const;
    int left(int key) const;
    int right(int key) const;
    void print(); 
    bool isEmpty(Node *node) const;
    int findMin(Node *node) const;

};

} 

    



