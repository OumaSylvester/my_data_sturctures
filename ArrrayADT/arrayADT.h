#include<iostream>
#include<cassert>

using namespace std;

template<class elemType>
class arrayListType
{
public:
    const arrayListType<elemType>& operator= (const arrayListType<elemType>& otherList) //data type, name of function body
    {
        //Overloads the assignment operator

        if (this != &otherList) //avoid self-assignment
            copyOtherList(otherList);
        return *this; // return this to our current varible. The variable we are copying to
    }

    bool isEmpty() const
    {
        //Function to determine whether the list is empty
        //Postcondition: Returns true if the list is empty; otherwise, false
        return(length == 0);
    }

    bool isFull() const
    {
        //Function to determine whether the list is full
        //Postcondition: Returns  true if true if the array is full;
        // otherwise false
        return(length == maxsize);
    }

    int listSize() const
    {
        //Function to determine the number the number or elements in the list
        //Postcondition: Returns the value of leghth
        return length;
    }

    int maxListSize() const
    {
        //Function to determine the size of the list
        //Postcondition: Returns the value  of maxSize
        return maxsize;
    }

    void print() const
    {
        //Function to output the elements of the list
        //Postcondition: Elements of the list are output of on the standard output device
        for(int i=0; i<length; i++)
        {
            cout<<list[i]<<" ";
            cout<<endl;
        }
    }

    bool isItemEqual(int location, const elemType& item)
    {
        //Function to determine whether item is same the item in the list
        // at the position specified
        //Postcondition: Returns true if list[location] is same as the item;
        // otherwise false
        return (list[location] == item);
    }

    void insertAt(int location, const elemType& insertItem)
    {
        //Function to insert an item in the list at the  specified location.
         //Postcondition: Starting at location , the elements the list are shifted down,
         // list[location] = insertItem; and length++
         //If the list if full, an appropriate message is displayed
         if(location <0 || location >= maxsize)
         {
             cerr<<"The position of the item to be inserted id out of range"<<endl;

         }
         else
            if(length>=maxsize) //list if full
            {
                cerr<<"Cannot insert in a full list"<<endl;
            }
            else
            {
                for(int i=length; i>location; i--)
                {
                    list[i]  =list[i -1]; // the elements down >> to the right

                }
                list[location] = insertItem; //insert the item at the specified location
                length++;  //increment the lenght
            }
    }

    void insertEnd(const elemType& insertItem)
    {
        //Function to insert an item at the end of the list
        //The parameter insertItem specifies  the item to be inserted.
        //Postcondition: list[length]=insertItem; and length++
        //If the list if full, an appropriate error is displayed
        if(length >=maxsize) //the list is full
            cerr<<"Cannot insert in a full list"<<endl;
        else
        {
            list[length] = insertItem; // insert the item at the end
            length++; //increment the length
        }
    }

    void removeAt(int location)
    {
        //Function to remove the item from th list at the specified location
        //Postcondition: The list element at list[location] is removed leghth is decrement by 1
        //If location is out of range, an appropriate error message is displayed
        if(location <0 || location >=length)
         {
             cerr<<"The position of the item to be inserted id out of range"<<endl;

         }
         else
         {
             for(int i=location; i<length-1; i++)
             {
                 list[i] = list[i+1];
             }
             length--;
         }
    }

    void retrieveAt(int location, elemType& retItem)const // retItem passed as a reference so that it is set directly for the calling function
    {
        //Function to retrieve an element from the list at the position
        // specified
        //Postcondition: retItem = list[location]
        //If location is out of range, an appropriate error message is displayed
        if(location < 0 || location>= length)
            cerr<<"The location of the item the item to be retrieved is out of range."<<endl;
        else
            retItem = list[location];
    }

