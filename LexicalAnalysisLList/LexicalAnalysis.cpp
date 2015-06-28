#include "LListDsEasy.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <sstream>
#include <conio.h>
#include <stack>

const string tableOfOperators[] = { "+", "-", "/", "*", "=", "<", ">", "++", "--", "<<", ">>", "!", "!=", "&", "&&", "|", "||", "[", "]", "=", "==" };
const char tableOfPunctuators[] = { ';', ',', '.', '(', ')', '{', '}' };
const string tableOfKeywords[] = { "auto", "bool", "BEGIN", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "ELSE", "ELSEIF", "END", "enum", "extern", "float", "for", "FOR", "goto", "if", "IF", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while", "WHILE", "asm", "_ss", "interrupt", "_cs", "cdecl", "near", "_ds", "far", "pascal", "_es", "huge", "catch", "class", "delete", "friend", "inline", "new", "operator", "overload", "private", "protected", "public", "template", "this", "throw", "try", "virtual" };
const string booleanValues[] = { "true", "false" };
char name[64];
char *cstr;
int charPointer; //pointer to each character in the file

int numOfStringConstants; //the number of string literal constants.
int numOfCharLiterals; //the number of character literal constants.
int numOfIdentifiers; //the number of identifiers
int numOfBooleanConstants; //the number of boolean constants
int numOfKeywords; //the number of keywords
int numOfOperators; //the number of operators
int numOfPunctuators; //the number of punctuators
int numOfIntegerConstants; //the number of integer constants
int numOfFloatConstants; //the number of float constants

void skipDirective(int&);
void skipComment(int&);

//prototypes of the functions used.(DFA's).
bool isStringLiteral(string);

bool isIdentifier(string);
//bool isBooleanValue(string);
bool isPunctuator(char);
bool isOperator(string);
bool isKeyword(string);
bool isInteger(string);
bool isFloat(string);

//prototypes of the functions used to find the ending of each kind of lexeme.
//string findEndQuote(int&); //find the endquote if a starting quote is found.
//string findEndApostrophe(int&); //find the ending apostrophe if an apostrophe is found.
string findEndOfIdentifier(int&); //find the end of the identifier if a letter or _ is found.
string findEndOperator(int&);
string findEndOfNum(int&);

char ch; //will hold each character in the file.
string findEndOfIdentifier(int &cpointer);
void skipComment(int &cpointer);

//fstream cppfile; //the stream used to open the file.
string output; //the string in which the contents of the file will be inserted.
string lexeme; //the string used to hold the value of each lexeme
int main(){

	LList Identifiers;
	LList Keywords;
	LList Punctuators;
	LList Operators;
	LList Constants;
	numOfStringConstants = 0;
	numOfCharLiterals = 0;
	numOfIdentifiers = 0;
	numOfBooleanConstants = 0;
	numOfKeywords = 0;
	numOfOperators = 0;
	numOfPunctuators = 0;
	numOfIntegerConstants = 0;
	numOfFloatConstants = 0;
	fstream cppfile; //the stream used to open the file.

	int numOfConstants = 0;
	char filename[32];

	output = ""; //initialize output to a blank string
	charPointer = 0; //point to the first character

	cout << "Enter the name of the file you want to analyze.\n";
	cout << "Note: It should within the same directory as your program: ";
	cin.getline(filename, 30);

	//read the file and place the contents to output.
	cppfile.open(filename, ios::in);

	if (!cppfile)
	{
		cout << "\n Unable to open the input file." << endl;
		cout << "\n Press any key to exit.";

		_getch();
		exit(0);
	}

	while (!cppfile.eof()){
		cppfile.get(ch); //get each character from the file
		output = output + ch; //append each character to the output string.
	}

	cppfile.close(); //close the file

	cout << "\nTHE PROGRAM\n\n";
	while (charPointer < output.length() - 1){
		cout << output[charPointer];
		charPointer++;
	}

	cout << "\n\n";
	//read the output string character by character.
	cout << "\nRESULTS...\n\n";

	charPointer = 0;

	while (charPointer < output.length() - 1){
		//if a letter or a _ is found then this may be an identifier...
		if ((isalpha(output[charPointer])) || (output[charPointer] == '_')){

			lexeme = findEndOfIdentifier(charPointer);
			
			if (isKeyword(lexeme)){
				numOfKeywords++; //increment the number of keywords.
				
				char *cstr = new char[lexeme.length() + 1];
				strcpy(cstr, lexeme.c_str());
				Keywords.InsertInBack(cstr);
				// do stuff
				delete[] cstr;
				
			}

		}

		else if (output[charPointer] == '/'){
			skipComment(charPointer);
		}

		else if (output[charPointer] == '#'){
			//skip the directive and move the character pointer
			skipDirective(charPointer);
		}

		else if (strchr("+-/*=<>!&|[]", output[charPointer])){
			lexeme = findEndOperator(charPointer); //check if there are operators beside it too

			if (isOperator(lexeme)){
				numOfOperators++;

				char *cstr = new char[lexeme.length() + 1];
				strcpy(cstr, lexeme.c_str());
				// do stuff
				Operators.InsertInBack(cstr);
				delete[] cstr;
				
				
			}
		}

		else if (isPunctuator((output[charPointer]))){
			numOfPunctuators++;
			lexeme = output[charPointer];
			char *cstr = new char[lexeme.length() + 1];
			strcpy(cstr, lexeme.c_str());
			// do stuff
			Punctuators.InsertInBack(cstr);
			delete[] cstr;
			
			
		}

		else if (isdigit(output[charPointer])){

			//if it is a number, find its end
			lexeme = findEndOfNum(charPointer);

			if (isInteger(lexeme)){ //if the number is an integer, increment the number of integer constants
				numOfIntegerConstants++;
				numOfConstants++;
				char *cstr = new char[lexeme.length() + 1];
				strcpy(cstr, lexeme.c_str());
				// do stuff
				Constants.InsertInBack(cstr);
				delete[] cstr;
				
				

			}
			else if (isFloat(lexeme)) {//if it is a float, increment the number of float constants
				numOfFloatConstants++;
				numOfConstants++;
				char *cstr = new char[lexeme.length() + 1];
				strcpy(cstr, lexeme.c_str());
				// do stuff
				Constants.InsertInBack(cstr);
				delete[] cstr;
				
				
			}
		}

		charPointer++; //move the pointer to the next character.
	}
	cout << "\nNumber of keywords found is: " << numOfKeywords << '\n';
	cout << "\tkeywords found are: ";
	Keywords.PrintList();

	//cout << "\nNumber of boolean constants found is: " << numOfBooleanConstants << "\n";

	cout << "\n\nNumber of identifiers found is: " << numOfIdentifiers << "\n";
	cout << "\tIdentifiers found are: ";
	Identifiers.PrintList();


	cout << "\n\nNumber of operators found is: " << numOfOperators << "\n";
	cout << "\toperators found are: ";
	Operators.PrintList();

	cout << "\n\nNumber of Delimiters found is: " << numOfPunctuators << "\n";
	cout << "\tDelimiters found are: ";
	Punctuators.PrintList();

	cout << "\n\nNumber of Constants found is: " << numOfConstants << "\n";
	cout << "\tConstants found are: ";
	Constants.PrintList();

	cout << "\n\n Press any key to exit.";

	_getch();
	exit(0);


}

bool isOperator(string lexeme){
	for (int x = 0; x<19; x++){
		if (lexeme == tableOfOperators[x]) //check if the lexeme is inside the table of operators
			return true;
	}
	return false;
}

bool isPunctuator(char lexeme){
	for (int x = 0; x<8; x++){
		if (lexeme == tableOfPunctuators[x]) //check if the lexeme is inside the table of punctuators
			return true;
	}
	return false;
}

bool isKeyword(string lexeme){

	//loop through the table of keywords
	for (int x = 0; x<60; x++){
		if (lexeme == tableOfKeywords[x]) //check if the lexeme is a keyword
			return true; //return true if it is a keyword
	}
	return false; //if it is not a keyword
}

	void skipComment(int &cpointer){

		//if the "/" sign is followed by another "/" sign
		if (output[cpointer + 1] == '/'){

			//move the pointer until a newline character is found (this is the end of the comment)
			while (output[cpointer] != '\n'){
				cpointer++;
			}

		}
		//if an asterisk* is found
		if (output[cpointer + 1] == '*'){

			//move to the character next to the asterisk
			cpointer += 2;

			//move the pointer to the next character until the */ is found (end of the comment)
			while ((output[cpointer] != '*') && (output[cpointer + 1] != '/')){
				cpointer++;
			}

		}
	}
	bool isInteger(string lexeme){
		for (int x = 0; x<lexeme.length(); x++){
			if (lexeme[x] == '.')
				return false; //it is not an integer if it contains
		}
		return true;
	}

	bool isFloat(string lexeme){
		for (int x = 0; x<lexeme.length(); x++){
			if (lexeme[x] == '.') //it is a float if it contains a decimal point
				return true;
		}
		return false;
	}
	string findEndOfIdentifier(int &cpointer){

		string tempstring = ""; //this variable will hold the identifier string

		//while alphanumeric characters or the _ character is found do this...	
		while (isalnum(output[cpointer]) || (output[cpointer] == '_')){
			tempstring += output[cpointer]; //append the character to tempstring
			cpointer++; //point to the next character in the file.
		}
		cpointer--;
		return tempstring; //pass tempstring back to where this function was called
	}

	void skipDirective(int &cpointer){
		while (output[cpointer] != '\n') //look for the newline character (end of directive)
			cpointer++; //point to the next character in the file until the newline character is found.
	}

	string findEndOperator(int &cpointer){
		string tempstring;
		tempstring += output[cpointer];


		//look for the ==,!=,<<.>>,||,&& operators
		//(operators which are repeated)
		switch (output[cpointer]){

		case '=':
			if (output[cpointer + 1] == '='){
				tempstring += output[cpointer + 1];
				cpointer++;
			}
			break;


		case '+':
			if (output[cpointer + 1] == '+'){
				tempstring += output[cpointer + 1];
				cpointer++;
			}
			break;

		case '-':
			if (output[cpointer + 1] == '-'){
				tempstring += output[cpointer + 1];
				cpointer++;
			}
			break;

		case '<':
			if (output[cpointer + 1] == '<'){
				tempstring += output[cpointer + 1];
				cpointer++;
			}
			break;

		case '>':
			if (output[cpointer + 1] == '>'){
				tempstring += output[cpointer + 1];
				cpointer++;
			}
			break;

		case '&':
			if (output[cpointer + 1] == '&'){
				tempstring += output[cpointer + 1];
				cpointer++;
			}
			break;

		case '|':
			if (output[cpointer + 1] == '|'){
				tempstring += output[cpointer + 1];
				cpointer++;
			}
			break;

		case '!':
			if (output[cpointer + 1] == '='){
				tempstring += output[cpointer + 1];
				cpointer++;
			}
			break;
		}
		return tempstring;
	}

	string findEndOfNum(int &cpointer){

		string tempstring; //the string where the number will be placed.
		tempstring = output[cpointer];

		//if the number starts with zero.
		if (output[cpointer] == '0'){

			//if zero is followed by a decimal point
			if (output[cpointer + 1] == '.'){

				cpointer++;
				tempstring += output[cpointer];
				cpointer++;

				//move the pointer until a none numeric character is found.
				while (strchr("0123456789", output[cpointer])){
					tempstring += output[cpointer];
					cpointer++;
				}

				//move the pointer one step backwards since an excess of 1 step was added to it in the loop.
				cpointer--;
				return tempstring; //return tempstring to the caller
			}

		}

		else{ //if it is a number other than zero

			cpointer++; //move to the next character

			//if the next character is a decimal point
			if (output[cpointer] == '.'){

				tempstring += output[cpointer]; //append the decimal point to tempstring
				cpointer++; //move to the next character

				//move the pointer to the next character until it is no longer a number.
				while ((strchr("0123456789", output[cpointer]))){

					tempstring += output[cpointer]; //append the next number to tempstring.
					cpointer++; //point to the next character.

				}
			}

			//if the next number is not a decimal point
			else{

				//move the pointer until a non-numeric character is found
				while (strchr("0123456789", output[cpointer])){

					tempstring += output[cpointer]; //append the numeric character to tempstring
					cpointer++; //point to the next character

					//if a decimal point is encountered within the number

					if (strchr(".", output[cpointer])){

						tempstring += output[cpointer]; //append the decimal point to tempstring
						cpointer++; //point to the next character.
					}
				}
			}

			cpointer--;//move the pointer one step backwards since an excess of 1 step was added to it in the loop.

			return tempstring; //return tempstring to the caller
		}

		return tempstring; //return tempstring if only a single number is found.
	}

