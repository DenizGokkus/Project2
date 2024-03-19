#include "ring.h"
#include <string>
#include <iostream>


// Predicate function
bool keyLengthGreaterThanThree(const string& key) {
    return key.size() > 3;
}

// Filter function
template<typename Key, typename Info>
Ring<Key, Info> filter(const Ring<Key, Info>& source, bool (*pred)(const Key&)) {
   
    Ring<Key, Info> result;
    Ring<Key,Info> sourcecopy;

    sourcecopy=source;

    if (sourcecopy.is_empty()) {
        return result;
    }

    // We'll start at the head and make a full iteration through the ring
    for (int i = 0, n = sourcecopy.count_elements(); i < n; ++i) {
        Key current_key = sourcecopy.get_current_key();
        if (pred(current_key)) {
            result.insertEnd(current_key, sourcecopy.get_current_value());
        }
        sourcecopy.move_next();
    }

    return result;
}

template<typename Key, typename Info>
Ring<Key, Info> shuffle(const Ring<Key, Info>& first, unsigned int fcnt,const Ring<Key, Info>& second, unsigned int scnt,unsigned int reps)
{
    Ring<Key, Info> result;
    Ring<Key, Info> firstcopy;
    Ring<Key, Info> secondcopy;
    firstcopy=first;
    secondcopy=second;

    if (first.is_empty() || second.is_empty() || fcnt == 0 || scnt == 0) {
        return result;
    }

    for (unsigned int r = 0; r < reps; ++r) {
        // Take fcnt elements from the first ring
        for (unsigned int i = 0; i < fcnt; ++i) {
            result.insertEnd(firstcopy.get_current_key(), firstcopy.get_current_value());
            firstcopy.move_next(); // This assumes that move_next() is a const method, which it isn't normally
        }

        // Take scnt elements from the second ring
        for (unsigned int j = 0; j < scnt; ++j) {
            result.insertEnd(secondcopy.get_current_key(), secondcopy.get_current_value());
            secondcopy.move_next(); // This assumes that move_next() is a const method, which it isn't normally
        }
    }

    return result;
}

template<typename Key, typename Info>
Ring<Key, Info> join(const Ring<Key, Info>& first, const Ring<Key, Info>& second) {
    Ring<Key, Info> result;
    Ring<Key, Info> firstcopy;
    Ring<Key, Info> secondcopy;
    
    firstcopy=first;
    secondcopy=second;
    // Add elements from the first ring to the result ring
    for (int i = 0, n = first.count_elements(); i < n; ++i) {
        // Insert only if the result does not already contain the key
        if (!result.contains(first.get_current_key())) {
            result.insertEnd(first.get_current_key(), firstcopy.get_current_value());
        }
        firstcopy.move_next();
    }

    // Add elements from the second ring to the result ring, potentially overwriting
    for (int j = 0, m = secondcopy.count_elements(); j < m; ++j) {
        // Insert only if the result does not already contain the key
        // Or update the existing value if the key is found
        if (!result.contains(secondcopy.get_current_key())) {
            result.insertEnd(secondcopy.get_current_key(), secondcopy.get_current_value());
        } else {
            result.update(secondcopy.get_current_key(), secondcopy.get_current_value());
        }
        secondcopy.move_next();
    }

    return result;
}


