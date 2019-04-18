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
					if(value==current->data){
						//cout<< *current;
						return current;
					}
					else{
						search2(current->left,value);
					}
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
	
	//range
	void printrange(int low,int high){	
		printrange2(root,low,high);
	}
	void printrange2(Node* curr,int low,int high){
		//Base condition
		if(curr == NULL){return;}
		//print left
		printrange2(curr->left,low,high);
		//print current if within range
		if((curr->data)>=low && (curr->data)<=high){
			cout << curr->data << ",";
		}
		//print right
		else{
			printrange2(curr->right,low,high);
		}
	}

	//count within range
	int rangecount(int low,int high){	
		return rangecount2(root,low,high);
	}

	int rangecount2(Node* current,int low,int high){
		//Base case
		if(current==NULL){return 0;}
		
		if(current->data == high && current->data == low){
			return 1;
		}

		//If current node in range include in count and apply recursion for left and right 	children
		if((current->data)<=high && (current->data)>=low){
			return 1 + rangecount2(current->left,low,high) + rangecount2(current->right,low,high);
		}

		//If current node is smaller than low 
		else if((current->data)<low){
			return rangecount2(current->right,low,high);
		}

		// left child recursion
		else{
			return rangecount2(current->left,low,high);
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
	b1.insert(2);
	b1.insert(13);
	b1.insert(3);
	b1.insert(11);
	b1.insert(1);
	b1.insert(0);
	b1.display();
	cout<<b1.count()<<endl;
	cout<<b1.search(0)<<endl;
	cout<<b1.height();
	b1.printrange(0,11);
	
	
	return 0;
}
