#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <ctime>
using namespace std;

//This function compues the length of the LCS in an iterative manner
//Takes in a 2D array, C.
//Two strings, X and Y to be compared
//Two ints, m and n, which are the lengths of Strings X and Y respectively.
int lcs_it(int **C, string X, string Y, int m, int n){
 for(int i = 0; i<=m; i++){
    for(int j = 0; j<=n; j++){
      if(i==0 || j==0){
        C[i][j] == 0;
      }
      else if(X[i-1]==Y[j-1]){
        C[i][j] = (1 + C[i-1][j-1]);
      }
      else{
        C[i][j] = max(C[i-1][j],C[i][j-1]);
      }
    }
  }
  return C[m][n];
}

//This function compues the actual string of the LCS in an iterative manner
//Takes in a 2D array, C.
//Two strings, X and Y to be compared
//Two ints, m and n, which are the lengths of Strings X and Y respectively.
string backtrack(int **C, string X, string Y, int m, int n){

  int index = C[m][n];
  char LCS[index+1];
  LCS[index] = '\0';

  int i = m;
  int j = n;

  while (i>0 && j>0){
    if(C[i-1][j] == C[i][j-1]){
      LCS[index-1] = X[i-1];
      index--;
      i--;
      j--;
    }
    else if (C[i-1][j] > C[i][j-1]){
      i--;
    }
    else {
      j--;
    }
  }
    string string_LCS(LCS);
    return string_LCS;
}

//This function compues the actual string of the LCS in a recursive manner
//Takes in a 2D array, C.
//Two strings, X and Y to be compared
//Two ints, m and n, which are the lengths of Strings X and Y respectively.
string backtrack_recursive(int **C, string X, string Y, int m, int n){

  int index = C[m][n];
  char LCS[index+1];
  LCS[index] = '\0';

  if(m==0 || n==0){
    return string("");
  }
  else if(X[m-1] == Y[n-1]){
    return backtrack_recursive(C, X, Y, m-1, n-1) + X[m-1];
  }
  else if(C[m-1][n] >C[m][n-1]){
    return backtrack_recursive(C, X, Y, m-1, n);
  }
  else{
    return backtrack_recursive(C, X, Y, m, n-1);
  }
}

//Returns the LCS length in a recursive manner.
//Inputs are: 
//Two strings, X and Y to be compared
//Two ints, m and n, which are the lengths of Strings X and Y respectively.
int lcs_re(string X, string Y, int m, int n){
  if ((m==0) || (n==0)){
    return 0;
  }
  if (X[m-1] == Y[n-1]){
    return (1 + lcs_re(X, Y, m-1, n-1));
  }
  else{
    return max(lcs_re(X, Y, m-1, n), lcs_re(X, Y, m, n-1));
  }
}

//Returns the LCS length in an iterative manner.
//Inputs are: 
//Two strings, X and Y to be compared
//Two ints, m and n, which are the lengths of Strings X and Y respectively.
int lcs_it_test(string X, string Y, int m, int n ){
  //Making local 2D array, called C
  int C[m+1][n+1];

  for(int i=0; i<=m; i++){
    for(int j=0; j<=n; j++){
      if(i==0 || j == 0){
        C[i][j] = 0;
      }
      else if(X[i-1]==Y[j-1]){
        C[i][j] = (1 + C[i-1][j-1]);
      }
      else{
        C[i][j] = max(C[i-1][j],C[i][j-1]);
      }
    }
  }
  return C[m][n];
}

