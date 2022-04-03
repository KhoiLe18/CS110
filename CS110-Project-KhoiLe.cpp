/**********************************
 * Name: Khoi Le
 * Student number: 200462293
 * Email: KTL841@uregina.ca
 * Course: CS 110
 * Assignment: Short Project
 * Last modified: December 6, 2021
***********************************/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void displayMenu();
void addRec(string [], int);
void searchRec(const string [], int);
void sortList(string [], int);
void deleteRec(string [], int);
void updateRec(string [], int);
void saveList(const string [], int);
void readList();
void displayList(const string [], int);

int main() {
  int choice;
  const int length_of_list = 9;
  string companyList[length_of_list] = {};

  displayMenu();

  while (choice != 9) {
    cin >> choice;

    switch (choice) {
        case 1:
            addRec(companyList, length_of_list);
            break;

        case 2:
            searchRec(companyList, length_of_list);
            break;

        case 3:
            sortList(companyList, length_of_list);
            break;

        case 4:
            deleteRec(companyList, length_of_list);
            break;

        case 5:
            updateRec(companyList, length_of_list);
            break;

        case 6:
            saveList(companyList, length_of_list);
            break;

        case 7:
            readList();
            break;

        case 8:
            displayList(companyList, length_of_list);
            cout << endl << endl;
            displayMenu();
            break;

				case 9:
						break;

        default:
            cout << "Not a valid choice" << endl << endl;
            displayMenu();
    }
	}


  return 0;
}

void displayMenu() {
  cout << "Main Menu:" << endl
       << "   1. Add a new record to the list" << endl
       << "   2. Search for a record" << endl
       << "   3. Descending sort of the list" << endl
       << "   4. Delete a record from the list" << endl
       << "   5. Update a record in the list" << endl
       << "   6. Save the list to a file" << endl
       << "   7. Read the list from a file" << endl
       << "   8. Display the list" << endl
       << "   9. Exit" << endl << endl
       << "Enter a choice: ";
}

void addRec(string complist[], int listLength) {
	int i = 0;
	bool full = true;
	while (i < listLength) {
		if (complist[i] == "") {
      cout << "Enter a name: ";
			getline(cin, complist[i]);
      getline(cin, complist[i]);
      full = false;
			break;
		}
		else
			i += 1;
	}

	if (full)
		cout << "The list is full" << endl;

	cout << endl << endl;

  displayMenu();
}

void searchRec(const string complist[], int listLength) {
	string recName;
  bool found = false;

  cout << "Enter a record's name: ";
	getline(cin, recName);
  getline(cin, recName);

	//Search for record
	for (int i = 0; i < listLength; i++) {
		if (complist[i] == recName) {
			found = true;
      break;
    }
		else
			found = false;
	}

  if (found)
    cout << "Record is found" << endl;
  else
    cout << "Record is not found" << endl;

	cout << endl << endl;

  displayMenu();
}

void sortList(string complist[], int listLength) {
  //Sort
  for (int i = 0; i < listLength; i++) {
      string temp;
      string largest = complist[i];
      int largestIndex = i;
      //Find the largest value
      for (int j = i + 1; j < listLength; j++) {
          if (complist[j] > largest) {
              largest = complist[j];
              largestIndex = j;
          }
        }
      //Swap the largest value with the current value
      temp = complist[i];
      complist[i] = complist[largestIndex];
      complist[largestIndex] = temp;
      
  }
  //Print out the sorted list
  displayList(complist, listLength);
  cout << endl << endl;

  displayMenu();
}

void deleteRec(string complist[], int listLength) {
  int deletedRow;

  displayList(complist, listLength);
  while (cin) {
    cout << endl << "Row to be deleted: ";
    cin >> deletedRow;

    //Check to see if the input is from 1-9 or not
    if (deletedRow > 9 || deletedRow < 1) {
      cout << "The list doesn't contain that row" << endl;
      break;
    }
    else {
      //Push the records behind the deleted row up
      for (int i = deletedRow ; i < listLength; i++)
          complist[i - 1] = complist [i];
      //Make the last row blank
      complist[listLength - 1] = "";
      cout << "The record in row " << deletedRow << " is deleted.";
      break;
    }
  }

  cout << endl << endl;

  displayMenu();
}

void updateRec(string complist[], int listLength) {
  int updatedRow;

  displayList(complist, listLength);
  while (cin) {
    cout << endl << "Row to be updated: ";
    cin >> updatedRow;

    //Check to see if the input is from 1-9 or not
    if (updatedRow > 9 || updatedRow < 1) {
      cout << "The list doesn't contain that row" << endl;
      break;
    }
    else {
      cout << endl << "Enter updated info: ";
      getline(cin, complist[updatedRow - 1]);
      getline(cin, complist[updatedRow - 1]);
      break;
    }
  }

  cout << endl << endl;

  displayMenu();
}

void saveList(const string complist[], int listLength) {
	ofstream outData;
	outData.open("company_list.txt");

	//Write content from the list to the file
	for (int i = 0; i < listLength; i++)
		outData << complist[i] << endl;

	outData.close();

	cout << "The list is saved" << endl;

	cout << endl << endl;

  displayMenu();
}

void readList() {
	ifstream inData;
	inData.open("company_list.txt");

	//Output the file's content to the console
	string temp;
	int i = 1;
	while (getline(inData, temp)) {
		cout << i << ". " << temp << endl;
		i += 1;
	}

	inData.close();

	cout << endl << endl;

  displayMenu();
}

void displayList(const string complist[], int listLength) {
  for (int i = 0; i < listLength; i++) {
      cout << i + 1 << ". " << complist[i] << endl;
  }
}
