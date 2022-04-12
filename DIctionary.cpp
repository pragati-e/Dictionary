#include <iostream>
#include <fstream>
#include <string> 
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

fstream ioFile;
string line;
map<string, vector<string>> mMap;

static string howTo = "\t PARAMETER HOW-TO, please enter: \n\t1. A search key -then 2. An optional part of speech -then\n\t3. An optional 'distinct' -then 4. An optional 'reverse'";

bool isPos(string& var) {
    bool yes = false;
    if (var == "noun" || var == "verb" || var == "adjective" || var == "adverb" || var == "preposition" || var == "conjuction" || var == "preposition" || var == "pronoun") {
        yes = true;
    } return yes;
}

void spellCheck(string& key) {
    key.at(0) = toupper(key.at(0));
    for (int i = 0; i < key.length(); i++) {
        if (isdigit(key.at(i))) {
            for (int j = 0; j < key.length(); j++) {
                key.at(j) = toupper(key.at(j));
            } break;
        }
    }
}

void caseOnePar(string& first) {
    cout << "\t|" << endl;
    if (mMap.count(first)) {
      
        map<string, vector<string>>::const_iterator search{ mMap.find(first) };
       
        for (int i = 1; i < search->second.size(); i++) {
            
            string master = search->second[i];
            int x = master.find("-");
            string pos = master.substr(0, x - 1);
            int y = master.find(">") + 3;
            string def = master.substr(y, master.length() - y);
            
            spellCheck(first);
            cout << "\t " << first << "\t[" << pos << "]\t:  " << def << endl;

        }
    }
    else if (first == "!help" || first == "") {
        cout << howTo << endl;
    }
    else {
        cout << "\t <Not Found> To be considered for the next release. Thank you.\n\t|\n\t|" << endl;
        cout << howTo << endl;
    } cout << "\t|" << endl;
}

void caseTwoPar(string& first, string& second) {
    cout << "\t|" << endl;
    set<string> stringset;
    transform(second.begin(), second.end(), second.begin(), ::tolower);

    if (mMap.count(first) && second == "distinct") {

        map<string, vector<string>>::const_iterator search{ mMap.find(first) };
        

        for (int i = 1; i < search->second.size(); i++) {
            stringset.insert(search->second[i]);
        }
        for (set<string>::const_iterator i = stringset.begin(); i != stringset.end(); i++) {
           
            string master = *i;
            int x = master.find("-");
            string pos = master.substr(0, x - 1);
            int y = master.find(">") + 3;
            string def = master.substr(y, master.length() - y);
            spellCheck(first);
            cout << "\t " << first << "\t[" << pos << "]\t:  " << def << endl;

        }
    }
        
        else if (isPos(second) && mMap.count(first)){
            map<string, vector<string>>::const_iterator search{ mMap.find(first) };
            for (int i = 1; i < search->second.size(); i++) {
               
                string master = search->second[i];
                int x = master.find("-");
                string pos = master.substr(0, x - 1);
                int y = master.find(">") + 3;
                string def = master.substr(y, master.length() - y);
                spellCheck(first);
                if (second == pos) {
                    cout << "\t " << first << "\t[" << pos << "]\t:  " << def << endl;
                    
                   
                }
               // else if(second != pos) {


                    //cout << "\t <Not Found> To be considered for the next release. Thank you.\n\t|\n\t|" << endl;
                    //cout << howTo << endl;
                   //// cout << "struggling" << endl;
                   /// break;

                //}
            }
          
        }
        else if (mMap.count(first) && second == "reverse") {
        map<string, vector<string>>::const_iterator search{ mMap.find(first) };
      

        for (int i = search->second.size() - 1; i >= 1; i--) {
           
            string master = search->second[i];
            int x = master.find("-");
            string pos = master.substr(0, x - 1);
            int y = master.find(">") + 3;
            string def = master.substr(y, master.length() - y);
            
            spellCheck(first);
            //map<string, string[]> tempMap;
            //string tempS[] = { pos,def };
            //tempMap.emplace({ first,*(tempS) });
            cout << "\t " << first << "\t[" << pos << "]\t:  " << def << endl;

        }
    }
    cout << "\t|" << endl;
}

