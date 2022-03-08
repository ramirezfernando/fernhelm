#include <iostream>
#include <fstream>
#include <string>

using namespace std;


void menu();

int main() {

    int choice;

    ifstream fin("text1.txt");
    ofstream fout("sorted.txt");

    if (!fin.is_open()) {
        cout << ("File not found!") << endl;
        return 1;
    }
    
    cin >> choice;
    while (choice != 0) {


    }
    
    cout << "exit" << endl;


    return 0;
}




void menu() {
    cout << "--------------------------------------------------------------" << endl <<
        "Please make your choice: " << endl <<
        "0 - Exit" << endl <<
        "1 - Word count" << endl << 
        "2 - Find the longest word that appears the last alphabetically" << endl <<
        "3 - Replace all none alphabetical characters with whitespaces and output the new text on screen" << endl << 
        "4 - Output all words in order of their lengths and alphabetically" << endl <<
        "--------------------------------------------------------------" << endl;
}