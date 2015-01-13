#include "SetCollection.h"

/******************************************************************************
 *3456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
 * Class 'SetCollection' for organizing and testing sets.
 *
 * This function tests all the functions located in the MySet class. This is done
 * by using several test sets for difference scenarios. 
 *
 *
 * Author: Duncan A. Buell modified by Omar Ansari
 * Date last modified: 18 October 2014
**/




/******************************************************************************
 * Constructor
**/
SetCollection::SetCollection()
{
}

/******************************************************************************
 * Destructor
**/
SetCollection::~SetCollection()
{
}

/******************************************************************************
 * Accessors and Mutators
**/

/******************************************************************************
 * General functions.
**/

/******************************************************************************
 * Function 'initialize'.
 *
 * This function initializes some hard coded test sets to use later when 
 * testing different methods.
 *
 * Parameters:
 *   none
**/
void SetCollection::initialize()
{
  
#ifdef EBUG
  Utils::logStream << "enter initialize\n"; 
#endif

//TESTSET1 will be our empty set.
TESTSET1CARD = 0;

//Three elements in set. 
TESTSET2.add("HI");
TESTSET2.add("DOCTOR");
TESTSET2.add("BUELL");
TESTSET2CARD = 3;

//Set which contains same elements as TESTSET2
TESTSET3.add("HI");
TESTSET3.add("DOCTOR");
TESTSET3.add("BUELL");
TESTSET3CARD = 3;

//Superset of TESTSET5
TESTSET4.add("THIS");
TESTSET4.add("IS");
TESTSET4.add("A");
TESTSET4.add("STORY");
TESTSET4.add("ALL");
TESTSET4.add("ABOUT");
TESTSET4.add("HOW");
TESTSET4CARD = 7;

//Subset of TESTSET4
TESTSET5.add("ALL");
TESTSET5.add("ABOUT");
TESTSET5.add("HOW");
TESTSET5CARD = 3;

//TESTSET6 and TESTSET7 overlap by one element.
TESTSET6.add("FROSTY");
TESTSET6.add("THE");
TESTSET6.add("SNOWMAN");
TESTSET6CARD = 3;
//TESTSET6 and TESTSET7 overlap by one element.
TESTSET7.add("SNOWMAN");
TESTSET7.add("IS");
TESTSET7.add("COLD");
TESTSET7CARD = 3;

#ifdef EBUG
  Utils::logStream << "leave initialize\n"; 
#endif
}
/******************************************************************************
 * Function 'testCard'.
 *
 * This function tests the card function in the MySet class. It checks to 
 * to see if the function returns what you expect.
 *
 * Parameters:
 *   MySet set - set that you are checking.
 *	 unsigned int card - The number you are expecting the card to be.
**/
bool SetCollection::testCard(MySet set, unsigned int card)
{
#ifdef EBUG
  Utils::logStream << "enter testCard\n"; 
#endif

#ifdef SET

if (set.card() == card) //Check the returned card against expected.
{
  return true;
} else
{
  return false;
}
#endif

#ifdef EBUG
  Utils::logStream << "leave testCard\n"; 
#endif
}
/******************************************************************************
 * Function 'testAdd'.
 *
 * This function tests the add function in the MySet class. It checks to 
 * to see if the function adds elements properly. More information can
 * be found in the readme.txt file.
 *
 * Parameters:
 *   MySet set - set that you are checking.
 *	 unsigned int card - The number you are expecting the card to be.
 *   string elt - elt that you are adding to set.
**/
bool SetCollection::testAdd(MySet theSet, unsigned int card, string elt)
{

bool returnValue = true;

#ifdef EBUG
  Utils::logStream << "enter testAdd\n"; 
#endif

#ifdef SET
 
  theSet.add(elt); //Attempt the addition.
  returnValue = (testCard(theSet, card)); //Check if card is what we expect.

#endif

return returnValue;

#ifdef EBUG
  Utils::logStream << "leave testAdd\n"; 
#endif
}
/******************************************************************************
 * Function 'testContainsElt'.
 *
 * This function tests the  containsElt function in the MySet class. It checks
 * to see if the function actually checks containment properly. More 
 * information can be found in the readme.txt file.
 *
 * Parameters:
 *   MySet set - set that you are checking.
 *   string elt - elt that you are adding to set.
**/
bool SetCollection::testContainsElt(MySet theSet, string elt)
{
bool returnValue = true;

#ifdef EBUG
  Utils::logStream << "enter testContainsElt"; 
#endif

#ifdef SET
  returnValue = theSet.containsElt(elt); //If containsElt, return true.
#endif

return returnValue;

#ifdef EBUG
  Utils::logStream << "leave testContainsElt"; 
#endif
}
/******************************************************************************
 * Function 'testContainsSet'.
 *
 * This function tests the containsSet function in the MySet class. It checks
 * to see if the function actually checks set containment properly. More 
 * information can be found in the readme.txt file.
 *
 * Parameters:
 *   MySet left - set that you are checking if contains another set.
 *   MySet right - set that you are checking is contained in first set.
**/
bool SetCollection::testContainsSet(MySet left, MySet right)
{

bool returnValue = true;

#ifdef EBUG
  Utils::logStream << "enter testEqualsLocally\n"; 
#endif

#ifdef SET
 
returnValue = left.containsSet(right); //Check containment.

#endif

return returnValue;

#ifdef EBUG
  Utils::logStream << "leave testEqualsLocally\n"; 
#endif
}

