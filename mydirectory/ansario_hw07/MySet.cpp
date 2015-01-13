#include "MySet.h"

/******************************************************************************
 *3456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
 * Class 'MySet'.
 * This class implements a mathematical set and provides a suite of
 * functions for handling sets. Functions provided are:
 *    add -- to add an elt to 'this' set
 *    containsElt -- to test whether 'this' set contains a specific elt
 *    containsSet -- to test whether 'this' set contains another set
 *    equals -- to test if 'this' set is equal to another set
 *    getElts -- to return the elts of 'this' for iteration over by some
 *               calling function
 *    isContained in Set -- to test if 'this' is contained in another set
 *    remove -- to remove an elt from 'this' set (if it is present)
 *
 * This class can be compiled using a compiler directive to use either
 * an STL 'set' container or a 'vector' container as the underlying
 * storage structure. In the former case it can be viewed as merely a
 * convenience wrapper for the 'set' container.
 *
 * This class assumes that all elements are of 'string' data type.
 *
 * Author: Duncan A. Buell
 * Date last modified: 11 October 2014
**/

/******************************************************************************
 * We need to ensure that one or the other storage structure will be used.
**/
#ifndef SET
#ifndef VECTOR
#error Must define either 'SET' or 'VECTOR'
#endif
#endif

#ifdef SET
#ifdef VECTOR
#error Cannot define both 'SET' and 'VECTOR'
#endif
#endif

/******************************************************************************
 * Constructor
**/
MySet::MySet()
{
}

/******************************************************************************
 * Destructor
**/
MySet::~MySet()
{
}

/******************************************************************************
 * Accessors and Mutators
**/

/******************************************************************************
 * General functions.
**/


int MySet::card()
{
  return theSet.size();
}
/******************************************************************************
 * Function to add an element.
 * This returns 'true' if the elt was added and 'false' if the elt was
 * already in the set.
 *
 * Set version:
 *     We call the 'insert' function. This inserts the elt if it is
 *         not present, does not insert if it's already there, and
 *         returns a pair with a 'bool' that is 'true' or 'false'
 *         according as the elt was inserted or not.
 *     We then return that 'bool value.
 *
 * Vector version:
 *     We iterate over the 'vector' testing to see if 'elt' is already
 *         present.
 *     If not, we push it back on the 'vector'.
 *     We then return a 'bool value.
 *
 * Parameter:
 *   elt - the element to add
 *
 * Returns:
 *   a boolean as to whether or not the elt was added
**/
bool MySet::add(string elt)
{
#ifdef SET
  bool returnValue = true;
  std::pair<std::set<string>::iterator,bool> pair = this->theSet.insert(elt);
  returnValue = pair.second;
#endif

#ifdef VECTOR
  bool returnValue = true;
  vector<string>::iterator iter;

  for(iter = this->theSet.begin(); iter != this->theSet.end(); ++iter)
  {
    if(elt == (*iter))
    {
      returnValue = false;
      break;
    }
  }
  if(returnValue)
  {
    this->theSet.push_back(elt);
  }
#endif

  return returnValue;
}

/******************************************************************************
 * Function to test if 'this' set contains element 'thatElt'.
 *
 * Set version:
 *     We issue a 'find' and return 'true' if 'thatElt' was found,
 *         else 'false'.
 *
 * Vector version:
 *     We iterate over the 'vector' testing to see if 'elt' is present
 *         and return a 'true' if it is, else 'false'.
 *
 * Parameter:
 *   thatElt - the 'thatElt' in the test
 *
 * Returns:
 *   the answer to the question
**/
bool MySet::containsElt(string thatElt) const
{
  bool returnValue = false;

#ifdef SET
  // for some reason it doesn't insist on a 'const_iterator'
  // but i have put one in anyway
  set<string>::const_iterator iter;

  iter = this->theSet.find(thatElt);
  
  if (iter != this->theSet.end())
  {
    returnValue = true;
  }
#endif

#ifdef VECTOR
  // for the 'vector', the compiler DOES insist on a 'const_iterator'
  vector<string>::const_iterator iter;

  for(iter = this->theSet.begin(); iter != this->theSet.end(); ++iter)
  {
    if (*iter == thatElt)
    {
      returnValue = true;
      break;
    }
  }
#endif

  return returnValue;
}

