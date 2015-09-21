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
    int * iStampDenominations; 
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
 StampDispenser::StampDispenser(const int* stampDenominations, size_t numStampDenominations){
    iStampDenominations = new int[numStampDenominations];
    int i;
    for (i = 0; i < numStampDenominations; i++ ){
        iStampDenominations[numStampDenominations - i - 1] = stampDenominations[i];
    }
    numStamps = numStampDenominations;
}

int StampDispenser::minNumberOfStamps(vector<int> combinationsOfDenominations)
{
        int minValue=combinationsOfDenominations[0];
        for(int i=1; i<combinationsOfDenominations.size(); i++ )
        {
            if(combinationsOfDenominations[i]<minValue)
                minValue=combinationsOfDenominations[i];
        }
        return minValue;
    
}

/// <summary>
/// Destructor method definition
/// </summary>
StampDispenser::~StampDispenser() {
    delete [] iStampDenominations;
}

int main()
{
    int stampDenominations[] = {90, 30, 24, 10, 6, 2, 1};
    StampDispenser stampDispenser(stampDenominations, 7);
    
    /// <summary>
    /// User Interactive scan and print of input & output statements
    /// </summary>
    
    int num;
    cout << "The Denominations available are: "<<endl;
    
    for (int i = 0; i <= 6; i++)
    {
        cout << stampDenominations[i] << "  ";
        
    }
    cout<<endl;
    
    cout<<"Enter the amount" <<endl;
    cin>>num;
    
    
    assert(stampDispenser.CalcNumStampsToFillRequest(18) == 3);
    cout << "The minimum number of Stamps to dispense the entered amount is: "<<stampDispenser.CalcNumStampsToFillRequest(num)<<endl;

    
    return 0;
}
    
    

