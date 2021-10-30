//Thrisha Kopula Fall 2020
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
using namespace std;
//expense class to create expense objects and print them using a tosString() function
class Expense {
  private:
  double amount;
  string description;
  public:
  Expense(double a, string d) {
    amount = a;
    description = d;
  }
  double getAmount() {
    return amount;
  }
  string getDescription() {
    return description;
  }
  void setAmount(double a) {
    amount = a;
  }
  void setDescription(string d) {
    description = d;
  }
  string toString() {
    stringstream s, amt;
    amt << setprecision(2) << fixed << amount << ")";
    s << "AMOUNT($" << left << setw(10) << amt.str() <<  " " << "DESCRIPTION(" << description << ")"; 
    string str = s.str();
    return str;
  }
};

//function to print out every current Expense object in the vector
void showAll(vector<Expense> v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i].toString() << endl;
  }
}

//function to display the Expense objects that has the word that the user inputted
void searchExpensesString(vector<Expense> v) {
  string searchStr;
  cout << "Please enter the search string: ";
  cin >> searchStr;
  //cout << endl;

  for (int i = 0; i < v.size(); i++) { 
    if (v[i].getDescription().find(searchStr) != -1) {
      cout << v[i].toString() << endl;
    }
  }
}

//function that looks through each Expense object and displays the ones that have a greater or equal amount
void searchExpensesGreater(vector<Expense> v) {
  double amt;
  cout << "Please enter the amount: ";
  cin >> amt;
  //cout << endl;

  for (int i = 0; i < v.size(); i++) {
    if (v[i].getAmount() >= amt) {
      cout << v[i].toString() << endl;
    }
  }
}

//function that allows the user to add a new Expense
vector<Expense> spend(vector<Expense> v) {
  double amt;
  string d;
  cout << "Please enter the description for the expense: ";
  cin >> d;
  cout << "Please enter the amount: ";
  cin >> amt;
  
  if (amt < 0) {
    while (amt < 0) {
      cout << "Invalid amount. Amount cannot be negative or string. Please try it again." << endl;
      cin >> amt;
    }
  }
  cout << endl;
  Expense e(amt, d); 
  v.push_back(e);
  cout << e.toString() << endl;
  return v;
}

//Function mostly taken from the modules pags in Canvas, which reads the file the user inputs and stores each line into an Expense object
vector<Expense> readFile(string d) {
  vector<Expense> test;
  ifstream fin(d);
  if (fin.is_open() == false) {
    cout << "Error: unable to open this data file: " << d << ". Please check location and filename." << endl ;
  } else {
    while(fin.eof() == false) {
      string oneLine ;
      getline(fin, oneLine) ;
      if (oneLine.size() > 0) {
        stringstream parser(oneLine) ;
        double amount ;
        parser >> amount ;
        string desc ;
        getline(parser, desc);
        desc.erase(0, desc.find_first_not_of(" "));
        Expense e(amount, desc);
        test.push_back(e);
      }
    }
    fin.close();
  }
  return test;
}

//main function that loops though the menu options until the user choose '5', and exits
int main(int argc, char * argv[]) {
  cout << endl;
  if (argc == 1) {
    cout << "Invalid usage. Please give an expense data file name." << endl;
    return 0;
  }
  string dataFileName = argv[1];
  vector<Expense> mainVec = readFile(dataFileName);
  cout << "Welcome to my expense manager plus." << endl;
  int menuNum;
  while (menuNum != 5) {
    cout << endl;
    cout << "Expense Management Menu:" << endl;
    cout << "1. Show all" << endl;
    cout << "2. Spend" << endl;
    cout << "3. Search expenses containing this string" << endl;
    cout << "4. Search expenses with greater than or equal to this amount" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your option: ";
    cin >> menuNum;
    cout << endl;
    if (menuNum == 1) {
      showAll(mainVec);
    } else if (menuNum == 2) {
      mainVec = spend(mainVec);
    } else if (menuNum == 3) {
      searchExpensesString(mainVec);
    } else if (menuNum == 4) {
      searchExpensesGreater(mainVec);
    }
  }
  
}
