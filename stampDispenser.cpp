//
//  stampDispenser.cpp
//
//  Created by Vetri Selvi Vairamuthu on 9/5/15.
//  Copyright (c) 2015 Vetri Selvi Vairamuthu. All rights reserved.
//
#include <stdlib.h>
#include <assert.h>

/// <summary>
/// Facilitates dispensing stamps for a postage stamp machine.
/// </summary>
class StampDispenser
{
private:
    int *stampDenominations;
    size_t numStampDenominations;
public:
    /// <summary>
    /// Initializes a new instance of the <see cref="StampDispenser"/> class that will be
    /// able to dispense the given types of stamps.
    /// </summary>
    /// <param name="stampDenominations">
    /// The values of the types of stamps that the machine has.
    /// Should be sorted in descending order and contain at least a 1.
    /// </param>
    /// <param name="numStampDenominations">
    /// The number of types of stamps in the stampDenominations array.
    /// </param>
    StampDispenser(const int* stampDenominations, size_t numStampDenominations);
    /// <summary>
    /// The destructor - Releases resources
    /// </summary>    
    ~StampDispenser();
    /// <summary>
    /// Returns the minimum number of stamps that the machine can dispense to
    /// fill the given request.
    /// </summary>
    /// <param name="request">
    /// The total value of the stamps to be dispensed.
    /// </param>
    /// <returns>
    /// The minimum number of stamps needed to fill the given request.
    /// </returns>
    int CalcNumStampsToFillRequest(int request);

};

/// <summary>
/// Constructor method definition
/// </summary>
 StampDispenser(const int* stampDenominations, size_t numStampDenominations){



 }

/// <summary>
/// Destructor method definition
/// </summary>
StampDispenser::~StampDispenser() {
    delete [] m_stampDenominations;
}

int main()
{

    int num;
    int stampDenominations[] = {90, 30, 24, 10, 6, 2, 1};
    StampDispenser stampDispenser(stampDenominations, 7);
    /// <summary>
    /// Displays the available denominations
    /// </summary>
    cout << "The Denominations available are: "<<endl;
    for (int i = 0; i <= 7; i++)
    {
        cout << stampDenominations[i] << "  ";
        
    }
    cout<<endl;

    cout<<"Enter the amount" <<endl;
    cin>>num;
    ////assert(stampDispenser.CalcNumStampsToFillRequest(18) == 3);

    assert(stampDispenser.CalcNumStampsToFillRequest(18) == 3);
    cout << "The minimum number of Stamps to dispense the entered amount is: "<<stampDispenser.CalcNumStampsToFillRequest(num)<<endl;

    return 0;
}
    
    

