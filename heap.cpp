#include<iostream>
using namespace std;


class heap {
  public:
  int arr[100];
  int size;

  heap()
  {
    arr[0] = -1;
    size = 0;
  }


  void insert(int val)
  {
    size = size + 1;
    int index = size;
    arr[index] = val;

    while(index > 1)
      {
	int parent = index/2;
	
	if(arr[parent] < arr[index])
	  {
	    swap(arr[parent], arr[index]);
	    index = parent;
	  }
	else
	  {
	    return;
	  }
      }
  }


  void deleteRoot()
  {
    if(size == 0)
      {
	return;
      }

    arr[1] = arr[size];
    size--;

    int i = 1;
    while(i<size)
      {
	int left = 2 * i;
	int right = (2*i)+1;

	if(left < size && arr[i] < arr[left])
	  {
	    swap(arr[i], arr[left]);
	    i = left;
	  }
	else if(right < size && arr[i] < arr[right])
	  {
	    swap(arr[i], arr[right]);
	    i = right;
	  }
	else
	  {
	    return;
	  }
      }
    
  }


  void print()
  {
    for(int i=1; i<=size; i++)
      {
	cout<<arr[i]<<" ";
      }
    cout<<endl;
  }
};



int main()
{
  heap h;
  h.insert(50);
  h.insert(55);
  h.insert(53);
  h.insert(52);
  h.insert(54);

  h.deleteRoot();
  h.print();
  
  return 0;
}
