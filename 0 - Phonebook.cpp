/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int binarySearch(const vector<pair<string, string>>& phonebook, string name){
    
    int low = 0;
    int high = phonebook.size() - 1;
    
    while(low <= high){
        int mid = low + (high - low)/2;
        
        if (phonebook[mid].first == name){
            return mid;
        }
        else if (phonebook[mid].first < name){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    
    int choice;
    string name, number;
    vector<pair<string, string>> phonebook;
    bool flag = true;
    char c;

    do{
        
    cout << "Hi! What would you like to do?\n1. Add a contact(1) \n2. Look up a contact(2) \n3. Display phonebook(3) \n4. Delete a contact(4) \n5. Clear phonebook(5) \n6. Quit(6) \n" << endl;
    cin >> choice;
    cin.ignore();

        switch(choice){
        
            case 1: {
                cout << "\nEnter name of the contact." << endl;
                getline(cin, name);
                cout << "Enter number of the contact." << endl;
                getline(cin, number);
                phonebook.push_back({name, number});
                cout << "\nThe contact: " << name << " - " << number << " has been added to the phonebook.\n" << endl;
            
                break;
            }
            case 2: {
                cout << "\nEnter name of the contact you want to find" << endl;
                getline(cin, name);
                
                vector<pair<string, string>> sorted_phonebook = phonebook;
                sort(sorted_phonebook.begin(), sorted_phonebook.end());
                
                int pos = binarySearch(sorted_phonebook, name);
                
                if (pos != -1){
                    cout << "\nFound contact: " << sorted_phonebook[pos].first << ": " << sorted_phonebook[pos].second << "\n"<< endl;
                }
                else{
                    cout << "\nContact not found.\n" << endl;
                }
                break;
            } 
            case 3: {
            
                if (phonebook.empty()){
                    cout << "\nPhonebook is empty." << endl;
                }
                else{
                    for (const auto& pair: phonebook){
                        cout << pair.first << ": " << pair.second << endl;
                    }
                }
                break;
            }
            
            case 4: {
                
                cout << "Enter the name of the contact you want to delete: " << endl;
                getline(cin, name);
                
                int p = 0;
                
                while (phonebook[p].first != name){
                    p++;
                }
                phonebook.erase(phonebook.begin() + p);
                cout << "Contact has been deleted." << endl;
                
                break;
            }
            
            case 5: {
                
                cout << "This is going to erase all your phonebook data. Are you absolutely sure? (y/n)" << endl;
                cin >> c;
                
                if (c == 'y' || c == 'Y'){
                    
                    phonebook.clear();
                    cout << "Phonebook has been cleared." << endl;
                } 
                break;
            }
            
            case 6: {
                
                flag = false;
                break;
            }
            
            default: {
                cout << "Select a choice shown above: 1, 2, 3, 4, 5 or 6" << endl;
            }    
        }
        
    } while (flag);
    
    return 0;
}
