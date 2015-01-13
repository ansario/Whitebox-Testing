/****************************************************************
 * Header file for the class to organize and test sets.
 *
 * Author/copyright:  Duncan Buell
 * Date: 18 July 2014
 *
**/

#ifndef SETCOLLECTION_H
#define SETCOLLECTION_H

#include <iostream>
#include <vector>
#include <set>
using namespace std;

#include "MySet.h"

#include "../../Utilities/Scanner.h"
#include "../../Utilities/ScanLine.h"

class SetCollection
{
public:
  SetCollection();
  virtual ~SetCollection();

  void initialize();
  bool testCard(MySet set, unsigned int card);
  bool testAdd(MySet theSet, unsigned int card, string elt);
  bool testContainsElt(MySet theSet, string elt);
  bool testContainsSet(MySet left, MySet right);
  bool testEquals(MySet left, MySet right);
  bool testGetElts(MySet set, int elts);
  bool testOperatorEqual(MySet theSet, MySet thatSet);
  bool testOperatorGreater(MySet theSet, MySet thatSet);
  bool testOperatorLess(MySet theSet, MySet thatSet);
  bool testIsContainedInSet(MySet left, MySet right);
  bool testRemove(MySet theSet, unsigned int card, string elt);
  void testSets(ofstream& outStream);
  string toString();
  string toStringTrueFalse(bool what);

private:
  
  MySet TESTSET1;
  int TESTSET1CARD;
  MySet TESTSET2;
  int TESTSET2CARD;
  MySet TESTSET3;
  int TESTSET3CARD;
  MySet TESTSET4;
  int TESTSET4CARD;
  MySet TESTSET5;
  int TESTSET5CARD;
  MySet TESTSET6;
  int TESTSET6CARD;
  MySet TESTSET7;
  int TESTSET7CARD;


};

#endif
