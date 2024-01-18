#include<iostream>
using namespace std;

class MaxHeap{
    public:
    int arr[250];
    int size;

    MaxHeap(){
        size = 0;
    }

    void insertInHeap(int val){
        int index = size;
        size++;

        arr[index] = val;

        while(index > 0){
            int parentIndex = (index-1)/2;

            if(arr[parentIndex] <= arr[index]){
                swap(arr[parentIndex],arr[index]);
                index = parentIndex;
            }
            else{
                break;
            }
        }
    }

    void print() {
        for(int i=0; i<size; i++) {
            cout << arr[i] <<" ";
        }cout << endl;
    }

    void heapify(int index){
        int largest = index;
        int left = 2*index + 1;
        int right = 2*index + 2;

        if(left < size && arr[largest] < arr[left]){
            largest = left;
        }

        if(right < size && arr[largest] < arr[right]){
            largest = right;
        }

        if(largest != index){
            swap(arr[largest],arr[index]);
            heapify(largest);
        }
    }

    void deleteFromHeap(){
        if(size == 0){
            cout<<"Empty";
            return;
        }

        swap(arr[0],arr[size-1]);
        size--;

        heapify(0);        
    }
};

int main(){
    MaxHeap m;

    m.insertInHeap(2);
    m.print();
    m.insertInHeap(6);
    m.print();
    m.insertInHeap(8);
    m.print();
    m.insertInHeap(3);
    m.print();
    m.insertInHeap(7);
    m.print();

    m.deleteFromHeap();
    m.print();
    m.deleteFromHeap();
    m.print();
    m.deleteFromHeap();
    m.print();
    m.deleteFromHeap();
    m.print();
    m.deleteFromHeap();
    m.print();
    m.deleteFromHeap();
    m.print();
}
