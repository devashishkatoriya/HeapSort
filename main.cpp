//Program to implement Heap Sort

/*
 * Created by Devashish Katoriya on 14-03-2017
 */

#include <iostream>

using namespace std;

#define LIMIT 30

class Heap
{
    int a[LIMIT],n;
    void reHeapUp();
public:
    Heap()
    {
        n = 0;
        for(int i=0;i<LIMIT;i++)
            a[i] = 0;
    }
    inline bool isFull()
    {
        return n == LIMIT-1;
    }
    inline bool isEmpty()
    {
        return n == 0;
    }
    void clr()
    {
        n = 0;
        for(int i=0;i<LIMIT;i++)
            a[i] = 0;
    }
    void insert();
    void display();
    void sort();
};

void Heap::sort()
{
    if(isEmpty())
    {
        cout<<"\nHeap is Empty!";
        return;
    }
    int temp[LIMIT],i,j,N;
    for(i=0;i<n;i++)
        temp[i] = a[i];
    N = n;
    
    cout<<"\nThe Array in Descending Order is :- \n";
    for(i=0;i<N;i++)
    {
        cout<<a[0]<<"\t";
        for(j=0;j<n-1;j++)
        {
            a[j] = a[j+1];
        }
        n--;
        reHeapUp();
    }
    
    n = N;
    for(i=0;i<n;i++)
        a[i] = temp[i];
}

void Heap::reHeapUp()
{
    int i,j,k,root;
    for(i=1;i<n;i++)
    {
        root = a[i];
        j = i;
        k = (j-1)/2;
        while(j>0 && a[k]<root)
        {
            a[j] = a[k];
            j = k;
            k = (j-1)/2;
        }
        a[j] = root;
    }
}

void Heap::insert()
{
    int element;
    cout<<"\nEnter element : ";
    cin>>element;
    if(!isFull())
    {
        a[n++] = element;
        reHeapUp();
        cout<<"\nElement inserted Successfully!";
    }
    else
        cout<<"\nHeap is Full!";
}

void Heap::display()
{
    if(isEmpty())
    {
        cout<<"\nHeap is Empty!";
        return;
    }
    cout<<"\nThe contents of Heap are :- \n";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<"\t";
    }
}

int main()
{
    Heap obj;
    int ch;
    char choice;
    cout<<"\nProgram to implement Heap Sort.";
    do
    {
        ch = 0;
        choice = 'n';
        cout<<"\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        cout<<"\n 1 for Insertion";
        cout<<"\n 2 for Display";
        cout<<"\n 3 for Sorting";
        cout<<"\n 4 for Is-Full";
        cout<<"\n 5 for Is-Empty";
        cout<<"\n -1 to Clear Heap";
        cout<<"\n  0 to Exit";
        cout<<"\nEnter your choice : ";
        cin>>ch;
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        switch(ch)
        {
            case 1 : obj.insert();
                break;
            case 2 : obj.display();
                break;
            case 3 : obj.sort();
                break;
            case 4 : if(obj.isFull())
                    cout<<"\nThe Heap is Full!";
                else
                    cout<<"\nThe Heap is Not full.";
                break;
            case 5 : if(obj.isEmpty())
                    cout<<"\nThe Heap is Empty!";
                else
                    cout<<"\nThe Heap is Not empty.";
                break;
            case -1: cout<<"\nAre you sure, you want to clear Heap (y/n) ? ";
                cin>>choice;
                if(choice == 'y' || choice == 'Y')
                {
                    obj.clr();
                    cout<<"\nHeap cleared Successfully!";
                }
                else
                    cout<<"\nCancelled!";
            case 0 : break;
            default: cout<<"\nInvalid Option!";
        }
        
    }while(ch!=0);
    
    cout<<"\n\nThank you for using this program :)\n\n";
    return 0;
}

/* OUTPUT

Program to implement Heap Sort.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 1 for Insertion
 2 for Display
 3 for Sorting
 4 for Is-Full
 5 for Is-Empty
 -1 to Clear Heap
  0 to Exit
Enter your choice :1
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Enter element :12

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 1 for Insertion
 2 for Display
 3 for Sorting
 4 for Is-Full
 5 for Is-Empty
 -1 to Clear Heap
  0 to Exit
Enter your choice :1
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Enter element :213

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 1 for Insertion
 2 for Display
 3 for Sorting
 4 for Is-Full
 5 for Is-Empty
 -1 to Clear Heap
  0 to Exit
Enter your choice :1
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Enter element :126

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 1 for Insertion
 2 for Display
 3 for Sorting
 4 for Is-Full
 5 for Is-Empty
 -1 to Clear Heap
  0 to Exit
Enter your choice :1
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Enter element :4

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 1 for Insertion
 2 for Display
 3 for Sorting
 4 for Is-Full
 5 for Is-Empty
 -1 to Clear Heap
  0 to Exit
Enter your choice :1
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Enter element :156

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 1 for Insertion
 2 for Display
 3 for Sorting
 4 for Is-Full
 5 for Is-Empty
 -1 to Clear Heap
  0 to Exit
Enter your choice : 1
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Enter element :1269

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 1 for Insertion
 2 for Display
 3 for Sorting
 4 for Is-Full
 5 for Is-Empty
 -1 to Clear Heap
  0 to Exit
Enter your choice : 1
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Enter element :126

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 1 for Insertion
 2 for Display
 3 for Sorting
 4 for Is-Full
 5 for Is-Empty
 -1 to Clear Heap
  0 to Exit
Enter your choice : 2
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

The contents of Heap are :-
1269    156     213     4       12      126     126

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 1 for Insertion
 2 for Display
 3 for Sorting
 4 for Is-Full
 5 for Is-Empty
 -1 to Clear Heap
  0 to Exit
Enter your choice : 3
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

The Array in Descending Order is :-
1269    213     156     126     126     12      4

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 1 for Insertion
 2 for Display
 3 for Sorting
 4 for Is-Full
 5 for Is-Empty
 -1 to Clear Heap
  0 to Exit
Enter your choice : 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Thank you for using this program :)
 
*/