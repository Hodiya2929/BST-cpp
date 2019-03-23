#include<iostream>
#include "Tree.hpp"

/*
recursive insertion implementatin
void Tree::insert(int key){
root=insertHelper(key,root);
}
Node* Tree::insertHelper(int key, Node *node){
Node *temp=root;
if(temp==nullptr)
    return new Node(key);
else if(temp->data>key)
temp=insertHelper(key,temp->right);
else if(temp->data<key)
temp=insertHelper(key, temp->left);
else std::cout<<"Dont forget to throw an error! and to increment side";
}
*/

void ariel::Tree::insert(int key){//rare iterative implementation

if(Troot==nullptr){//tree has no nodes

    this->Troot= new Node(key); 
    this->sizeOf++;
    return;
}

//else tree as at least a root node

Node *curr=this->Troot;//holds the current node 
Node *parent=curr;//holds the parent of current node

while (curr!=nullptr){

parent=curr;

if(curr->data>key)
curr=curr->left;

else if(curr->data<key)
curr=curr->right;

//value exist already
else throw("Value exist already");
}

//check if left or right child
if(parent->data<key)
   parent->right=new Node(key);
else 
   parent->left=new Node(key);

this->sizeOf++;

}


//Iterative remove method

int ariel::Tree::remove(int key){

    if(this->Troot==nullptr)    //can't remove from empth tree
        throw "can't remove from an empty tree";
    
//we must have the parent node if we want to remove the parent pointer

        Node *nodeToDelete=this->Troot;
        Node *parent=nodeToDelete;
  
            while (nodeToDelete!=nullptr){

                parent=nodeToDelete;

//must check null poiner, otherwise segmantation fault

               if (nodeToDelete!=nullptr && nodeToDelete->data<key)
               nodeToDelete=nodeToDelete->right;

               else if(nodeToDelete!=nullptr && nodeToDelete->data>key)
               nodeToDelete=nodeToDelete->left;
            

             if(nodeToDelete!=nullptr && nodeToDelete->data==key)
                   return  removeHelper(nodeToDelete, parent, key);

            }

            //value doesnt exist in the tree
 throw "scanned the tree and didn't find the value";
}

void ariel::Tree::print(){

if(this->Troot==nullptr)
     throw "nothing to print, tree is empty";
//call for recursice inorder print
this->printHelper(Troot);
}

int ariel::Tree::size() const{
    return sizeOf;
}

//empty constructor
ariel::Tree::Tree(){
this->Troot=nullptr;
this->sizeOf=0;
}

//empty destructor
ariel::Tree::~Tree(){
deleteHelper(Troot);//call for recursive deletion
}

int ariel::Tree::root() const{

if(this->Troot==nullptr){
    throw "Tree is empty, no root";
}

return Troot->data;
}

bool ariel::Tree::contains(int key){

Node *curr=this->Troot;

while(curr!=nullptr){//if differs from nullptr we can access left & right
if(curr->data==key)
    return true;

else if(curr->data > key)
    curr=curr->left;

else curr=curr->right;

}

return false;
}

int ariel::Tree::left(int key) const{

if(contains(key)){

Node *curr=this->Troot;

while(curr!=nullptr){

if(curr->data==key){
    if(!isEmpty(curr->left))
        return curr->left->data;
    else throw "Tree's left child is empty";    
}
else if(curr->data > key)
    curr=curr->left;

else curr=curr->right;

  }
}
throw "Tree dosen't contains the inserted value";
}

bool ariel::Tree::isEmpty(Node *node){
return(node==nullptr);
}

int ariel::Tree::right(int key) const{

if(contains(key)){

Node *curr=this->Troot;

while(curr!=nullptr){

if(curr->data==key){
    if(!isEmpty(curr->right))
        return curr->right->data;
    else throw "Tree's right child is empty";  
}

else if(curr->data > key)
    curr=curr->left;

else curr=curr->right;

    }
}
throw "Tree dosen't contains the inserted value";
}

int ariel::Tree::parent(int key) const{

if(contains(key)){

if(Troot->data==key)
    throw "Root not doesnt have a parent";

Node *node=Troot;
Node *parent=node;
 
 while(node!=nullptr){
parent=node;

if(node->data > key)
    node=node->left;
else if(node->data < key)
    node=node->right;

if(node->data==key)
     return parent->data;
 }
}

throw "Tree dosen't contains the inserted value";
}

int ariel::Tree::findMin(Node *node) const{//based on BST tree - looks for the most left child of current node

    if(node->left==nullptr)
    return node->data;
    else return findMin(node->left);
    }