int main() {
  string X;
  string Y;
  int iterative_runs = 0;
  int recursive_runs = 0;
  int start_s;
  int stop_s;

  ifstream inputFile("input.txt");
  inputFile >> X >> Y;
  inputFile.close();

//Need to calculate length of each of the input strings after we assign values to the strings
  int m  = X.size();
  int n = Y.size();

int **C = new int*[m+1];
for (int i=0; i<m+1; ++i) {
  C[i]= new int [n+1];
}
  
cout << "Enter trial time for iterative version (less than " << min(m, n)<< "): "<< endl;
cin >> iterative_runs;
cout << "Enter trial time for recursive version (less than 20): " << endl;
cin >> recursive_runs;

cout << "Beginning: " << iterative_runs << endl;
cout << "Recursive: " << recursive_runs << endl;
cout << "\n" << endl;

cout << "X: " <<X<< endl;
cout << "\n" << endl;
cout << "Y: " <<Y<< endl;
cout << "\n" << endl;
cout << "m: " <<m<< endl;
cout << "n: " <<n<< endl;
cout << "\n" << endl;

/****************************Testing Block****************************/

int **C_test = new int*[m+1];
for (int i=0; i<m+1; ++i) {
  C_test[i]= new int [n+1];
}

string test_X = "";
string test_Y = "";

//test_X = "AGCAT";
//test_Y = "GAC";

//test_X = "ABCD";
//test_Y = "ABCD";

//test_X = "DCBA";
//test_Y = "ABCD";

//test_X = "AACCTTGG";
//test_Y = "ACACTGTGA";

test_X = "longest";
test_Y = "stone";

int test_m  = test_X.size();
int test_n = test_Y.size();

cout << "test_X: " <<test_X<< endl;
cout << "test_Y: " <<test_Y<< endl;
cout << "test_m: " <<test_m<< endl;
cout << "test_n: " <<test_n<< endl;

int len_test_it = lcs_it(C_test, test_X, test_Y, test_m, test_n);
int lcs_test_recursive = lcs_re(test_X, test_Y, test_m, test_n);
cout <<"" << endl;
cout << "Iterative Backtrack: " << len_test_it <<endl;
cout << "Recursive Backtrack: " << lcs_test_recursive <<endl;
cout << "" << endl;

cout << "Test LCS string ITERATIVE is: : " << backtrack(C_test, test_X, test_Y, test_m, test_n) << endl;
cout << "Test LCS string RECURSIVE is: : " << backtrack_recursive(C_test, test_X, test_Y, test_m, test_n) << endl;
cout << "" << endl;
/****************************Testing Block****************************/

int len = lcs_it(C, X, Y, m, n);
cout << "LCS length using iterative method with 2D Array: " << len <<endl;
cout << "" << endl;
int len_no2DArray = lcs_it_test(X,Y,m,n);
cout << "LCS length using iterative method without 2D Array: " << len_no2DArray <<endl;
cout << "" << endl;
//int lenRecursive = lcs_re(X,Y,m,n);
//cout << "LCS length using recursive method without 2D Array: " << lenRecursive <<endl;
//NEED TO TEST THIS FUNCTION WITH SMALLER LENGTHS


cout << "Iterative Backtrack: " << backtrack(C, X, Y, m, n) << endl;
cout << "" << endl;
cout << "Recursive Backtrack: " << backtrack_recursive(C, X, Y, m, n) << endl;

/**********Program Execution Time Block**********/

cout << "" << endl;
cout << "" << endl;

for(int i=1; i<=iterative_runs; i++){
  cout <<"Iterative Test. Loop #: "<< i << endl;
  start_s=clock();
  cout << "LCS with strings of length i= "<< i << " is: "<<lcs_it_test(X,Y,i,i) << endl;
  stop_s=clock();
  clog << i << "\t" << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
}

for (int j=1; j<=recursive_runs; j++){
  cout <<"Recursive Test. Loop #: "<< j << endl;
  start_s=clock();
  cout << "LCS with strings of length j= "<<j << " is: "<<lcs_re(X,Y,j,j) << endl;
  stop_s=clock();
  clog << j << "\t" << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
}

cout << "" << endl;
cout << "" << endl;

for(int i=1; i<=800; i++){
  cout <<"Iterative Test. Loop #: "<< i << " of 800" << endl;
  start_s=clock();
  cout << "LCS with strings of length i= "<< i << " is: "<<lcs_it_test(X,Y,i,i) << endl;
  stop_s=clock();
  clog << i << "\t" << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
}

cout << "\n" << endl;
cout << "\n" << endl;

for (int j=1; j<=20; j++){
  cout <<"Recursive Test. Loop #: "<< j << " of 20" << endl;
  start_s=clock();
  cout << "LCS with strings of length j= "<<j << " is: "<<lcs_re(X,Y,j,j) << endl;
  stop_s=clock();
  clog << j << "\t" << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
}
/**********Program Execution Time Block**********/
}
