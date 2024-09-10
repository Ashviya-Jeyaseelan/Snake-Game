#include "objPosArrayList.h"
#include <iostream>

using namespace std;

bool passed = true;
int passCount = 0;
int failCount = 0;

// WARNING!!  This test suite does not contain any test cases for accessing elements out-of-bound.
//
// You must deploy exception throwing for all out-of-bound accesses.


// Test Case 1 - Constructor Tester
// - Will require you to implement getSize() and getElement() methods.
void testConstructor()
{
	objPos zeroPos, currentPos;
	objPosArrayList thisList;
	int expectedSize = 0;
	int actualSize = thisList.getSize();
	
	// First check the list size
	if(expectedSize != actualSize)
	{
		cout << "[FAILED] Test Constructor Failed" << endl;
		failCount++;
		passed = false;	
		return;
	}

	bool expectedCheck = true;
	bool actualCheck;

	// Then check all elements in the array are zero-initialized via objPos() default constructor
	for(int i = 0; i < ARRAY_MAX_CAP; i++)
	{
		thisList.getElement(currentPos, i);
		actualCheck = zeroPos.isPosEqual(&currentPos);

		if(expectedCheck != actualCheck)
		{
			cout << "[FAILED] Test Constructor Failed" << endl;
			failCount++;
			passed = false;	
			return;
		}
	}

	cout << "[OK] Test Constructor Passed" << endl;
	passCount++;
	return;

	// The destructor will be called automatically for stack-allocated objects
}

/////////////////////////////////////////////////////////////////
// MY TEST CASES
/////////////////////////////////////////////////////////////////
void mytestConstructor() // For maximum capacity
{
    objPosArrayList thisList;
    
    int expectedSize = 0;
    int actualSize = thisList.getSize();

    if (expectedSize != actualSize)
    {
        cout << "[FAILED] Test Constructor for Max Capacity Failed - wrong size" << endl;
        failCount++;
        passed = false;
        return;
    }

    bool expectedCheck = true;
    bool actualCheck;

    objPos currentPos;

    for (int i = 0; i < ARRAY_MAX_CAP; i++)
    {
        thisList.getElement(currentPos, i);
        actualCheck = currentPos.isPosEqual(&currentPos);

        if (expectedCheck != actualCheck)
        {
            cout << "[FAILED] Test Constructor for Max Capacity Failed - element wrong" << endl;
            failCount++;
            passed = false;
            return;
        }
    }

    cout << "[OK] Test Constructor for Max Capacity Passed" << endl;
    passCount++;
}
/////////////////////////////////////////////////////////////////

// Test Case 2a - insertHead 1 Element 
// - Will require you to implement getHeadElement(), getTailElement(), and getElement() methods.
void testInsertHead_1Element()
{
	objPos currentPos;
	objPos samplePos{2, 5, 'a'};  

	// Insert 1 sample element
	objPosArrayList thisList;
	thisList.insertHead(samplePos);

	int expectedSize = 1;
	int actualSize = thisList.getSize();
		
	// First check the list size is 1
	if(expectedSize != actualSize)
	{
		cout << "[FAILED] Test Insert Head 1 Element Failed - wrong size" << endl;
		failCount++;
		passed = false;	
		return;
	}

	bool expectedCheck = true;
	bool actualCheck;

	// Then check whether the head element is what we have inserted.
	thisList.getHeadElement(currentPos);
	actualCheck = samplePos.isPosEqual(&currentPos);

	if(expectedCheck != actualCheck)
	{
		cout << "[FAILED] Test Insert Head 1 Element Failed - head wrong" << endl;
		failCount++;
		passed = false;	
		return;
	}

	// Next, check whether the tail element is also the head element in a list of 1 element.
	thisList.getTailElement(currentPos);
	actualCheck = samplePos.isPosEqual(&currentPos);

	if(expectedCheck != actualCheck)
	{
		cout << "[FAILED] Test Insert Head 1 Element Failed - tail wrong" << endl;
		failCount++;
		passed = false;	
		return;
	}

	// Finally, chech whether the element at index = 0 is also the head element in a list of 1 element
	// Then check whether the head element is what we have inserted.
	thisList.getElement(currentPos, 0);
	actualCheck = samplePos.isPosEqual(&currentPos);

	if(expectedCheck != actualCheck)
	{
		cout << "[FAILED] Test Insert Head 1 Element Failed - body wrong" << endl;
		failCount++;
		passed = false;	
		return;
	}
	// The destructor will be called automatically for stack-allocated objects

	cout << "[OK] Test Insert Head 1 Element Passed" << endl;
	passCount++;	
}

