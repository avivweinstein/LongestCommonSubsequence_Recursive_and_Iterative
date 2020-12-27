#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

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

string backtrack(int **C, string X, string Y, int m, int n){ //Using this function to test out adding chars to a char array.

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

string backtrack_recursive(int **C, string X, string Y, int m, int n){ //This will return the LCS string itself in a recursive manner.

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


int main() {
  string X;
  string Y;

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

int **C_test = new int*[m+1];
for (int i=0; i<m+1; ++i) {
  C_test[i]= new int [n+1];
}

string test_X = "";
string test_Y = "";

test_X = "AGCAT";
test_Y = "GAC";

//test_X = "ABCD";
//test_Y = "ABCD";

//test_X = "DCBA";
//test_Y = "ABCD";

//test_X = "AACCTTGG";
//test_Y = "ACACTGTGA";

//test_X = "longest";
//test_Y = "stone";

int test_m  = test_X.size();
int test_n = test_Y.size();

cout << "test_X: " <<test_X<< endl;
cout << "test_Y: " <<test_Y<< endl;
cout << "test_m: " <<test_m<< endl;
cout << "test_n: " <<test_n<< endl;

int len_test_it = lcs_it(C_test, test_X, test_Y, test_m, test_n);
int lcs_test_recursive = lcs_re(test_X, test_Y, test_m, test_n);
cout << "\n" << endl;
cout << "Test LCS length using ITERATIVE method: " << len_test_it <<endl;
cout << "Test LCS length using RECURSIVE method: " << lcs_test_recursive <<endl;
cout << "\n" << endl;



cout << "Test LCS string ITERATIVE is: : " << backtrack(C_test, test_X, test_Y, test_m, test_n) << endl;
cout << "Test LCS string RECURSIVE is: : " << backtrack_recursive(C_test, test_X, test_Y, test_m, test_n) << endl;
cout << "\n" << endl;


/*cout << "X: " <<X<< endl;
cout << "\n" << endl;
cout << "Y: " <<Y<< endl;
cout << "\n" << endl;
cout << "m: " <<m<< endl;
cout << "n: " <<n<< endl;


int len = lcs_it(C, X, Y, m, n);
cout << "Full LCS using iterative method: " << len <<endl;
cout << "Backtrack: " << backtrack(C, X, Y, m, n) << endl;
cout << "Backtrack: " << backtrack_recursive(C, X, Y, m, n) << endl;*/

}
