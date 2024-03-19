#include <iostream> 
#include <string>   
#include <map>      
#include "ring.h"  
#include "ring_functions.h"


int main() {
    // Create and populate the ring
    Ring<string, int> myRing;
    myRing.insertEnd("uno", 1);
    myRing.insertEnd("due", 2);
    myRing.insertEnd("tre", 3);
    myRing.insertEnd("quattro", 4);
    myRing.insertEnd("cinque", 5);
    myRing.insertEnd("sei", 6);
    myRing.insertEnd("sette", 7);
    myRing.insertEnd("otto", 8);

    // Filter the ring with the predicate function
    Ring<string, int> filteredRing = filter(myRing, keyLengthGreaterThanThree);

    // Print the filtered ring
    cout << "Filtered ring:" << endl;
    filteredRing.print();

    Ring<string, int> firstRing;
    firstRing.insertEnd("uno", 1);
    firstRing.insertEnd("due", 1);
    firstRing.insertEnd("tre", 2);
    firstRing.insertEnd("quattro", 1);

    // Create and populate the second ring
    Ring<std::string, int> secondRing;
    secondRing.insertEnd("due", 1);
    secondRing.insertEnd("tre", 1);
    secondRing.insertEnd("quattro", 3);
    secondRing.insertEnd("cinque", 5);

    // Join the rings
    Ring<std::string, int> joinedRing = join(firstRing, secondRing);
    std::cout << "Joined ring:" << std::endl;
    joinedRing.print();


    firstRing.remove_all();

    firstRing.insertEnd("uno", 1);
    firstRing.insertEnd("due", 2);
    firstRing.insertEnd("tre", 3);
    firstRing.insertEnd("quattro", 4);

    secondRing.remove_all();
    
    secondRing.insertEnd("bir", 1);
    secondRing.insertEnd("iki", 2);
    secondRing.insertEnd("uc", 3);
    secondRing.insertEnd("dort", 4);
    secondRing.insertEnd("bes", 5);

    // Shuffle the rings: take 1 element from the first, then 2 from the second, repeat 3 times
    Ring<string, int> shuffledRing = shuffle(firstRing, 1, secondRing, 2, 3);

    // Print the shuffled ring
    cout << "Shuffled ring:" << endl;
    shuffledRing.print();


    return 0;
}