// Test Case 2b - insertHead 5 Element 
// - Will require you to implement getHeadElement() and getTailElement() method.
void testInsertHead_5Element()
{
	objPos currentPos;
	objPos bodyPos{2, 5, 'a'};  
	objPos headPos{3, 3, 'm'};

	// Insert 4 body elements, then 1 unique head element
	objPosArrayList thisList;
	thisList.insertHead(bodyPos);
	thisList.insertHead(bodyPos);
	thisList.insertHead(bodyPos);
	thisList.insertHead(bodyPos);
	thisList.insertHead(headPos);

	int expectedSize = 5;
	int actualSize = thisList.getSize();
		
	// Confirm the list size is now 5
	if(expectedSize != actualSize)
	{
		cout << "[FAILED] Test Insert Head 5 Element Failed - size wrong" << endl;
		failCount++;
		passed = false;	
		return;
	}

	bool expectedCheck = true;
	bool actualCheck;

	// Then, check the head element is the unique element
	thisList.getHeadElement(currentPos);
	actualCheck = headPos.isPosEqual(&currentPos);

	if(expectedCheck != actualCheck)
	{
		cout << "[FAILED] Test Insert Head 5 Element Failed - head wrong" << endl;
		failCount++;
		passed = false;	
		return;
	}

	// Next, chech the body elements at index 1, 2, and 3.
	for(int i = 1; i < actualSize - 1; i++)
	{
		thisList.getElement(currentPos, i);
		actualCheck = bodyPos.isPosEqual(&currentPos);

		if(expectedCheck != actualCheck)
		{
			cout << "[FAILED] Test Insert Head 5 Element Failed - body wrong" << endl;
			failCount++;
			passed = false;	
			return;
		}	
	}

	// Finally, check the tail element is the body element
	thisList.getTailElement(currentPos);
	actualCheck = bodyPos.isPosEqual(&currentPos);

	if(expectedCheck != actualCheck)
	{
		cout << "[FAILED] Test Insert Head 5 Element Failed - tail wrong" << endl;
		failCount++;
		passed = false;	
		return;
	}
	// The destructor will be called automatically for stack-allocated objects

	cout << "[OK] Test Insert Head 5 Element Passed" << endl;
	passCount++;
}

/////////////////////////////////////////////////////////////////
// MY TEST CASES
/////////////////////////////////////////////////////////////////
void mytestInsertHead1() // Test for an empty element
{
    objPos currentPos;
    objPos samplePos{2, 5, 'a'};

    objPosArrayList thisList;
    thisList.insertHead(samplePos);

    int expectedSize = 1;
    int actualSize = thisList.getSize();

    if (expectedSize != actualSize)
    {
        cout << "[FAILED] Test Insert Head for Empty List Failed" << endl;
        failCount++;
        passed = false;
        return;
    }

    bool expectedCheck = true;
    bool actualCheck;

    thisList.getHeadElement(currentPos);
    actualCheck = samplePos.isPosEqual(&currentPos);

    if (expectedCheck != actualCheck)
    {
        cout << "[FAILED] Test Insert Head for Empty List Failed - head wrong" << endl;
        failCount++;
        passed = false;
        return;
    }

    thisList.getTailElement(currentPos);
    actualCheck = samplePos.isPosEqual(&currentPos);

    if (expectedCheck != actualCheck)
    {
        cout << "[FAILED] Test Insert Head for Empty List Failed - tail wrong" << endl;
        failCount++;
        passed = false;
        return;
    }

    thisList.getElement(currentPos, 0);
    actualCheck = samplePos.isPosEqual(&currentPos);

    if (expectedCheck != actualCheck)
    {
        cout << "[FAILED] Test Insert Head for Empty List Failed - body wrong" << endl;
        failCount++;
        passed = false;
        return;
    }

    cout << "[OK] Test Insert Head for Empty List Passed" << endl;
    passCount++;
}

/////////////////////////////////////////////////////////////////

