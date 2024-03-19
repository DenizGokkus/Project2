# Description

This C++ repository features the implementation of a ring class, a doubly linked list designed for flexible and efficient data manipulation. The class supports operations such as insertion, deletion, and advanced manipulations exemplified by the task requirements:

-Filtering: The filter function selects elements whose keys satisfy a specific condition, demonstrated by filtering strings longer than 3 characters, resulting in a new list with elements like [quattro:4 cinque:5 sette:7 otto:8].

-Joining: Demonstrates combining two bi_ring instances by summing the information of matching keys, as shown in the task where joining lists results in [uno:1 due:2 tre:3 quattro:4 cinque:5].

-Unique Values Generation: Eliminates repeated keys by aggregating their information, illustrated with a function that combines strings, producing a list with unique keys like [one: uno-eins two: due-zwei three: tre-drei ...].

-Shuffling: A unique join operation that alternates elements from two lists in a specified pattern, exemplified by merging lists into a sequence such as [uno:1 bir:1 iki:2 due:2 uc:3 dort:4 tre:3 bes:5 bir:1].

Accompanying the class implementation, this repository contains tests for each functionality within bi_ring_test.h and bi_ring_test.cpp files, ensuring the class performs as expected across different scenarios.
