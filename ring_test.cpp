#include <iostream> 
#include <string>   
#include <map>      
#include "ring.h"  

using namespace std;

int main() {
    Ring<int, string> ring;

    // Test isEmpty
    cout << "Is ring empty initially? " << (ring.is_empty() ? "Yes" : "No") << endl;

    // Test insertEnd
    ring.insertEnd(1, "One");
    ring.print();

    // Test insertFront
    ring.insertFront(2, "Two");
    ring.print();

    // Test contains
    cout << "Does ring contain key 1? " << (ring.contains(1) ? "Yes" : "No") << endl;
    cout << "Does ring contain key 3? " << (ring.contains(3) ? "Yes" : "No") << endl;

    // Test update
    ring.update(1, "One Updated");
    ring.print();

    // Test remove_current
    ring.remove_current();
    ring.print();

    // Test count_elements
    cout << "Number of elements: " << ring.count_elements() << endl;

    // Test set_current
    ring.set_current();
    ring.print();

    // Test is_at_start
    cout << "Is ring at start? " << (ring.is_at_start() ? "Yes" : "No") << endl;

    // Test move_next, get_current_key, get_current_value
    ring.move_next();
    cout << "Current key: " << ring.get_current_key() << ", Current value: " << ring.get_current_value() << endl;

    // Test remove_all
    ring.remove_all();
    cout << "Is ring empty after remove_all? " << (ring.is_empty() ? "Yes" : "No") << endl;

    return 0;
}