// Test Case 3a - insertTail 1 Element 
void testInsertTail_1Element()
{
	objPos currentPos;
	objPos samplePos{2, 5, 'a'};  

	// Insert 1 sample element
	objPosArrayList thisList;
	thisList.insertTail(samplePos);

	int expectedSize = 1;
	int actualSize = thisList.getSize();
		
	// First check the list size is 1
	if(expectedSize != actualSize)
	{
		cout << "[FAILED] Test Insert Tail 1 Element Failed - size wrong" << endl;
		failCount++;
		passed = false;	
		return;
	}

	bool expectedCheck = true;
	bool actualCheck;

	// Then check whether the head element is what we have inserted.
	thisList.getHeadElement(currentPos);
	actualCheck = samplePos.isPosEqual(&currentPos);

	if(expectedCheck != actualCheck)
	{
		cout << "[FAILED] Test Insert Tail 1 Element Failed - head wrong" << endl;
		failCount++;
		passed = false;	
		return;
	}

	// Next, check whether the tail element is also the head element in a list of 1 element.
	thisList.getTailElement(currentPos);
	actualCheck = samplePos.isPosEqual(&currentPos);

	if(expectedCheck != actualCheck)
	{
		cout << "[FAILED] Test Insert Tail 1 Element Failed - tail wrong" << endl;
		failCount++;
		passed = false;	
		return;
	}

	// Finally, chech whether the element at index = 0 is also the head element in a list of 1 element
	// Then check whether the head element is what we have inserted.
	thisList.getElement(currentPos, 0);
	actualCheck = samplePos.isPosEqual(&currentPos);

	if(expectedCheck != actualCheck)
	{
		cout << "[FAILED] Test Insert Tail 1 Element Failed - body wrong" << endl;
		failCount++;
		passed = false;	
		return;
	}
	// The destructor will be called automatically for stack-allocated objects

	cout << "[OK] Test Insert Tail 1 Element Passed" << endl;
	passCount++;
}

// Test Case 3b - insertTail 5 Element 
void testInsertTail_5Element()
{
	objPos currentPos;
	objPos bodyPos{2, 5, 'a'};  
	objPos tailPos{3, 3, 'm'};

	// Insert 4 body elements, then 1 unique head element
	objPosArrayList thisList;
	thisList.insertTail(bodyPos);
	thisList.insertTail(bodyPos);
	thisList.insertTail(bodyPos);
	thisList.insertTail(bodyPos);
	thisList.insertTail(tailPos);

	int expectedSize = 5;
	int actualSize = thisList.getSize();
		
	// Confirm the list size is now 5
	if(expectedSize != actualSize)
	{
		cout << "[FAILED] Test Insert Tail 5 Element Failed - size wrong" << endl;
		failCount++;
		passed = false;	
		return;
	}
	bool expectedCheck = true;
	bool actualCheck;

	// Then, check the head element is the common body element
	thisList.getHeadElement(currentPos);
	actualCheck = bodyPos.isPosEqual(&currentPos);

	if(expectedCheck != actualCheck)
	{
		cout << "[FAILED] Test Insert Tail 5 Element Failed - head wrong" << endl;
		failCount++;
		passed = false;	
		return;
	}
	// Next, chech the body elements at index 1, 2, and 3.
	for(int i = 1; i < actualSize - 1; i++)
	{
		thisList.getElement(currentPos, i);
		actualCheck = bodyPos.isPosEqual(&currentPos);

		if(expectedCheck != actualCheck)
		{
			cout << "[FAILED] Test Insert Tail 5 Element Failed - body wrong" << endl;
			failCount++;
			passed = false;	
			return;
		}
	}

	// Finally, check the tail element is the body element
	thisList.getTailElement(currentPos);
	actualCheck = tailPos.isPosEqual(&currentPos);

	if(expectedCheck != actualCheck)
	{
		cout << "[FAILED] Test Insert Tail 5 Element Failed - tail wrong" << endl;
		failCount++;
		passed = false;	
		return;
	}
	// The destructor will be called automatically for stack-allocated objects

	cout << "[OK] Test Insert Tail 5 Element Passed" << endl;
	passCount++;
}

/////////////////////////////////////////////////////////////////
// MY TEST CASES
/////////////////////////////////////////////////////////////////
void mytestInsertTail1() // For empty list
{
    objPos currentPos;
    objPos samplePos{2, 5, 'a'};

    objPosArrayList thisList;
    thisList.insertTail(samplePos);

    int expectedSize = 1;
    int actualSize = thisList.getSize();

    if (expectedSize != actualSize)
    {
        cout << "[FAILED] Test Insert Tail for Empty List Failed - wrong size" << endl;
        failCount++;
        passed = false;
        return;
    }

    bool expectedCheck = true;
    bool actualCheck;

    thisList.getHeadElement(currentPos);
    actualCheck = samplePos.isPosEqual(&currentPos);

    if (expectedCheck != actualCheck)
    {
        cout << "[FAILED] Test Insert Tail for Empty List Failed - head wrong" << endl;
        failCount++;
        passed = false;
        return;
    }

    thisList.getTailElement(currentPos);
    actualCheck = samplePos.isPosEqual(&currentPos);

    if (expectedCheck != actualCheck)
    {
        cout << "[FAILED] Test Insert Tail for Empty List Failed - tail wrong" << endl;
        failCount++;
        passed = false;
        return;
    }

    thisList.getElement(currentPos, 0);
    actualCheck = samplePos.isPosEqual(&currentPos);

    if (expectedCheck != actualCheck)
    {
        cout << "[FAILED] Test Insert Tail Empty List Failed - body wrong" << endl;
        failCount++;
        passed = false;
        return;
    }

    cout << "[OK] Test Insert Tail Empty List Passed" << endl;
    passCount++;
}
/////////////////////////////////////////////////////////////////

