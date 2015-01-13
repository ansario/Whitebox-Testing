/****************************************************************
 * Header file for a single set.
 * This class wraps the built in 'set' container.
 *
 * Author/copyright:  Duncan Buell
 * Date: 11 October 2014
 *
**/

#ifndef MYSET_H
#define MYSET_H

#ifndef SET
#ifndef VECTOR
#error Must define either 'SET' or 'VECTOR'
#endif
#endif

#include <iostream>
#include <vector>
#include <set>
using namespace std;

#include "../../Utilities/Scanner.h"
#include "../../Utilities/ScanLine.h"

class MySet
{
public:
  MySet();
  virtual ~MySet();

  bool add(string elt);
  int card();
  bool containsElt(string elt) const;
  bool containsSet(MySet thatSet) const;
  bool equals(MySet thatSet) const;
  bool isContainedInSet(MySet thatSet) const;
  bool remove(string elt);
  string toString() const;

#ifdef SET
  set<string> getElts() const;
#endif

#ifdef VECTOR
  vector<string> getElts() const;
#endif

  /////////////////////////////////////////////////////////////////
  // Overloaded 'friend' operators.
  friend bool operator <=(const MySet& setLeft, const MySet& setRight);
  friend bool operator >=(const MySet& setLeft, const MySet& setRight);
  friend bool operator ==(const MySet& setLeft, const MySet& setRight);
  friend ostream& operator <<(ostream& outputStream,
                              const MySet& mySet);

private:
#ifdef SET
  set<string> theSet;
#endif

#ifdef VECTOR
  vector<string> theSet;
#endif

};

#endif

