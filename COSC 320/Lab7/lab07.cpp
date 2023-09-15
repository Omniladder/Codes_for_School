#include <iostream>
#include "d_hash.h"
#include "d_hashf.h"
//#include "d_hiter.h"
#include <fstream>
#include <string>


using namespace std;

ifstream& getWord(ifstream& fin, string& w); //DUSTIN O'Brien //


int main()
{
    ifstream dictionary; 
    dictionary.open("dict.dat");
    string doc = "";
    cout<<"Run: "<<endl<<endl;
    cout<<"Enter the document name:"<<endl;
    cin>>doc;
    ifstream text;
    text.open(doc);

    
    myhash <string, hFstring> hashBrown(1373);

    string word;

    while(!dictionary.eof())
    {
        getWord(dictionary,word);
        hashBrown.insert(word);
    }

    cout<<"misspelled words:"<<endl;
    while(!text.eof())
    {
        getWord(text,word);
        if(hashBrown.find(word)==hashBrown.end())
        {
            cout<<word<<endl;
        }
    }

}


//extract a word from fin
ifstream& getWord(ifstream& fin, string& w)
{
	char c;

	w = "";	// clear the string of characters

	while (fin.get(c) && !isalpha(c))
		;	// do nothing. just ignore c

	// return on end-of-file
	if (fin.eof())
		return fin;

	// record first letter of the word
	w += tolower(c);

	// collect letters and digits
	while (fin.get(c) && (isalpha(c) || isdigit(c)))
		w += tolower(c);

	return fin;
}
