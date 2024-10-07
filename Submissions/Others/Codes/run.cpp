#include<bits/stdc++.h>
using namespace std;

const int ITER = 10000; // select the number of iterations

// populate and save the brute, code and gen files
int32_t main() {
  string brute = "g++ -o brute brute.cpp";
  system(brute.c_str()); // compiling the brute solution
  string code = "g++ -o code code.cpp"; 
  system(code.c_str()); // compiling the code solution
  string gen = "g++ -o gen gen.cpp";
  system(gen.c_str()); // compiling the gen

  auto st = clock();
  for (int t = 1; t <= ITER; t++) {
    cerr << "Trying for the " << t << "-th time :((\n";

    string in = "input.txt";
    string gen = "gen > input.txt";
    system(gen.c_str()); // generating a case

    string brute_solution = "brute < input.txt > brute_solution.txt";
    system(brute_solution.c_str());

    string code_solution = "code < input.txt > code_solution.txt";
    system(code_solution.c_str());

    ifstream brute_file;
    brute_file.open("brute_solution.txt"); //opening brute solution file
    string brute_output = "", line;
    while (getline(brute_file, line, '.')) { // reading every line including spaces and newlines
      brute_output += line;
    }

    ifstream code_file;
    code_file.open("code_solution.txt"); //opening code solution file
    string code_output = "";
    while (getline(code_file, line, '.')) { // reading every line including spaces and newlines
      code_output += line;
    }

    if (brute_output != code_output) {
      cout << "MISMATCH FOUND while running test case " << t << "\n\n";
      cerr << "MISMATCH FOUND while running test case " << t << "\n\n";
      cout << "Check the input.txt file to find the case, brute_solution.txt to find the brute output and similarly check the code_solution.txt\n";
      cerr << "Time taken = " << 1.0 * (clock() - st) / CLOCKS_PER_SEC << "s\n";
      exit(0);
    }

    brute_file.close();
    code_file.close();
  }
  cout << "No cases found!\n";
  cerr << "No cases found!\n";
  cerr << "Time taken = " << 1.0 * (clock() - st) / CLOCKS_PER_SEC << "s\n";
  return 0;
}