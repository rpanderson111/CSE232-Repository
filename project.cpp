#include<iostream>
using std::cout; using std::endl; using std::cin;
#include<vector>
using std::vector;
#include<string>
using std::string;
#include<fstream>
using std::ifstream;

int main() {
    //pulls in file
    ifstream input ("common_passwords.txt");
    
    //initializes vector for in common passwords, the string for user's input, and the string for theword within the file
    vector<string> in_common;
    string comparing_word, user_input;
    cout << "Give me a password: ";
    cin >> user_input;
    int input_size = user_input.size();
    cout << endl << "You provided a password of " << user_input << endl;
    int final_diff = 100000;
    //loop through each word within file
    while (true) {
        if (input >> comparing_word) {
            //compares user's password to word within file, giving how many letters shared there are (shared)
            int shared = 0;
            for (int i = 0; i < input_size; i++) {
                if (user_input[i] == comparing_word[i]) {
                    shared += 1;
                }
            }
            //checks length of user's word and word within file, then finds the difference
            int comparing_size = comparing_word.size();
            int diff;
            if (input_size >= comparing_size) {
                diff = input_size - shared;
            } else {
                diff = comparing_size - shared;
            }
            //checks length of in_common vector, then appends word if meets criteria
            if (in_common.empty() || diff == final_diff) {
                in_common.push_back(comparing_word);
            }
            else if (diff < final_diff) {
                final_diff = diff;
                in_common.clear();
                in_common.push_back(comparing_word);
            }
        } else if (input.eof()) {
            break;
        //moves to next word in file
        } else {
            input.clear();
            input.ignore();
        }
    }
    //final output
    cout << "The most similar passwords to " << user_input << " are: " << endl;
    sort(in_common.begin(), in_common.end());
    for (auto i: in_common) {
        cout << i << ", ";
    }
    cout << endl << "All of which are " << final_diff << " character(s) different." << endl;