// Test Case 4a - removeHead from 1 Element List
void testRemoveHead_1Element()
{
	objPos currentPos;
	objPos samplePos{2, 5, 'a'};  

	// Insert 1 sample element
	objPosArrayList thisList;
	thisList.insertHead(samplePos);

	thisList.removeHead();

	int expectedSize = 0;
	int actualSize = thisList.getSize();
	
	if(expectedSize != actualSize)
	{
		cout << "[FAILED] Test Remove Head 1 Element Failed" << endl;
		failCount++;
		passed = false;	
		return;
	}

	cout << "[OK] Test Remove Head 1 Element Passed" << endl;
	passCount++;

	// The destructor will be called automatically for stack-allocated objects
}

// Test Case 4b - removeHead from 5 Element list
void testRemoveHead_5Element()
{
	objPos currentPos;
	objPos bodyPos{2, 5, 'a'};  
	objPos headPos{3, 3, 'm'};

	// Insert 4 body elements, then 1 unique head element
	objPosArrayList thisList;
	thisList.insertHead(bodyPos);
	thisList.insertHead(bodyPos);
	thisList.insertHead(bodyPos);
	thisList.insertHead(bodyPos);
	thisList.insertHead(headPos);

	thisList.removeHead();
	
	int expectedSize = 4;
	int actualSize = thisList.getSize();
		
	// Confirm the list size is now 4
	if(expectedSize != actualSize)
	{
		cout << "[FAILED] Test Remove Head 5 Elements Failed, size wrong" << endl;
		failCount++;
		passed = false;	
		return;
	}

	bool expectedCheck = true;
	bool actualCheck;

	// Then, check the unique element has been removed
	thisList.getHeadElement(currentPos);
	actualCheck = bodyPos.isPosEqual(&currentPos);

	if(expectedCheck != actualCheck)
	{
		cout << "[FAILED] Test Remove Head 5 Elements Failed, head wrong" << endl;
		failCount++;
		passed = false;	
		return;
	}

	// Next, the rest of the elements are still common elements
	for(int i = 1; i < actualSize; i++)
	{
		thisList.getElement(currentPos, i);
		actualCheck = bodyPos.isPosEqual(&currentPos);

		if(expectedCheck != actualCheck)
		{
			cout << "[FAILED] Test Remove Head 5 Elements Failed, body wrong" << endl;
			failCount++;
			passed = false;	
			return;
		}
	}

	cout << "[OK] Test Remove Head 5 Elements Passed" << endl;
	passCount++;

	// The destructor will be called automatically for stack-allocated objects
}

/////////////////////////////////////////////////////////////////
// MY TEST CASES
/////////////////////////////////////////////////////////////////
void mytestRemoveHead1() // For one element
{
    objPos currentPos;
    objPos samplePos{2, 5, 'a'};

    objPosArrayList thisList;
    thisList.insertTail(samplePos);

    thisList.removeHead();

    int expectedSize = 0;
    int actualSize = thisList.getSize();

    if (expectedSize != actualSize)
    {
        cout << "[FAILED] Test Remove Head for a Single Element List Failed - size wrong" << endl;
        failCount++;
        passed = false;
        return;
    }

    cout << "[OK] Test Remove Head for a Single Element List Passed" << endl;
    passCount++;
}

void mytestRemoveHead2() // For an empty list
{
    objPosArrayList thisList;

    thisList.removeHead();

    int expectedSize = 0;
    int actualSize = thisList.getSize();

    if (expectedSize != actualSize)
    {
        cout << "[FAILED] Test Remove Head for Empty List Failed - size wrong" << endl;
        failCount++;
        passed = false;
        return;
    }

    cout << "[OK] Test Remove Head for Empty List Passed" << endl;
    passCount++;
}
/////////////////////////////////////////////////////////////////

