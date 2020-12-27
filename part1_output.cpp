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

cout << "X: " <<X<< endl;
cout << "" << endl;
cout << "Y: " <<Y<< endl;
cout << "" << endl;
cout << "m: " <<m<< endl;
cout << "n: " <<n<< endl;
cout << "" << endl;

int len = lcs_it(C, X, Y, m, n);
cout << "LCS length using iterative method with 2D Array: " << len <<endl;
cout << "" << endl;
cout << "Resulting LCS string using backtrack method: " << backtrack_recursive(C, X, Y, m, n) << endl;

}