    void replaceAt(int location, const elemType& repItem)
    {
        //Function to replace the elements in the list at the position specified.
        //Postcondition: list[location] = repItem
        // If the location is out orange, an appropriate error message is displayed
        if (location < 0 || location >= length)
            cerr << "The location of the item to be replaced is out of range." << endl;
        else
            list[location]= repItem;
    }

    void clearList()
    {
        //Function to remove all the elements from the list
        //After this operation, the size of the list is zero: length = 0;
        length = 0; // this does not destroy the list but does not allow th user to access the old values
        //memory remains allocated unless the object is destroyed. Now if the user species a location it will always be greater than length which is 0.
        //Hence unable to access the elements
    }

    int seqSearch(const elemType& item) const
    {
        //Function to search the list for a given item.
        //Postcondition: if the item is found, returns the location in the
        // array where the item is found; otherwise false
        int loc;
        bool found = false;
        for(loc = 0; loc<length; loc++)
            if(list[loc] == item)
            {
                found = true;
                break;
            }
        if(found)
            return loc;
        else
            return -1; //return -1 to show that the item is not in the list

    }


    int insert(const elemType& insertItem)
    {
        //Function to insert the insertItem at the end of the list. However, first
        // the list is searched to see whether the item to be inserted is already in the list
        //Postcondition: list[length] = insertItem; length++
        //If an item is already in the list, or the list is full, an appropriate
        // error message is displayed
        int loc;
        if(length == 0) //list is empty
        {
            list[length++] = insertItem; // insert the item and increment the length
            return 0;
        }
        else if(length == maxsize)
        {
            cerr<<"Cannot insert in a full list."<<endl;
            return -1;
        }
        else
        {
            loc = seqSearch(insertItem); //search if the item exists in the list aready
            if(loc == -1) // the item to be inserted does not exists in the list
                list[length++] = insertItem; // insert and increment length
            else
            {
                cerr<<"the item to be inserted is already in the list No duplicates are allowed."<<endl;
                return -1;
            }

        }
    }



    void remove(const elemType& removeItem)
    {
        //Function to remove an item from the list.
        //Postcondition: If remove item is found in the list, it is removed from the list
        // and length decremented by 1
        int loc;
        if(length == 0)
            cerr<<"Cannot delete from an empty list"<<endl;
        else
        {
            loc = seqSearch(removeItem);
            if(loc != -1) // if removeItem is in the list
                removeAt(loc); //remove the item with removeAt() function that takes care of position remove
            else
                cout<<"The item to be deleted is not in the list"<<endl;
        }

    }

    arrayListType(int size=5)
    {
        //Constructor
        //Create an array of the size specified by size. Defaults to 100
        //Postcondition: The list points to the array, length =0;
        // and maxSize = size

            if (size < 0)
                {
                    cerr << "The array size must be positive. Creating "
                        << "an array of size 100. " << endl;
                    maxsize = 100;
                }
            else
                maxsize = size;
            length = 0;
            list = new elemType[maxsize];
            assert(list != NULL);

    }

    arrayListType(const arrayListType<elemType>& otherList)
    {
        //Copy constructor
        //Called when an object is passed as a value parameter to a function and
        // when an object is declared and initialized using the value of another
        // object of the same type.
        //Ensures deep copy to avoid memory sharing this object and the otherList object. This could lead to serious errors when one of the objects is destroyed
        copyOtherList(otherList);

    }

    ~arrayListType()
    {
        //destructor
        //Deallocates the memory occupied by the array
        delete[] list;
    }

    int binarySearch(const elemType& item)const
    {
        int first = 0; //starting index
        int last = length -1; //last index
        int mid; // middle element index

        bool found = false;

        while(first<=last && !found)
        {
            mid = (first + last) /2;
            if(list[mid] == item)
                found = true;
            else if (list[mid] > item)
                last = mid -1 ; //if the middle item is greater than our search item the item to be searched on the left side of the list
            else
                first = mid + 1; // search on the right side of the list if th e middle item is > the searched item
        }
        if(found)
            return mid;
        else
            return -1;
    }

