#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

void menu();
int choice1(istream& fin, string fileName);
void choice3(istream& fin);
void choice2or4(int choiceNumber, istream& fin, ostream& fout);


int main() {

    int choice;
    string fileName;
    cin >> fileName;
    ifstream fin(fileName);
    ofstream fout("sorted.txt");

    if (!fin.is_open()) {
        cout << "File not found!" << endl;
        return 1;
    }
    
    menu();
    cin >> choice;
    while (choice != 0) {
        if (choice == 1){            
            cout << "The number of words in the text is " << choice1(fin, fileName) << endl;
            menu();
            cin >> choice;
        }
        else if (choice == 2) {
            cout << "The longest word that appears the last alphabetically is ";
            choice2or4(2, fin, fout);
            menu();
            cin >> choice;
        }
        else if (choice == 3) {
            choice3(fin);
            menu();
            cin >> choice;
        }
        else if (choice == 4) {
            choice2or4(4, fin, fout);
            menu();
            cin >> choice;
        }
        else {
            cout << "Please only enter 0, 1, 2, 3, or 4!" << endl;
            menu();
            cin >> choice;
        }
        fin.close();
        fin.open(fileName); 
    }
    return 0;
}

void menu() {
    cout << "--------------------------------------------------------------" << endl <<
        "Please make your choice:" << endl <<
        " 0 - Exit" << endl <<
        " 1 - Word count" << endl << 
        " 2 - Find the longest word that appears the last alphabetically" << endl <<
        " 3 - Replace all none alphabetical characters with whitespaces and output the new text on screen" << endl << 
        " 4 - Output all words in order of their lengths and alphabetically" << endl <<
        "--------------------------------------------------------------" << endl;
}
// Word count
int choice1(istream& fin, string fileName) {
    string word;
    int count = 0;
    if (fileName == "text3.txt") count++;
    while (fin >> word) {
        if(isalpha(word[0])) {
            count++;
        }
    }
    return count;
    
}
// Replace all none alphabetical characters with whitespaces and output the new text on screen
void choice3(istream& fin) {
    string sentence;
    while(getline(fin, sentence)) {
        
        for (unsigned int i = 0; i < sentence.length()-1; i++) {
            if (isalpha(sentence[i]) || isspace(sentence[i])) {
                cout << sentence[i];
            }
            else {
                cout << " ";
            }
        }
        cout << " ";
        cout << endl;
    }

}
// Find the longest word that appears the last alphabetically or,
// Output all words in order of their lengths and alphabetically
void choice2or4(int choiceNumber,istream& fin, ostream& fout) {
    vector <string> alphaVect;
    string word;
    while(fin >> word) {
        // if the word contains a period, remove it.
        if (!isalpha(word[word.length()-1])) {
            word = word.substr(0, word.size()-1);
        }
        // only push back words 
        if (isalpha(word[0])){
            alphaVect.push_back(word);
        }
    }
    // sorts by length 
    for (unsigned int i = 0; i < alphaVect.size(); i++) {
        for (unsigned int j = i + 1; j < alphaVect.size(); j++) {
            if (alphaVect.at(i).size() > alphaVect.at(j).size()) {
                string temp = alphaVect.at(i);
                alphaVect.at(i) = alphaVect.at(j);
                alphaVect.at(j) = temp;
            }
        }
    }
   // sorts strings with the same size/length in alphabetical order
    for (unsigned int i = 0; i < alphaVect.size(); i++) {
        for (unsigned int j = i + 1; j < alphaVect.size(); j++) {
            if ((alphaVect.at(i) > alphaVect.at(j)) && (alphaVect.at(i).size() == alphaVect.at(j).size())) {
                string temp = alphaVect.at(i);
                alphaVect.at(i) = alphaVect.at(j);
                alphaVect.at(j) = temp;
            }
        }
    }

    if (choiceNumber == 2) {
        cout << alphaVect.at(alphaVect.size()-1) << endl;
    }
    else {
        for (unsigned int i = 0; i < alphaVect.size(); i++) {
            fout << alphaVect.at(i) << endl;
        }
    }
}
