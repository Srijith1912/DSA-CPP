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

    do{
        
    cout << "Hi! What would you like to do?\n1. Add a contact(1) \n2. Look up a contact(2) \n3. Display phonebook(3) \n4. Quit(4) \n" << endl;
    cin >> choice;
    cin.ignore();

    switch(choice){
    
        case 1: {
            cout << "Enter name of the contact." << endl;
            getline(cin, name);
            cout << "Enter number of the contact." << endl;
            getline(cin, number);
            phonebook.push_back({name, number});
            cout << "The contact: " << name << "- " << number << " has been added to the phonebook." << endl;
        
            break;
        }
        case 2: {
            cout << "Enter name of the contact you want to find" << endl;
            getline(cin, name);
            
            vector<pair<string, string>> sorted_phonebook = phonebook;
            sort(sorted_phonebook.begin(), sorted_phonebook.end());
            
            int pos = binarySearch(sorted_phonebook, name);
            
            if (pos != -1){
                cout << "Found contact: " << sorted_phonebook[pos].first << ": " << sorted_phonebook[pos].second << endl;
            }
            else{
                cout << "Contact not found." << endl;
            }
            
            break;
        } 
        case 3: {
        
            if (phonebook.empty()){
                cout << "Phonebook is empty." << endl;
            }
            else{
                for (const auto& pair: phonebook){
                    cout << pair.first << ": " << pair.second << endl;
                }
            }
            break;
        }
        case 4: {
            
            flag = false;
            break;
        }    
        default: {
            cout << "Select a choice shown above: 1, 2, 3 or 4" << endl;
        }    
    }
        
    } while (flag);
    
    return 0;
}