#include "MySet.h"

/****************************************************************
 * Overloaded '<=' operator, not a 'MySet' member function.
 * Returns "setLeft is contained in setRight"?
 *
 * Parameters:
 *   setLeft -- the 'MySet' to test for being contained in
 *   setRight -- the 'MySet' to test for containing
**/
bool operator <=(const MySet& setLeft, const MySet& setRight)
{
  return setLeft.isContainedInSet(setRight);
}

/****************************************************************
 * Overloaded '>=' operator, not a 'MySet' member function.
 * Returns "setLeft contains setRight"?
 *
 * Parameters:
 *   setLeft -- the 'MySet' to test for containing
 *   setRight -- the 'MySet' to test for being contained by
**/
bool operator >=(const MySet& setLeft, const MySet& setRight)
{
  return setLeft.containsSet(setRight);
}

/****************************************************************
 * Overloaded '==' operator, not a 'MySet' member function.
 * Returns "setLeft equals setRight"?
 *
 * Parameters:
 *   setLeft -- the 'MySet' on the LHS of the '=='
 *   setRight -- the 'MySet' on the RHS of the '=='
**/
bool operator ==(const MySet& setLeft, const MySet& setRight)
{
  return setLeft.equals(setRight);
}

/****************************************************************
 * Overloaded '<<' operator, not a 'MySet' member function.
 *
 * Parameters:
 *   outStream -- the output stream to write to
 *   mySet -- the 'MySet' to 'toString'
**/
ostream& operator <<(ostream& outputStream, const MySet& mySet)
{
  outputStream << mySet.toString();

  return outputStream;
}
