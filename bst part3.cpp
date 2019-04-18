#include<iostream>
using namespace std;

//class for a node
class Node{
	//make class public
	public:
		int data;
		Node*left;
		Node*right;
		Node*p;
		
		//defult constructor
		Node(int value){
			data=value;
			left=NULL;
			right=NULL;
			p=NULL;
		}
};
//calss for binary search tree
class BST{
	//make class public
	public:
		Node*root;
		int i;
		//default constructor
		BST(){
			root=NULL;
			i=0;
		}
		
		//insert
		void insert(int value){
			insert2(root,value);
		}
		void insert2(Node*current, int value){
			//if root=null
			if(root==NULL){
				current=new Node(value);
				i++;
				
				root=current;
			}
			else if(value<current->data){
				if(current->left==NULL){
					current->left=new Node(value);
					i++;
					current->left->p=current;
					
					current=current->left;
				}
				else{
					insert2(current->left,value);
					
				}
			}
			else if(value>current->data){
				if(current->right==NULL){
					current->right=new Node(value);
					i++;
					current->right->p=current;
					current=current->right;
				}
				else{
					insert2(current->right,value);
					
				}
			}
		}
		//display
	void display(){
		display2(root);
	}
	void display2(Node*current){
		if(current==NULL){
			return;
		}
		else{
			display2(current->left);
			cout<<current->data<<",";
			display2(current->right);
			return;
		}
	}
		
		//count
		int count(){
			return i;
		}
		//search
		Node* search(int value){
		
			return search2(root,value);
		}
		
		Node* search2(Node*current,int value){
			//base condition
			if(current==NULL||root==NULL){
				return current;
			}
			else{
				if(value<current->data){
					
						search2(current->left,value);
					
				}
				else{
					if(value==current->data){
						return current;
						//cout<<*current;
					}
					else{
						search2(current->right,value);
					}
				}
			}
		}
	
	
	//find minimum
	Node* fmin(int value){
		return fmin2(search(value),value);
	}
	Node* fmin2(Node*current,int value){
		//Node*current=search(value);
		if(current->left==NULL){
			return current;
		}
		else{
			fmin2(current->left,value);
		}
	}
		
	void Delete(int value){
		Delete2(root,value);
		i--;
	}
	
	void Delete2(Node*current,int value){
		//search the node to be deleted
		current=search(value);
		//replace it with its immediate succesor or predecessor
		//delete 
		//parent with no children
		if(!current->left&&!current->right){
			if(current->data<current->p->data){
				current->p->left=NULL;
			}
			else{
				current->p->right=NULL;
			}
			delete current;
		}
		//parent with 1 child
		else if(!current->left&&current->right||!current->right&&current->left){
			//if left child exists
			if(current->left){
				current->left->p=current->p;
				current->p->left=current->left;
				
			}
			//if right child exists
			if(current->right){
				current->right->p=current->p;
				current->p->right=current->right;
			}
			delete current;
		}
		//parent with 2 children
		else if(current->left&&current->right){
			Node*temp=fmin(current->right->data);
			current->data=temp->data;
			//if temp has right child
			if(temp->right){
				temp->right->p=temp->p;
				temp->p->right=temp->right;
				
				
			}
			temp->p->left=NULL;
				temp->p=NULL;
				delete temp;
			
			
		}
	}
		
		//height
		int height(){
			return height2(root);
		}
		int height2(Node*current){
			if(current==NULL){
				return 0;
			}
			else{
				int lh=height2(current->left);
				int rh=height2(current->right);
				
				if(lh>rh){
					return lh+1;
				}
				else{
					return rh+1;
				}
			}
		}
				
		
		
};


int main(){
	
	BST b1;
	b1.insert(10);
	b1.insert(1);
	b1.insert(13);
	b1.insert(4);
	b1.insert(11);
	b1.insert(5);
	b1.insert(3);
	b1.insert(0);
	b1.Delete(10);
	b1.display();
	cout<<endl;
	cout<<b1.count()<<endl;
	cout<<b1.search(4)<<endl;
	cout<<b1.height()<<endl;
	b1.printrange(0,11);
	
	
	return 0;
}
