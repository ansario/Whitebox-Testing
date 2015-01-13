/***********************************************************
*Readme.txt for SetCollection.cpp file. HW07_CSCE240_F2014
*
*@author Omar A. Ansari. Copyright 2014. All rights reserved.
*@version 1.0 11/20/2014
*

The purpose of the testing suite is to white-box test the given code in order to
rule out possible programming, logic, and syntax errors. White-box testing is a method of testing software that tests internal structures of an application, as opposed to its functionality (i.e. black-box testing) (Wikipedia.org). 

The tests detailed below have been carefully crafted in order to test all possible cases of input for the functions in the MySet.cpp. 

—————————————————————————————————————————————————————————————————————————————————————————

Function in SetCollection.cpp | testAdd(MySet theSet, unsigned int card, string elt)
This function is tested several ways.

A. The function is is tested with an empty set. We know it does not have any elements so 
its cardinality will be 0. Adding an element should increase the cardinality to 1 if the
addition works properly.

B. The function is tested with a set containing some elements. If the element is added
properly, the cardinality of the set should increase by one.

C. The function is tested with a set that already contains the element. The cardinality
should not increase. 

—————————————————————————————————————————————————————————————————————————————————————————


Function in SetCollection.cpp | testContainsElt(MySet theSet, string elt)
This function is tested two ways.

D. The function is tested with the elt not being contained in theSet. In this case, an error is returned if the element is found in theSet.

E. The function is tested with the elt contained in theSet. In this case, an error is returned if the element is not found in theSet.

—————————————————————————————————————————————————————————————————————————————————————————

Function in SetCollection.cpp | testContainsSet(MySet theSet, MySet thatSet)
This function is tested in several ways.

F. The function is tested with two empty sets. By definition, an empty set contains all
other empty sets. This test returns an error if one empty set is not found in another.

G. The function is tested with one non-empty set and one empty set. By definition, the non-empty set should contain the empty set. This test returns an error if the empty set is not found in the non-empty set.

H. The function is tested with Set A and Set B, where B is a subset of A. This test returns an error if Set B is not found in Set A.

I. The function is tested with Set A and Set B, where B is a subset of A. This test returns an error if Set A is found in Set B.

J. The function is tested with two sets, A & B, where A has only one element in common with B. By definition of containment, this test returns an error if B is found in A.

—————————————————————————————————————————————————————————————————————————————————————————

Function in SetCollection.cpp | testEquals(MySet theSet, MySet thatSet)
This function is tested in several ways.

K. The function is tested with two empty sets. By definition, an empty set contains all
other empty sets. This test returns an error if one empty set is not found equal to another.

L. The function is tested with two sets that contain exactly the same elements. By definition, these sets are equal and the test will return an error if they are found to be different.

M. The function is tested with Set A and Set B where set B is a subset of A. This test returns an error if A and B are found to be equal.

N. The function is tested with two sets, A & B, where A has only one element in common with B. By definition of equals, this test returns an error if B is found to be equal to A.

—————————————————————————————————————————————————————————————————————————————————————————

Function in SetCollection.cpp | testIsContainedInSet(MySet theSet, MySet thatSet)
This function is tested in several ways.

O. The function is tested with two empty sets. By definition, an empty set contains all
other empty sets. This test returns an error if one empty set is not found in another.

P. The function is tested with two sets which contain the same elements. By definition, one should be found in the other. This test returns an error if one set is not found in the other set.

Q. The function is tested with Set A and Set B, where B is a subset of A. This test returns an error if Set B is not found in Set A.

R. The function is tested with Set A and Set B, where B is a subset of A. This test returns an error if Set A is found in Set B.

S. The function is tested with two sets, A & B, where A has only one element in common with B. By definition of containment, this test returns an error if B is found in A.

—————————————————————————————————————————————————————————————————————————————————————————

Function in SetCollection.cpp | testRemove(MySet theSet, int card, string elt)
This function is tested in several ways.

T. The function is tested with an empty set. If it returns anything other than 0 elements, 
an error message will be displayed.

U. The function is tested with a non-empty set. If the number of elements returned does not match expected elements, show error message.

V. The function is tested with a non-empty set. It is passed an incorrect cardinality on purpose. If the function returns true, show an error message.

—————————————————————————————————————————————————————————————————————————————————————————

Function in SetCollection.cpp | testRemove(MySet theSet, int card, string elt)
This function is tested in several ways.

W. The function is tested with an empty set. Nothing can be removed from an empty set. This test returns an error if the cardinality of the empty set changes.

X. The function is tested with a set of 3 elements that does not contain the element being removed. The cardinality should not change since the element is not contained in the set.

Y. The function is tested with a set of 3 elements that do contain the element being removed. An error is returned if the cardinality changes.

—————————————————————————————————————————————————————————————————————————————————————————

OPERATOR TESTING

Z.

The operators are simply tested using the above methods. There are three methods used in the testing of the operators:

testOperatorEqual (MySet theSet, MySet thatSet)
testOperatorLess (MySet theSet, MySet thatSet)
testOperatorGreater (MySet theSet, MySet thatSet)

These functions simply test the containsSet, equals, and isContainedInSet mentioned above using the same tests.

—————————————————————————————————————————————————————————————————————————————————————————

ERROR CODES:

1.  Element was not added to empty set.
2.  Element was not added to non-empty set.
3.  Element was not added to non-empty set.
4.  Element was found in empty set.
5.  Element in set was not found in set.
6.  Empty set was not found to contain empty set.
7.  Empty set was not found in a non-empty set.
8.  Subset of set A was not found in set A.
9.  Set A was found in subset of A.
10. Overlapping set is found in another set without containing the whole set.
11. Empty set was not found to equal empty set.
12. Set A was not found to equal Set B although they contain the same elements.
13. Set A containing a subset B, was found to be equal to B.
14. Overlapping, yet not equal sets, were found to be equal.
15. Empty set was found to not be contained in empty set.
16. Set A which is equal to Set B was not found to contain Set B.
17. Set A which is a subset of Set B was not contained in Set B.
18. Set B which is a subset of set A was found to contain set A.
19. Set A was found to contain Set B although they only have 1 element in common.
20. An element was removed from an empty set.
21. An element was removed from a set not containing that element.
22. An element was removed from set A but set A was not decremented in cardinality.
23. An empty set was found to have more than 0 elements.
24. A set containing 3 elements was found to contain an alternate number of elements.
25. A set containing 7 elements was found to contain an alternate number of elements. //
26. Two empty sets were not found to equal each other.
27. A set with more than 0 elements was found to equal an empty set.
28. Set A and Set B contain the same elements but were found to not equal each other.
29. An empty set was not found to be contained in an empty set.
30. A subset of Set A was not found to be contained in Set A.
31. Set B is a subset of A but was not found to be contained in A.
32. An empty set was not found to contain another empty set.
33. A set with elements greater than 0 was not found to contain an empty set.
34. Set A with subset B was not found to contain B.