void caseThreePar(string& first, string& second, string& third) {
    cout << "\t|" << endl;
    set<string> stringset;
    transform(second.begin(), second.end(), second.begin(), ::tolower);
    transform(third.begin(), third.end(), third.begin(), ::tolower);

    if (mMap.count(first) && isPos(second) && third == "distinct") {
        map<string, vector<string>>::const_iterator search{ mMap.find(first) };
        for (int i = 1; i < search->second.size(); i++) {
            stringset.insert(search->second[i]);
        }

        for (set<string>::const_iterator i = stringset.begin(); i != stringset.end(); i++) {
            

            string master = *i;
            int x = master.find("-");
            string pos = master.substr(0, x - 1);
            int y = master.find(">") + 3;
            string def = master.substr(y, master.length() - y);
            spellCheck(first);
            if (second == pos) {
                cout << "\t " << first << "\t[" << pos << "]\t:  " << def << endl;
              
            }

        }
       
    }
    else if (mMap.count(first) && isPos(second) && third == "reverse") {
        map<string, vector<string>>::const_iterator search{ mMap.find(first) };
        for (int i = search->second.size()-1; i >= 1 ; i--) {

            string master = search->second[i];
            int x = master.find("-");
            string pos = master.substr(0, x - 1);
            int y = master.find(">") + 3;
            string def = master.substr(y, master.length() - y);
            spellCheck(first);
            if (second == pos) {
                cout << "\t " << first << "\t[" << pos << "]\t:  " << def << endl;

            }
        }
    }

    else if ((second == "distinct" && third == "reverse") || (second == "reverse" && third == "distinct")) {
        map<string, vector<string>>::const_iterator search{ mMap.find(first) };
        vector<string> tempVec;

        for (int i = search->second.size() - 1; i >= 1 ; i--) {

            stringset.insert(search->second[i]);
         
        }
       
        for (set<string>::const_iterator i = stringset.begin(); i != stringset.end(); i++) {
            //cout << *i << "we are here" << endl;
            tempVec.push_back(*i);
           // string master = *i;
            //int x = master.find("-");
           // string pos = master.substr(0, x - 1);
            //int y = master.find(">") + 3;
            //string def = master.substr(y, master.length() - y);
            ///spellCheck(first);
            //cout << "\t " << first << "\t[" << pos << "]\t:  " << def << endl;

        }
        for (int i = tempVec.size() - 1; i >= 0; i--) {
            string master = tempVec[i];
            int x = master.find("-");
            string pos = master.substr(0, x - 1);
            int y = master.find(">") + 3;
            string def = master.substr(y, master.length() - y);
            spellCheck(first);
            cout << "\t " << first << "\t[" << pos << "]\t:  " << def << endl;
        }
    }
    cout << "\t|" << endl;
}


void loadData(string& line, vector<string>& vec, map<string, vector<string>>& mMap) {
    int i = 0;
    int j = line.find("|");
    string key;
   

    while (j != string::npos) {
        
        string str = line.substr(i, j - i);
        vec.push_back(str);
       
        i = ++j;
        
        j = line.find("|", j);
        

        if (j == string::npos) {
            str = line.substr(i, line.length());
            vec.push_back(str);
            
        }
        sort(vec.begin() + 1, vec.end());


    }mMap.insert({ vec[0], vec });
}