// Test Case 5a - removeTail 1 Element 
void testRemoveTail_1Element()
{
	objPos currentPos;
	objPos samplePos{2, 5, 'a'};  

	// Insert 1 sample element
	objPosArrayList thisList;
	thisList.insertTail(samplePos);

	thisList.removeTail();

	int expectedSize = 0;
	int actualSize = thisList.getSize();
		
	// First check the list size is 1
	if(expectedSize != actualSize)
	{
		cout << "[FAILED] Test Remove Tail 1 Element Failed" << endl;
		failCount++;
		passed = false;	
		return;
	}

	cout << "[OK] Test Remove Tail 1 Element Passed" << endl;
	passCount++;
	// The destructor will be called automatically for stack-allocated objects
}

// Test Case 5b - removeTail 5 Element 
void testRemoveTail_5Element()
{
	objPos currentPos;
	objPos bodyPos{2, 5, 'a'};  
	objPos tailPos{3, 3, 'm'};

	// Insert 4 body elements, then 1 unique head element
	objPosArrayList thisList;
	thisList.insertTail(bodyPos);
	thisList.insertTail(bodyPos);
	thisList.insertTail(bodyPos);
	thisList.insertTail(bodyPos);
	thisList.insertTail(tailPos);

	thisList.removeTail();

	int expectedSize = 4;
	int actualSize = thisList.getSize();
		
	// Confirm the list size is now 4
	if(expectedSize != actualSize)
	{
		cout << "[FAILED] Test Remove Tail 5 Element Failed - size wrong" << endl;
		failCount++;
		passed = false;	
		return;
	}
	bool expectedCheck = true;
	bool actualCheck;

	// Then, check the tail element removed
	thisList.getTailElement(currentPos);
	actualCheck = bodyPos.isPosEqual(&currentPos);

	if(expectedCheck != actualCheck)
	{
		cout << "[FAILED] Test Remove Tail 5 Elements Failed, tail wrong" << endl;
		failCount++;
		passed = false;	
		return;
	}

	// Next, chech the body elements at index 1, 2, and 3.
	for(int i = 0; i < actualSize - 1; i++)
	{
		thisList.getElement(currentPos, i);
		actualCheck = bodyPos.isPosEqual(&currentPos);

		if(expectedCheck != actualCheck)
		{
			cout << "[FAILED] Test Remove Tail 5 Elements Failed, body wrong" << endl;
			failCount++;
			passed = false;	
			return;
		}	
	}

	cout << "[OK] Test Remove Tail 5 Elements Passed" << endl;
	passCount++;

	// The destructor will be called automatically for stack-allocated objects
}

/////////////////////////////////////////////////////////////////
// MY TEST CASES
/////////////////////////////////////////////////////////////////
void mytestRemoveTail1() // For empty list
{
    objPosArrayList thisList;

    thisList.removeTail();

    int expectedSize = 0;
    int actualSize = thisList.getSize();

    if (expectedSize != actualSize)
    {
        cout << "[FAILED] Test Remove Tail Empty List Failed - size wrong" << endl;
        failCount++;
        passed = false;
        return;
    }

    cout << "[OK] Test Remove Tail Empty List Passed" << endl;
    passCount++;
}

void mytestRemoveTail2() // For a single element
{
    objPos currentPos;
    objPos samplePos{2, 5, 'a'};

    objPosArrayList thisList;
    thisList.insertTail(samplePos);

    thisList.removeTail();

    int expectedSize = 0;
    int actualSize = thisList.getSize();

    if (expectedSize != actualSize)
    {
        cout << "[FAILED] Test Remove Tail for a Single Element List Failed - size wrong" << endl;
        failCount++;
        passed = false;
        return;
    }

    cout << "[OK] Test Remove Tail for a Single Element List Passed" << endl;
    passCount++;
}
/////////////////////////////////////////////////////////////////


int main(int argc, char const *argv[]) {
	
	
    testConstructor();
	// OUR TEST CASES
	mytestInsertHead1();

	testInsertHead_1Element();
	testInsertHead_5Element();
	// OUR TEST CASES
	mytestInsertHead1();

	testInsertTail_1Element();
	testInsertTail_5Element();
	// OUR TEST CASES
	mytestInsertTail1();

	testRemoveHead_1Element();
	testRemoveHead_5Element();
	// OUR TEST CASES
	mytestRemoveHead1();
	mytestRemoveHead2();

	testRemoveTail_1Element();
	testRemoveTail_5Element();
	// OUR TEST CASES
	mytestRemoveTail1();
	mytestRemoveTail2();
	
	if(passed)
		cout << "ALL TEST PASSED : " << passCount << " Passes." << endl;
	else
		cout << "TEST FAILED : " << passCount << " Passes, " << failCount << " Fails."  << endl;

    return passed;
}

