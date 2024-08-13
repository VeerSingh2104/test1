#include <iostream>
#include <string>

using namespace std;
string encoding(string plaintext, int shift){
  string result = "";
  for(int i=0;i<plaintext.length();i++) {
    char c=plaintext[i];
    if(isupper(c)) {
      result += char (int(c+shift-65)%26+65);
    }
    else if (islower(c)) {
      result += char(int(c+shift-97)%26+97);
    }
    else {
      result += c;
    }
  }
  return result;
}

string decoding(string ciphertext, int shift) {
  return encoding(ciphertext, 26-shift);
}

int main() {
  string plaintext;
  int shift;
  cout<<"Enter the text: ";
  getline(cin,plaintext);
  
  cout<<"\nEnter the shift: ";
  cin>>shift;

  cout<<"\nCoded Text: "<<encoding(plaintext,shift)<<endl;
  cout<<"\nDecoded Text: "<<decoding(encoding(plaintext,shift),shift)<<endl;
  return 0;
}
      
