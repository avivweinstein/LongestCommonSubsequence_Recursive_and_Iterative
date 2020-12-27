#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <ctime>
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


cout << "Enter trial time for iterative version (less than " << min(m, n)<< "): "<< endl;
cin >> iterative_runs;
cout << "Enter trial time for recursive version (less than 20): " << endl;
cin >> recursive_runs;

cout << "Beginning: " << iterative_runs << endl;
cout << "Recursive: " << recursive_runs << endl;
cout << "\n" << endl;

/*for(int i=1; i<=iterative_runs; i++){
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
}*/

cout << "\n" << endl;
cout << "\n" << endl;

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





}