/******************************************************************************
 * Function to test if 'this' set contains set 'thatSet'.
 *
 * We retrieve the elts of 'thatSet',
 * iterate over those elements,
 * and test to see that each retrieved elt from 'thatSet' is in 'this'.
 *
 * In this case the 'set' version and the 'vector' version are
 * essentially identical.
 *
 * Parameter:
 *   thatSet - the 'thatSet' in the test
 *
 * Returns:
 *   the answer to the question
**/
bool MySet::containsSet(MySet thatSet) const
{
  bool returnValue = true;

#ifdef SET
  set<string> thatSetElts = thatSet.getElts();

  set<string>::iterator iter;
  for (iter = thatSetElts.begin(); iter != thatSetElts.end(); ++iter)
  {
    set<string>::iterator isEltOfPtr = this->theSet.find(*iter);
    if (isEltOfPtr == this->theSet.end())
    {
      returnValue = false;
      break;
    }
  }
#endif

#ifdef VECTOR
  vector<string> thatSetElts = thatSet.getElts();

  vector<string>::iterator iter;
  for (iter = thatSetElts.begin(); iter != thatSetElts.end(); ++iter)
  {
    if(!this->containsElt(*iter))
    {
      returnValue = false;
      break;
    }
  }
#endif

  return returnValue;
}

/******************************************************************************
 * Function to test if 'this' set equals set 'thatSet'.
 *
 * We test this by testing containment both ways using the containment
 * functions in this class.
 *
 * The 'set' and 'vector' versions are identical.
 *
 * Parameter:
 *   thatSet - the 'thatSet' in the test
 *
 * Returns:
 *   the answer to the question
**/
bool MySet::equals(MySet thatSet) const
{
  return (this->containsSet(thatSet)) && (thatSet.containsSet(*this));
}

/******************************************************************************
 * Function to return the elts of 'this' as a 'set<string>' or as a
 * 'vector<string>' according as the compiler directive dictates.
 *
 * Set version:
 *     We simply return the underlying 'set'.
 *
 * Vector version:
 *     We simply return the underlying 'vector'.
 *
 * Returns:
 *   the elements
**/
#ifdef SET
set<string> MySet::getElts() const
#endif
#ifdef VECTOR
vector<string> MySet::getElts() const
#endif
{
  return this->theSet;
}

/******************************************************************************
 * Function to test if 'this' set is contained in set 'thatSet'.
 * We get the answer by simply calling the 'thatSet' containment function.
 *
 * The 'set' and 'vector' versions both just flip 'this' and 'that'
 * sets and call the "is contained in set" function.
 *
 * Parameter:
 *   thatSet - the 'thatSet' in the test
 *
 * Returns:
 *   the answer to the question
**/
bool MySet::isContainedInSet(MySet thatSet) const
{

  return thatSet.containsSet(*this);
}

/******************************************************************************
 * Function to remove an elt from a set if the elt is in the set.
 * We do a simple 'find' to determine presence, and then remove or not.
 *
 * Set version:
 *     We issue a 'find', and if the elt is present, we 'erase' it.
 *
 * Vector version:
 *     We iterate to find whether the elt is present, and erase it
 *         if it is present.
 *
 * In either version, we return a 'bool' if the elt is erased.
 *
 * Parameter:
 *   what - the elt to remove
 *
 * Returns:
 *   true or false according as the elt was present and removed or not
**/
bool MySet::remove(string what)
{
  bool returnValue = false;

#ifdef SET
  set<string>::iterator iter = this->theSet.find(what);

  if(iter != this->theSet.end())
  {
    this->theSet.erase(iter);
    returnValue = true;
  }
#endif

#ifdef VECTOR
  vector<string>::iterator iter;

  for(iter = this->theSet.begin(); iter != this->theSet.end(); ++iter)
  {
    if(*iter == what)
    {
      this->theSet.erase(iter);
      returnValue = true;
      break;
    }
  }
#endif

  return returnValue;
}

/******************************************************************************
 * Function 'toString'.
 * This function dumps the set to a 'string' and returns it.
 *
 * The 'set' and 'vector' versions are identical except for data type
 * of the 'iterator'.
 *
 * Returns:
 *   the 'toString' of the set
**/
string MySet::toString() const
{
  string s = "[";

#ifdef SET
  set<string>::iterator iter;
#endif

#ifdef VECTOR
  vector<string>::const_iterator iter;
#endif

  for (iter = this->theSet.begin(); iter != this->theSet.end(); ++iter)
  {
    s += " " + (*iter);
  }
  s += " ]";

  return s;
}
