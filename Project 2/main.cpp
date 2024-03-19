#include "split.h"
#include "ring.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    Ring<string,int> ring1;
    //source
    ring1.insertEnd("zero",0);
    ring1.insertEnd("One",1);
    ring1.insertEnd("Two",2);
    ring1.insertEnd("Three",3);
    ring1.insertEnd("four",4);
    ring1.insertEnd("five",5);
    ring1.insertEnd("six",6);
    ring1.insertEnd("seven",7);
    ring1.insertEnd("eight",8);
    ring1.insertEnd("nine",9);
    
    Ring<string,int> ring2;
    Ring<string,int> ring3;

    // Initialize values
    int strartindex = 2;
    int step1 = 2;
    int repeat1 = 4;
    bool forward1 = true;
    int step2 = 3;
    int repeat2 = 2;
    bool forward2 = false;

//tests the split function tests the stuatus of the source after split function and tests everything within the split function
    split(ring1,strartindex,ring2,step1,repeat1,forward1,ring3,step2,repeat2,forward2);
//tests the print function
    cout<<"source:"<<endl;
    ring1.print();
    cout<<"ring1:"<<endl;
    ring2.print();
    cout<<"ring2:"<<endl;
    ring3.print();
    //remove all function test 
    ring2.remove_all();
    ring3.remove_all();
    ring2.print();
    ring3.print();
    //tests is it empty bool function
    cout<<ring2.is_empty()<<endl;
    //empty
    cout<<ring3.is_empty()<<endl;
    //empty
    cout<<ring1.is_empty()<<endl;
    //not empty

    //what hapens if you give an emty file as imput
    Ring<string,int> ring4;
    split(ring3,strartindex,ring2,step1,repeat1,forward1,ring3,step2,repeat2,forward2);
    //what happens if you give a full ring to fill (it removes all and does it anyways)
    //aslo operator = test
    ring2=ring1;
    split(ring1,strartindex,ring2,step1,repeat1,forward1,ring3,step2,repeat2,forward2);
     cout<<"ring1:"<<endl;
    ring2.print();
    cout<<"ring2:"<<endl;
    ring3.print();
    ring2.remove_all();
    ring3.remove_all();
    //what happens if you put 0 for step or use a startindex that is bigger than the number of ements in the ring
    split(ring1,strartindex,ring2,0,repeat1,forward1,ring3,step2,repeat2,forward2);
    //it takes the element that you imput rings are infinit 
    split(ring1,12,ring2,step1,repeat1,forward1,ring3,step2,repeat2,forward2);
     cout<<"ring1:"<<endl;
    ring2.print();
    cout<<"ring2:"<<endl;
    ring3.print();

    cout<<endl;
    cout<<"------------------------aditional_task--------------------------------"<<endl;
    //aditional task
    cout<<"Source:"<<endl;
    ring1.print();
    cout<<"Swap Function"<<endl;
    Ring<int,string> ring5;

    swapKeyValue(ring1)=ring5;

    return 0;
}