    void insertOrd(const elemType& item)
    {
        //This method inserts item to an ordered list
        int first = 0;
        int last = length - 1;
        int mid;

        bool found = false;
        if(length == 0) // the list is empty
        {
            list[0] = item;
            length++;
        }
        else if(length == maxsize)
            cerr<<"Cannot insert into a full list.";
        else
        {
            while(first<=last && !found)
            {
                mid = (first + last) /2;
                if(list[mid] == item)
                    found=true;
                else if(list[mid] > item)
                    last = mid - 1;
                else
                    first = mid + 1;
            }
            if(found)
                cerr<<"The insert item is already in the list. Duplicates are not allowed."<<endl;
            else
            {
                if(list[mid] < item)
                    mid++;
                inserAt(mid, item);
            }


        }

    }


    void selectionSort()
    {
        //Sorts the elements in increasing order
        int minIndex;
        for(int loc=0; loc<length-1; loc++)
        {
            minIndex = minLocation(loc, length-1);
            swap(loc, minIndex);
        }
    }

    void insertionSort()
    {
        //sorting the list elements by the insertion algorithm
        /*Insertion sort divides the list into two sides, the upper sorted side and
         the lower unsorted side. The lower unsorted side is marked by the element
         first element that is out of ordere*/
        int firstOutOfOrder; // index of the first element in  the list out of  order(not sorted). Element to be moved to its proper location
        int location; //location where the unsorted element to be inserted
        elemType temp; //temporary storage for the element to be inserted

        for(firstOutOfOrder = 1; firstOutOfOrder <length; firstOutOfOrder++) // start the loop with firstOutOrder=1
        {
            if(list[firstOutOfOrder] < list[firstOutOfOrder - 1]) //if the element at firstOutOrder is less than the one above it
            {
                temp = list[firstOutOfOrder]; //store the element that is out of order in temp[element of the lower sublist]
                location = firstOutOfOrder; // set current location where temporary will be inserted finally to the index of firstOutOfOrder

                do{
                    list[location] = list[location -1]; //move the element that is up the (upper sorted list)down the list by 1 step
                    location--; //decrement the location by 1 to move to set where our temporary element will be inserted
                }
                while(location > 0 && list[location - 1] > temp); //As long as the current location -1  element is greater than our temp element(list[firstOutOfOrder] element)
                list[location] = temp; //place it the location if the while loop terminates

                //Increment firstOutOrder to the next index and do the same till we reach the end of the list...sorted
            }
        }
    }

protected:
    elemType *list; // array to hold the list elements
    int length; // to store the length of the list. Number of elements in the list
    int maxsize; // to store the maximum size of the array

private:
    void copyOtherList(const arrayListType<elemType>& otherList)
    {
        //This function copies otherList to the current list. It helps avoid code dublication
        maxsize = otherList.maxsize;
        length = otherList.length;
        list = new elemType[maxsize]; //create the array

        assert(list != NULL); //terminate if unable to allocate memory space

        for(int j=0; j<length; j++) //copy otherList
            list[j] = otherList.list[j];
    }

    //method to return the index of the smallest element in the array.
    // it is used in the selection sorting algorithm
    int minLocation(int first, int last)
    {
        int minIndex; // index of the smallest element in the list
        minIndex = first;  // set it to the first element in the list

        for(int loc=first+1; loc<=last; loc++)
            if(list[loc] < list[minIndex]) // check if the next item in the list is less than the one at minIndex
            minIndex = loc; //advance the minIndex to the index of the  next smallest element in the list
        return minIndex;
    }

    //Function to swap two elements in the list given the location of the elements in the list
    void swap(int first,int second)
    {
        elemType temp; //to hold the first element temporarily to allow the second to take its place. When it takes its place it overrides it
        temp = list[first]; // hold first elem in temp
        list[first] = list[second]; // set first to second
        list[second] = temp;
    }
};

