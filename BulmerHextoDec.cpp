// Mark Bulmer - CSC 234 - 4-28-2022 
// Hexadecimal to Decimal Converter

#include<iostream>
#include<stdexcept>
#include<string>
#include<cctype>
using namespace std;

int hex2Dec(const string& hexString);
int convertHexToDec(char ch);

int hex2Dec(const string& hexString) 
{
  int value = 0; 
  for (unsigned int i = 0; i < hexString.size(); i++)
     value = value * 16 + convertHexToDec(toupper(hexString[i]));
  return value;
}

// The function returns an int for a hex digit. 
// Throws an invalid_argument("Not a hex number") if the hex character is invalid
int convertHexToDec(char ch)
{ 
	if (ch >= 'A' && ch <= 'F')
		return 10 + (ch - 'A');
	else if (ch <= '9' && ch >= '0')
		return ch - '0';
	else
		throw invalid_argument("Not a hex number");
}

int main()
{
	string hexString;
	cout << "Enter a hex number: ";
	cin >> hexString;
	
  try
  {
    cout << hex2Dec(hexString);
  }
  catch(invalid_argument& ex)
  {
    cout << "Not a hex number";
  }

  return 0;
}