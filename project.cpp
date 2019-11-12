#include<iostream>
using std::cout; using std::endl; using std::cin;
#include<vector>
using std::vector;
#include<string>
using std::string;
#include<functional>
using std::multiplies; using std::minus; using std::plus;
#include<numeric>
using std::accumulate;
#include<algorithm>
using std::remove_if; using std::copy; using std::count_if; using std::sort; using std::copy_if;
#include<iterator>
using std::ostream_iterator; using std::back_inserter;
#include<fstream>
using std::ifstream;
#include<typeinfo>
#include<iomanip>
using std::setprecision; using std::fixed;

int main() {
    ifstream input ("common_passwords.txt");
    vector<string> in_common;
    string comparing_word;
    string user_input;
    cout << "Give me a password: ";
    cin >> user_input;
    int input_size = user_input.size();
    cout << endl << "You provided a password of " << user_input << endl;
    int final_diff = 100000;
    while (true) {
        if (input >> comparing_word) {
            int shared = 0;
            for (int i = 0; i < input_size; i++) {
                if (user_input[i] == comparing_word[i]) {
                    shared += 1;
                }
            }
            int comparing_size = comparing_word.size();
            int diff;
            if (input_size >= comparing_size) {
                diff = input_size - shared;
            } else {
                diff = comparing_size - shared;
            }
            //cout << "Shared: " << shared << " Size: " << comparing_size << " Difference: " << diff << endl;
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
        } else {
            input.clear();
            input.ignore();
        }
    }
    cout << "The most similar passwords to " << user_input << " are: " << endl;
    sort(in_common.begin(), in_common.end());
    for (auto i: in_common) {
        cout << i << ", ";
    }
    cout << endl << "All of which are " << final_diff << " character(s) different." << endl;
