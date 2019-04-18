/*
2 Rules for Binary Heap
- Its a complete tree. -> So you can use an array
- Either a max-heap or min-heap. 
Array Implementation 
Root - A[0]
Parent Node : Arr[(i-1)/2]
Left Child  : Arr[(2*i)+1]
Right Child : Arr[(2*i)+2]
Functions:
1. GetMin()
2. ExtractMin()
3. DecreaseKey()
4. Insert()
5. Delete()
6. Display()
*/

#include<iostream>
using namespace std;

class BinaryHeap{
    public:
    // Pointer to array of elements
    int * hArr;
    // Maximum possible size of array
    int mSize;
    // Current size of array 
    int cSize;

    BinaryHeap(int mSize){
        // Constructor 
        hArr = new int[mSize];
        this->mSize = mSize;
        cSize = 0;
    }

    void swap(int *a, int *b){
        // Swap elements ... 
        int temp = *a; 
        *a = *b; 
        *b = temp;
    }
    
    int parent(int i){ return (i-1)/2;}
    int left(int i){ return (i*2)+1;}
    int right(int i){ return (i*2)+2;}

    int getMin(){ return hArr[0]; }

    void insert(int value){
        // Base case. for Heap Overflow
        if(cSize>mSize)
        return;
        // Insert the new key at the end.
        else
        {
            hArr[cSize]=value;//insert at the end
            cSize++;//increase current size
        //Check it for all hierarchy with loop
            int i=cSize;//starting index
            if(i-1!=0)//if only one element is present
            {
                while(i-1>0)//loop to check whether current index reached the root
                {
                //Check if it breaks the heap property and fix it.
                    if(hArr[i-1]<hArr[parent(i-1)])//condition
                    {
                        swap(&hArr[i-1],&hArr[parent(i-1)]);//swap the parent and child
                    }
                    i--;//decrease the index by one
                }
            }
        }
    }
    void display(){
        // Display the array
        for(int i=0;i<cSize;i++)
        cout<<hArr[i]<<" ";
    }

    int extractMin() 
    { 
        // Base case for Empty Heap
        if(cSize==0)
        return 0;
        // Base case for Heap with 1 value.
        else if(cSize==1)
        {
            return hArr[0];
            cSize--;
        }
        else
        {
            int x=hArr[0];
        // Copy the last element to the root.
            hArr[0]=hArr[cSize-1];
            cSize--;
        // Call MinHeapify on root. 
            MinHeapify(0);
        // Return the min (Store it, before you replace the root with the last element)
            return x;
        }
    }

    void decreaseKey(int i, int new_val) 
    { 
        // Algorithm for what happens when I reduce the value of an element indexed at i to new_val. You can assume new_val to be less than the present value of the element. 
        hArr[i] = new_val; 
        // Loop for correcting the Property 2.
        while(i>0)
        // Compare with parent and move up till i == 0 or there is no violation.
        {
            if(hArr[i]<hArr[parent(i)])
            {
                swap(&hArr[i],&hArr[parent(i)]);
                i=parent(i);//change index to its parent's index
            }
        }

    } 
    // Deletes the element indexed at i. 
    void deleteKeyAt(int i) 
    { 
        // Decrease the value to INT_MIN at index i use decreaseKey()
        decreaseKey(i,getMin()-1);
        // Call ExtractMin
        extractMin();
    }

    void MinHeapify(int i) 
    { 
        // Compare with left and right 
        if(hArr[i]>hArr[left(i)] && hArr[i]>hArr[right(i)])
        {
        // Replace with the smallest.
            if(hArr[left(i)]<hArr[right(i)])
            {
                swap(&hArr[i],&hArr[left(i)]);
                // Call MinHeapify at the replaced child.
                MinHeapify(left(i));
            }
            else
            {
                swap(&hArr[i],&hArr[right(i)]);
                // Call MinHeapify at the replaced child.
                MinHeapify(right(i));
            }
        }
        else if(hArr[i]>hArr[left(i)] && (hArr[right(i)]==0 || hArr[i]<hArr[right(i)]))//if only left child is bigger than the parent
        {
            swap(&hArr[i],&hArr[left(i)]);
        }
    }

};


int main(){
    BinaryHeap bh1(20);
    for(int i = 10; i >0 ; i--){
        cout << "Inserting " << i << endl;
        bh1.insert(i);
        bh1.display();
        cout<<endl;
    }
    cout<<endl;
    cout<<"Display after extraction of min"<<endl;
    bh1.extractMin();
    bh1.display();
    cout<<endl;
    cout<<endl;
    cout<<"Display after deletion at index 3"<<endl;
    bh1.deleteKeyAt(3);
    bh1.display();
    cout << endl;
}