/******************************************************************************
 * Function 'testEquals'.
 *
 * This function tests the equals function in the MySet class. It checks
 * to see if the function actually checks equality properly. More 
 * information can be found in the readme.txt file.
 *
 * Parameters:
 *   MySet left - set that you are checking if contains another set.
 *   MySet right - set that you are checking is contained in first set.
**/
bool SetCollection::testEquals(MySet left, MySet right)
{
  
bool returnValue = true;

#ifdef EBUG
  Utils::logStream << "enter testIsContainedInLocally\n"; 
#endif

#ifdef SET
returnValue = left.equals(right);
#endif

return returnValue;

#ifdef EBUG
  Utils::logStream << "leave testIsContainedInLocally\n"; 
#endif
}
/******************************************************************************
 * Function 'testIsContainedInSet'.
 *
 * This function tests the IsContainedInSet function in the MySet class. It checks
 * to see if the function actually checks set containment properly. More 
 * information can be found in the readme.txt file.
 *
 * Parameters:
 *   MySet left - set that you are checking if contains another set.
 *   MySet right - set that you are checking is contained in first set.
**/
bool SetCollection::testIsContainedInSet(MySet left, MySet right)
{

bool returnValue = true;

#ifdef EBUG
Utils::logStream << "enter testIsContainedInLocally\n"; 
#endif

#ifdef SET
returnValue = right.containsSet(left);
#endif

return returnValue;

#ifdef EBUG
  Utils::logStream << "leave testIsContainedInLocally\n"; 
#endif
}
/******************************************************************************
 * Function 'testGetElts'.
 *
 * This function tests the getElts function in the MySet class. It checks
 * to see if the function actually returns the appropriate underlying
 * data structure. More information can be found in the readme.txt file.
 *
 * Parameters:
 *   MySet left - set that you are checking if contains another set.
 *   int elts - number of elts expected.
**/
bool SetCollection::testGetElts(MySet theSet, int elts)
{

bool returnValue = false;

#ifdef EBUG
Utils::logStream << "enter testIsContainedInLocally\n"; 
#endif

#ifdef SET

set<string> tempElts = theSet.getElts();
if (tempElts.size() == elts)
{
	returnValue = true;
}
#endif

return returnValue;

#ifdef EBUG
Utils::logStream << "leave testIsContainedInLocally\n"; 
#endif
}
/******************************************************************************
 * Function 'testRemove'.
 *
 * This function tests the Remove function in the MySet class. It checks
 * to see if the elements are actually removed from the set.
 * More information can be found in the readme.txt file.
 *
 * Parameters:
 *   MySet left - set that you are checking if contains another set.
 *   unsigned int card - expected cardinality
 *	 string elt - elt to be removed.
**/
bool SetCollection::testRemove(MySet theSet, unsigned int card, string elt)
{

bool returnValue = true;

#ifdef EBUG
  Utils::logStream << "enter testAdd\n"; 
#endif

#ifdef SET
theSet.remove(elt);
returnValue = (testCard(theSet, card));
#endif

return returnValue;

#ifdef EBUG
  Utils::logStream << "leave testAdd\n"; 
#endif
}
/******************************************************************************
 * Function 'testOperatorEqual', 'testOperatorLess', and 'testOperatorMore'.
 *
 * The following three functions simply test the overridden operators. It checks
 * the internal functions usined in the the operator class.
 *
 * Parameters:
 *   MySet thatSet - set that you are checking if contains another set.
 *   MySet theSet - set that you are checking is contained in first set.
**/
bool SetCollection::testOperatorEqual(MySet theSet, MySet thatSet)
{

#ifdef EBUG
  Utils::logStream << "enter testAdd\n"; 
#endif

#ifdef SET

if (testEquals(theSet, thatSet))
{
	return true;
}else
{
	return false;
}
#endif

#ifdef EBUG
  Utils::logStream << "leave testAdd\n"; 
#endif
}

