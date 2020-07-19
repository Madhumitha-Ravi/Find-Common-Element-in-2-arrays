// We will get two arrays - we need to find the common item 
// Input - 2 arrays of n size
// Output - return true or false
// What is important ? Time or space or memory ? Default assume Time
// For my approach I am considering it to be a character array
// m - Size of Array 1 ; n - size of Array 2;
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// First using naive or brute force technique 
bool CheckForCommonElement(char* p_Array1 , char* p_Array2,int nSizeofArray1,int nSizeofArray2)
{
  for(int i=0;i<nSizeofArray1;i++)
  {
    for(int j=0;j<nSizeofArray2;j++)
    {
      if(p_Array1[i] == p_Array2[j])
      {
        return true;
      }
    }
  }
  return false;
  // Time Complexity = O(n*m) ie O(nSizeofArray1*nSizeofArray2)
  // because we are looping through 2 different array
  //Space Complexity = O(1);
}
//Optimized method - As we know for the brute force technique time Complexity was O(m*n) - We need to now give an Optimal solution
bool CheckForCommonElementOptimized(char* p_Array1,char* p_Array2,int nSizeofArray1,int nSizeofArray2)
{
  // How to approach this ?
  // our goal is to avoid nested for loop - so we need to loop through 1st array once get the elements stored and then try to loop through the 2nd array to find if the element is there 
  //By this TimeComplexity will be of O(m+n) which is better that O(m*n)
  // How to store the element so that we are not looping through that container for the 2nd array 
  // store it an map - the element as key , value can be anything - our goal is to check whether the element of array 2 is present as key or not .
  // If it is present -- then return true -- element of array 2 is present in array 1
  // else return false
  map<char,int> Array1Lookup;
  for (int i = 0; i<nSizeofArray1;i++)
  {
    Array1Lookup.insert({p_Array1[i],1});
  }
  for(int j=0;j<nSizeofArray2;j++)
  {
    if(Array1Lookup.find(p_Array2[j]) != Array1Lookup.end())
    {
        return true;
    }
  }
  return false;
  //Time complexity of O(m+n)
  // Space Complexity of O(m).. because we are inserting into the map the elements of array1 which of size m
}

int main()
{
  char arr1[] = {'a', 'b', 'c', 'x'};
  char arr2[] = {'d','e','f'};
  int nSizeofArray1 = sizeof(arr1)/sizeof(arr1[0]);
  int nSizeofArray2 = sizeof(arr2)/sizeof(arr2[0]);
  if(nSizeofArray1 > 0 && nSizeofArray2 > 0)
  {
    string sRet;
    sRet=CheckForCommonElement(arr1, arr2,nSizeofArray1,nSizeofArray2)?"True":"False";
    cout<<"Result through brute force function : "<<sRet<<endl;
    sRet.erase();
    sRet= CheckForCommonElementOptimized(arr1,arr2,nSizeofArray1,nSizeofArray2)? "True":"False";
    cout<<"Result throught optimized function: "<<sRet<<endl;
  }
  else
  {
    cout<<"An Empty array...Cannot process";
  }
  // OutPut : 
  /*
  Result through brute force function : False
  Result throught optimized function: False
  */
}
