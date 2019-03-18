#include<iostream>
using namespace std;

//class node
class Node{
	//make the class public
	public:
		//data
		int data;
		//2 pts to point to children
		Node*left;
		Node*right;
	//constructor
	Node(int value){
		data=value;
		left=NULL;
		right=NULL;
	}
};

//class tree
class Bist{
	//make the class public
	public:
		Node*root;
		
	//constructor	
	Bist(){
		root=NULL;
	}
	
	//insert
	void insert(int value){
		insertHelper(root,value);
	}
	//insertHelper
	void insertHelper(Node*current,int value){
		//if root==null
		if(current==NULL){
			current=new Node(value);
			if(root==NULL){
				root=current;
			}
		}
		//if root not = NULL check for inequality
		//if value<current move to left
		else if(value<current->data){
			if(current->left==NULL){
				//create a new node
				current->left=new Node(value);
			}
			else{	
				//if current is not = null, then 		
				insertHelper(current->left,value);
			}
		}
		else{
			if(current->right==NULL){
				//else move right and call insertHelper
				current->right=new Node(value);
			}
			else{
				insertHelper(current->right,value);
				//cout<<"****";
			}
		
		}
			
		
	}
	//display
	void Display(){
		Display2(root);
	}
	
	void Display2(Node*current){
		//base condition, is tree is empty or is current is null
		if(current==NULL){
			return;
		}
		else{
		//if tree is not empty the first display left node 
			Display2(current->left);
		//then center node 	
			cout<<current->data<<",";
		//then right node	
			Display2(current->right);
			
			return;
		}
	}
	//search
	Node* Search(int value){
		Search2(root,value);
	}
	
	Node* Search2(Node*current,int value){
		//comparing values to check if it is on right or left of current
		if(value<current->data){
			Search2(current->left,value);
		}
		else if(value==current->data){
			return current;
		}
		else if(value>current->data){
			Search2(current->right,value);
		}	
	}
	
	
};
//main
int main(){
	Bist b1;
	//calling functions
	b1.insert(10);
	b1.insert(3);
	b1.insert(12);
	b1.insert(13);
	b1.insert(0);
	b1.insert(11);
	b1.Display();
	cout<<b1.Search(13);
	
	
	return 0;
}