////////////////////////////////////////////////////////////////
bool SetCollection::testOperatorLess(MySet theSet, MySet thatSet)
{

#ifdef EBUG
  Utils::logStream << "enter testAdd\n"; 
#endif

#ifdef SET

if (testIsContainedInSet(theSet, thatSet))
{
	return true;
}else
{
	return false;
}
#endif

#ifdef EBUG
  Utils::logStream << "leave testAdd\n"; 
#endif
}
/////////////////////////////////////////////////////////////////////

bool SetCollection::testOperatorGreater(MySet theSet, MySet thatSet)
{

#ifdef EBUG
  Utils::logStream << "enter testAdd\n"; 
#endif

#ifdef SET

if (testContainsSet(theSet, thatSet))
{
	return true;
}else
{
	return false;
}
#endif

#ifdef EBUG
  Utils::logStream << "leave testAdd\n"; 
#endif
}
/******************************************************************************
 * Function 'testSets'.
 * This function tests the set functions in the 'MySet' class.
 *
 * Parameters:
 *
 *	ofStream& outStream - Stream to output to.
**/
void SetCollection::testSets(ofstream& outStream)
{

#ifdef EBUG
  Utils::logStream << "leave testSets\n"; 
#endif

#ifdef SET

/////////////////////////////////////////////////////////  
 
bool returnValueTest1 = true;
int errorCode = 0000;

if (!testAdd(TESTSET1, 1, "HELLO"))	//A
{
	returnValueTest1 = false;
	errorCode = 1;
}


if (!testAdd(TESTSET2, 4, "HELLO")) //B
{
	returnValueTest1 = false;
	errorCode = 2;
}

if (!testAdd(TESTSET4, 7, "THIS")) //C
{
	returnValueTest1 = false;
	errorCode = 3;
}

if (errorCode == 0000)
{
	outStream << "There were no errors found. Add function works properly." << endl;
} else
{
	outStream << "ERROR in add Function! Error Code: " << errorCode << " Please use the error code table to find the specific error!" << endl;
}

////////////////////////////////////////////////////////

bool returnValueTest2 = true;
errorCode = 0000;

if (testContainsElt(TESTSET1, "HI")) //D
{
	returnValueTest2 = false;
	errorCode = 4;
}	

if (!testContainsElt(TESTSET5, "HOW")) //E
{
	returnValueTest2 = false;
	errorCode = 5;
}

if (errorCode == 0)
{
	outStream << "There were no errors found. containsElt function works properly." << endl;
} else
{
	outStream << "ERROR in containsElt Function! Error Code: " << errorCode << " Please use the error code table to find the specific error!" << endl;
}	
//////////////////////////////////////////////////////////
bool returnValueTest3 = true;
errorCode = 0;

if (!testContainsSet(TESTSET1, TESTSET1)) //F
{
	returnValueTest3 = false;
	errorCode = 6;
}	

if (!testContainsSet(TESTSET2, TESTSET1)) //G
{
	returnValueTest3 = false;
	errorCode = 7;
}

if (!testContainsSet(TESTSET4, TESTSET5)) //H
{
	returnValueTest3 = false;
	errorCode = 8;
}

if (testContainsSet(TESTSET5, TESTSET4)) //I
{
	returnValueTest3 = false;
	errorCode = 9;
}

if (testContainsSet(TESTSET6, TESTSET7)) //J
{
	returnValueTest3 = false;
	errorCode = 10;
}

if (errorCode == 0)
{
	outStream << "There were no errors found. containsSet function works properly." << endl;
} else
{
	outStream << "ERROR in containsSet Function! Error Code: " << errorCode << 
		" Please use the error code table to find the specific error!" << endl;
}	
//////////////////////////////////////////////////////////////

bool returnValueTest4 = true;
errorCode = 0;

if (!testEquals(TESTSET1, TESTSET1)) //K
{
	returnValueTest4 = false;
	errorCode = 11;
}	

if (!testEquals(TESTSET2, TESTSET3)) //L
{
	returnValueTest4 = false;
	errorCode = 12;
}

if (testEquals(TESTSET4, TESTSET5)) //M
{
	returnValueTest4 = false;
	errorCode = 13;
}

if (testEquals(TESTSET6, TESTSET7)) //N
{
	returnValueTest4 = false;
	errorCode = 14;
}


if (errorCode == 0)
{
	outStream << "There were no errors found. equals function works properly." << endl;
} else
{
	outStream << "ERROR in equals Function! Error Code: " << errorCode << 
		" Please use the error code table to find the specific error!" << endl;
}	

//////////////////////////////////////////////////////////////
bool returnValueTest5 = true;
errorCode = 0;

if (!testIsContainedInSet(TESTSET1, TESTSET1)) //O
{
	returnValueTest5 = false;
	errorCode = 15;
}	

if (!testIsContainedInSet(TESTSET2, TESTSET3)) //P
{
	returnValueTest5 = false;
	errorCode = 16;
}

if (!testIsContainedInSet(TESTSET5, TESTSET4)) //Q
{
	returnValueTest5 = false;
	errorCode = 17;
}

if (testIsContainedInSet(TESTSET4, TESTSET5)) //R
{
	returnValueTest5 = false;
	errorCode = 18;
}

if (testIsContainedInSet(TESTSET6, TESTSET7)) //S
{
	returnValueTest5 = false;
	errorCode = 19;
}

if (errorCode == 0)
{
	outStream << "There were no errors found. isContainedInSet function works properly." << endl;
} else
{
	outStream << "ERROR in isContainedInSet Function! Error Code: "
		 << errorCode << " Please use the error code table to find the specific error!" << endl;
}	
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
bool returnValueTest6 = true;
errorCode = 0;

if (!testRemove(TESTSET1, 0, "NOTHING")) //T
{
	returnValueTest6 = false;
	errorCode = 20;
}	

if (!testRemove(TESTSET2, 3, "REMOVE")) //U
{
	returnValueTest6 = false;
	errorCode = 21;
}

if (!testRemove(TESTSET5, 2, "ALL")) //V
{
	returnValueTest6 = false;
	errorCode = 22;
}


if (errorCode == 0)
{
	outStream << "There were no errors found. remove function works properly." << endl;
} else
{
	outStream << "ERROR in remove Function! Error Code: " << errorCode << 
		" Please use the error code table to find the specific error!" << endl;
}	


//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
bool returnValueTest7 = true;
errorCode = 0;


if (!testGetElts(TESTSET1, 0)) //W
{
	returnValueTest7 = false;
	errorCode = 23;
}

if (!testGetElts(TESTSET2, 3)) //X
{
	returnValueTest7 = false;
	errorCode = 24;
}

if (testGetElts(TESTSET5, 30)) //Y
{
	returnValueTest7 = false;
	errorCode = 25;
}
//////////////////////////////////////////////////////////////////////

//OVERLOADING -- Z
	bool returnValueTest8 = true;
	errorCode = 0;
if (!testOperatorEqual(TESTSET1, TESTSET1)) 
{
	returnValueTest8 = false;
	errorCode = 26;
}

if (testOperatorEqual(TESTSET2, TESTSET1)) 
{
	returnValueTest8 = false;
	errorCode = 27;
}

if (!testOperatorEqual(TESTSET2, TESTSET3)) 
{
	returnValueTest8 = false;
	errorCode = 28;
}

if (!testOperatorLess(TESTSET1, TESTSET1))
{
	returnValueTest8 = false;
	errorCode = 29;
}

if (testOperatorLess(TESTSET4, TESTSET5))
{
	returnValueTest8 = false;
	errorCode = 30;
}

if (!testOperatorLess(TESTSET5, TESTSET4))
{
	returnValueTest8 = false;
	errorCode = 31;
}

if (!testOperatorGreater(TESTSET1, TESTSET1))
{
	returnValueTest8 = false;
	errorCode = 32;
}
if (!testOperatorGreater(TESTSET2, TESTSET1))
{
	returnValueTest8 = false;
	errorCode = 33;
}
if (!testOperatorGreater(TESTSET4, TESTSET5))
{
	returnValueTest8 = false;
	errorCode = 34;
}

if (errorCode == 0)
{
	outStream << "There were no errors found. Operators work properly." << endl;
} else
{
	outStream << "ERROR in Operators! Error Code: " << errorCode << 
		" Please use the error code table to find the specific error!" << endl;
}	

/////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

if (returnValueTest1)
{
	outStream << "Add function worked with no errors!" << endl;
} 

if (returnValueTest2)
{
	outStream << "containsElt function worked with no errors!" << endl;
} 

if (returnValueTest3)
{
	outStream << "containsSet function worked with no errors!" << endl;
} 

if (returnValueTest4)
{
	outStream << "equals function worked with no errors!" << endl;
} 

if (returnValueTest5)
{
	outStream << "isContainedInSet function worked with no errors!" << endl;
} 

if (returnValueTest6)
{
	outStream << "remove function worked with no errors!" << endl;
} 
if (returnValueTest7)
{
	outStream << "getElts function worked with no errors!" << endl;
} 

if (returnValueTest8)
{
	outStream << "ALL OPERATORS ARE WORKING PROPERLY." << endl;
} 




#endif
#ifdef EBUG
  Utils::logStream << "leave testSets\n"; 
#endif
}

/******************************************************************************
 * Function 'toStringTrueFalse'.
 * This function formats the boolean argument in fixed width string.
**/
string SetCollection::toStringTrueFalse(bool what)
{
  string s = " false";

  if(what)
  {
    s = " true ";
  }

  return s;
}
