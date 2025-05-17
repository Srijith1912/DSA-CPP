# DSA-CPP
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main(){

  string name, phone_number;
  char c;
  unordered_map<string, string> phonebook;

  do{
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter phone number: ";
    getline(cin, phone_number);
    phonebook[name] = phone_number;
    cout << "Add more contacts? (y/n)" << endl;
    cin >> c;
    cin.ignore();
  } while (c == 'y' || c == 'Y');

  cout << "\nPhonebook: " << endl;
  for (const auto& pair : phonebook) {
    cout << pair.first << ": " << pair.second << endl;
  }

return 0;
}