int main()
{
    string wrongPath{ "C:\\Users\MickeyMouse\AbsolutePath\DB\Data.CS.SFSU.txt" };
    string correctPath{ "./Data.CS.SFSU.txt" };
    cout << "! Opening data file... " << wrongPath << endl; 
    cout << "<!>ERROR<!> ===> File could not be opened." << endl;
    cout << "<!>ERROR<!> ===> Provided file path: " << wrongPath << endl;
    cout << "<!>Enter the CORRECT data file path: " << correctPath << endl;
    ioFile.open("Data.CS.SFSU.txt", ios::in);
    cout << "! Loading data..." << endl;
    while (getline(ioFile, line)) {
        vector<string> vec;
        
        loadData(line, vec, mMap);
    }
    cout << "! Loading completed..." << endl;
    cout << "! Closing data file... ./Data.CS.SFSU.txt" << endl;
    ioFile.close();
    cout << "\n===== DICTIONARY 340 C++ =====" << endl;
    cout << "----- Keywords: 19 \n----- Definitions: 61" << endl;
    cout << endl;
    string input;
    int count = 1;

    while (true) {

        printf("Search[%d]: ",count);
        getline(cin, input);
        
        if (input == "!Q" || input == "!q") {
            cout << endl << "----- THANK YOU -----" << endl;
            break;
        }
        vector<string> splitted;
        if (input == "") {
            cout << "\t|" << endl;
            cout << howTo << endl;
            cout << "\t|" << endl;
        }
        else {
            for (int i = 0; i < input.length(); i++) {
                input[i] = tolower(input[i]);
            }
        }
        istringstream ss(input);
        string x;
        count++;

        while (ss >> x) {
            splitted.push_back(x);
        }

        switch (splitted.size()) {
        case 1:
        {
            caseOnePar(splitted[0]);
            break;
        }
        case 2:
        {
            transform(splitted[1].begin(), splitted[1].end(), splitted[1].begin(), ::tolower);
            if (!(isPos(splitted[1]) || splitted[1] == "distinct" || splitted[1] == "reverse")) {
                cout << "\t|" << endl;
                cout << "\t <The entered 2nd parameter " + splitted[1] + " is NOT a part of speech.>" << endl;
                cout << "\t <The entered 2nd parameter " + splitted[1] + " is NOT 'distinct'.>" << endl;
                cout << "\t <The entered 2nd parameter " + splitted[1] + " is NOT 'reverse'.>" << endl;
                cout << "\t <The entered 2nd parameter " + splitted[1] + " was disregarded.>" << endl;
                cout << "\t <The 2nd parameter should be a part of speech or 'distinct' or 'reverse'.>" << endl;
                cout << "\t|" << endl;
                caseOnePar(splitted[0]);
                break;
            }
            caseTwoPar(splitted[0], splitted[1]);
            break;
       
        }

        case 3:
        {
            transform(splitted[1].begin(), splitted[1].end(), splitted[1].begin(), ::tolower);
            transform(splitted[2].begin(), splitted[2].end(), splitted[2].begin(), ::tolower);
            if (!(isPos(splitted[1]) || splitted[1] == "distinct" || splitted[1] == "reverse")) {
                cout << "\t|" << endl;
                cout << "\t <The entered 2nd parameter " + splitted[1] + " is NOT a part of speech.>" << endl;
                cout << "\t <The entered 2nd parameter " + splitted[1] + " is NOT 'distinct'.>" << endl;
                cout << "\t <The entered 2nd parameter " + splitted[1] + " is NOT 'reverse'.>" << endl;
                cout << "\t <The entered 2nd parameter " + splitted[1] + " was disregarded.>" << endl;
                cout << "\t <The 2nd parameter should be a part of speech or 'distinct' or 'reverse'.>" << endl;
                cout << "\t|" << endl;
                caseTwoPar(splitted[0], splitted[2]);
                break;
            }
            if (!(splitted[2] == "reverse" || splitted[2] == "distinct")){
                cout << "\t|" << endl;
                cout << "\t <The entered 3rd parameter " + splitted[2] + " is NOT 'distinct'.>" << endl;
                cout << "\t <The entered 3rd parameter " + splitted[2] + " is NOT 'reverse'.>" << endl;
                cout << "\t <The entered 3rd parameter " + splitted[2] + " was disregarded.>" << endl;
                cout << "\t <The entered 3rd parameter should be 'distinct' or 'reverse'.>" << endl;
                cout << "\t|" << endl;
                caseTwoPar(splitted[0], splitted[1]);
                break;
            }
            caseThreePar(splitted[0], splitted[1], splitted[2]);
            break;
        }
        
        case 4:
        {
            transform(splitted[1].begin(), splitted[1].end(), splitted[1].begin(), ::tolower);
            transform(splitted[2].begin(), splitted[2].end(), splitted[2].begin(), ::tolower);
            transform(splitted[3].begin(), splitted[3].end(), splitted[3].begin(), ::tolower);

            //cout << "oda e 1" << endl;

            if ((mMap.count(splitted[0])) && (isPos(splitted[1])) && (splitted[2] == "distinct") && (splitted[3] == "reverse")) {
                cout << "\t|" << endl;
                set<string> stringset;
                map<string, vector<string>>::const_iterator search{ mMap.find(splitted[0]) };
                vector<string> tempVec;

                for (int i = search->second.size() - 1; i >= 1; i--) {

                    stringset.insert(search->second[i]);

                }

                for (set<string>::const_iterator i = stringset.begin(); i != stringset.end(); i++) {
                    //cout << *i << "we are here" << endl;
                    tempVec.push_back(*i);
                   

                }
                for (int i = tempVec.size() - 1; i >= 0; i--) {
                    string master = tempVec[i];
                    int x = master.find("-");
                    string pos = master.substr(0, x - 1);
                    int y = master.find(">") + 3;
                    string def = master.substr(y, master.length() - y);
                    spellCheck(splitted[0]);
                    if (splitted[1] == pos) {

                        cout << "\t " << splitted[0] << "\t[" << pos << "]\t:  " << def << endl;
                    }
                }
                cout << "\t|" << endl;
                break;
            }

            
            if ((splitted[1] != "distinct" || splitted[1] != "reverse" || !isPos(splitted[1])) && (splitted[2] == "distinct" || splitted[2] == "reverse") && (splitted[3] == "reverse")) {
                cout << "\t|" << endl;
                cout << "\t <The entered 2nd parameter " + splitted[1] + " is NOT a part of speech.>" << endl;
                cout << "\t <The entered 2nd parameter " + splitted[1] + " is NOT 'distinct'.>" << endl;
                cout << "\t <The entered 2nd parameter " + splitted[1] + " is NOT 'reverse'.>" << endl;
                cout << "\t <The entered 2nd parameter " + splitted[1] + " was disregarded.>" << endl;
                cout << "\t <The 2nd parameter should be a part of speech or 'distinct' or 'reverse'.>" << endl;
               // cout << "oda e 2" << endl;
                cout << "\t|" << endl;
                caseTwoPar(splitted[0], splitted[2]);
                
            }

            if ((splitted[2] != "distinct" || splitted[2] != "reverse") && (splitted[3] == "reverse")) {
                cout << "\t|" << endl;
                cout << "\t <The entered 3rd parameter " + splitted[2] + " is NOT 'distinct'.>" << endl;
                cout << "\t <The entered 3rd parameter " + splitted[2] + " is NOT 'reverse'.>" << endl;
                cout << "\t <The entered 3rd parameter " + splitted[2] + " was disregarded.>" << endl;
                cout << "\t <The entered 3rd parameter should be 'distinct' or 'reverse'.>" << endl;
              //  cout << "oda e 3" << endl;
                cout << "\t|" << endl;
                caseTwoPar(splitted[0], splitted[1]);
            }

            if ((splitted[3] != "reverse") && (splitted[2] == "distinct" || splitted[2] == "reverse")) {
                cout << "\t|" << endl;
                cout << "\t <The entered 4th parameter " + splitted[3] + " is NOT 'reverse'.>" << endl;
                cout << "\t <The entered 4th parameter " + splitted[3] + " was disregarded.>" << endl;
                cout << "\t <The entered 4th parameter should be 'reverse'.>" << endl;
                cout << "\t|" << endl;
                caseThreePar(splitted[0], splitted[1], splitted[2]);
                break;
            }

            if ((splitted[2] != "distinct" || splitted[2] != "reverse") && (splitted[3] != "reverse") && (splitted[1] == "distinct" || splitted[1] == "reverse" || isPos(splitted[1]))) {
                cout << "\t|" << endl;
                cout << "\t <The entered 3rd parameter " + splitted[2] + " is NOT 'distinct'.>" << endl;
                cout << "\t <The entered 3rd parameter " + splitted[2] + " is NOT 'reverse'.>" << endl;
                cout << "\t <The entered 3rd parameter " + splitted[2] + " was disregarded.>" << endl;
                cout << "\t <The entered 3rd parameter should be 'distinct' or 'reverse'.>" << endl;
                cout << "\t|" << endl;
                cout << "\t <The entered 4th parameter " + splitted[3] + " is NOT 'reverse'.>" << endl;
                cout << "\t <The entered 4th parameter " + splitted[3] + " was disregarded.>" << endl;
                cout << "\t <The entered 4th parameter should be 'reverse'.>" << endl;
                cout << "\t|" << endl;
                caseTwoPar(splitted[0], splitted[1]);
                break;

            }
            if ((mMap.count(splitted[0])) && (!isPos(splitted[1])) && (splitted[2] != "distinct") && (splitted[3] != "reverse")) {
                cout << "\t|" << endl;
                cout << "\t <The entered 2nd parameter " + splitted[1] + " is NOT a part of speech.>" << endl;
                cout << "\t <The entered 2nd parameter " + splitted[1] + " is NOT 'distinct'.>" << endl;
                cout << "\t <The entered 2nd parameter " + splitted[1] + " is NOT 'reverse'.>" << endl;
                cout << "\t <The entered 2nd parameter " + splitted[1] + " was disregarded.>" << endl;
                cout << "\t <The 2nd parameter should be a part of speech or 'distinct' or 'reverse'.>" << endl;
                cout << "\t|" << endl;
                cout << "\t <The entered 3rd parameter " + splitted[2] + " is NOT 'distinct'.>" << endl;
                cout << "\t <The entered 3rd parameter " + splitted[2] + " is NOT 'reverse'.>" << endl;
                cout << "\t <The entered 3rd parameter " + splitted[2] + " was disregarded.>" << endl;
                cout << "\t <The entered 3rd parameter should be 'distinct' or 'reverse'.>" << endl;
                cout << "\t|" << endl;
                cout << "\t <The entered 4th parameter " + splitted[3] + " is NOT 'reverse'.>" << endl;
                cout << "\t <The entered 4th parameter " + splitted[3] + " was disregarded.>" << endl;
                cout << "\t <The entered 4th parameter should be 'reverse'.>" << endl;
                cout << "\t|" << endl;

                caseOnePar(splitted[0]);
                break;
            }

           
        }

        case 5: 
            cout << "\t|" << endl;
            cout << howTo << endl;
            cout << "\t|" << endl;
        }   
    }
    
}
