//
//  stampDispenser.cpp
//
//  Created by Vetri Selvi Vairamuthu on 9/5/15.
//  Copyright (c) 2015 Vetri Selvi Vairamuthu. All rights reserved.
//
#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include <vector>

using namespace std;


/// <summary>
/// Facilitates dispensing stamps for a postage stamp machine.
/// </summary>
class StampDispenser
{
private:
    /// Private instance variables/parameters
    int * iStampDenominations; 
    size_t iNumStampDenominations;
    ///<method>
    /// Method to determine the minimum value among the possible combinations of denominations
    int minNumberOfStamps(vector<int> combinationsOfDenominations);
    /// </method>
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
    /// The destructor -  free the resources acquired by the object
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

StampDispenser::StampDispenser(const int* stampDenominations, size_t numStampDenominations){
    iStampDenominations = new int[numStampDenominations];
    int i;
    for (i = 0; i < numStampDenominations; i++ ){
        iStampDenominations[numStampDenominations - i - 1] = stampDenominations[i];
    }
    iNumStampDenominations = numStampDenominations;
}

int StampDispenser::CalcNumStampsToFillRequest(int request)
{
  
    int *minimumStampsToFillRequest = new int [request+1];
    minimumStampsToFillRequest[0]=0;
    for(int i=1; i<=request; i++)
    {
        //Vector which holds the different possible combinations of denominations for a particular request value
        vector<int> combinationsOfDenominations;
        for(int j=0; j<iNumStampDenominations; j++)
        {
             //If the value of the request num is greater than the (jth element) of the denomination,
             //then the (jth element) of the denomination is taken as one of the possible denominations
            if(i>=iStampDenominations[j])
            {
                int valueRemaining= i-iStampDenominations[j];
                combinationsOfDenominations.push_back(minimumStampsToFillRequest[valueRemaining] + 1);
            }
        }
        //Pass the computed combinations to the 'minNumberOfStamps' method,
        //to retrieve the minimum value of the 'combinationsofDenominations' vector
        int minNum=minNumberOfStamps(combinationsOfDenominations);
        minimumStampsToFillRequest[i]=minNum;
    }
    return minimumStampsToFillRequest[request];
    
    
    
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


StampDispenser::~StampDispenser() 
{
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
    
    

