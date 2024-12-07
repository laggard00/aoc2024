#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <ranges>
#include <set>
#include <sstream>
#include <unordered_set>
#include <vector>
#include <regex>


using namespace std;



void firstPart();
void secondPart();


int main() {

    firstPart();
    secondPart();


}


void firstPart() {
    std::ifstream t("C:\\Users\\ivanc\\CLionProjects\\newProject\\inputday4.txt");
    std::string str;
    char charArray[140][140];
    int count=0;
    int xmasCounter=0;
    while(std::getline(t,str)){
        for(int i=0;i<str.size();i++) {
            charArray[count][i]=str[i];
        }
        count++;
    }
    for(int i=0;i<count;i++) {
        string s ;
        string sMirror;
        for(int j=0;j<count;j++) {
            s += charArray[i][j];
            sMirror += charArray[j][i];
        }
        int first =0;
        int second=0;
        do {
           auto b= s.size();
           first = s.find("XMAS",first);
            if(first != string::npos) {
                xmasCounter++;
                first +=1;
            }
            second = s.find("SAMX",second);
            if(second != string::npos) {
                xmasCounter++;
                second +=1;
            }

        }
        while(second != string::npos || first != string::npos);
        first =0;
        second=0;
        do {
            auto b= s.size();
            first = sMirror.find("XMAS",first);
            if(first != string::npos) {
                xmasCounter++;
                first +=1;
            }
            second = sMirror.find("SAMX",second);
            if(second != string::npos) {
                xmasCounter++;
                second +=1;
            }

        }
        while(second != string::npos || first != string::npos);
    }
    for (int d = 0; d < 140 + 140 - 1; ++d) {
        std::string s = "";
        for (int i = 0; i < 140; ++i) {
            int j = d - i; // Calculate column index
            if (j >= 0 && j < 140) {
                s += charArray[i][j];
            }
        }
        int first =0;
        int second=0;
        do {
            auto b= s.size();
            first = s.find("XMAS",first);
            if(first != string::npos) {
                xmasCounter++;
                first +=3;
            }
            second = s.find("SAMX",second);
            if(second != string::npos) {
                xmasCounter++;
                second +=3;
            }

        }
        while(second != string::npos || first != string::npos);
    }
    for (int d = 0; d < 140 + 140 - 1; ++d) {
        std::string s = "";
        for (int i = 0; i < 140; ++i) {
            int j = i + d - (140 - 1);
            if (j >= 0 && j < 140) {
                s += charArray[i][j];
            }
        }
        int first =0;
        int second=0;
        do {
            auto b= s.size();
            first = s.find("XMAS",first);
            if(first != string::npos) {
                xmasCounter++;
                first +=3;
            }
            second = s.find("SAMX",second);
            if(second != string::npos) {
                xmasCounter++;
                second +=3;
            }

        }
        while(second != string::npos || first != string::npos);
    }
    cout<<xmasCounter<<endl;
}
void secondPart() {
    std::ifstream t("C:\\Users\\ivanc\\CLionProjects\\newProject\\inputday4.txt");
    std::string str;
    int xmasCounter=0;
    char charArray[140][140];
    int count =0;
    while(std::getline(t,str)){
        for(int i=0;i<str.size();i++) {
            charArray[count][i]=str[i];
        }
        count++;
    }
    //M.M S.M S.S M.S
    //.A. .A. .A. .A.
    //S.S S.M M.M M.S
    for (int i = 1; i < 140; ++i) {
        for(int j = 1; j < 140; ++j) {
            if(charArray[i][j] == 'A') {
                if(charArray[i+1][j+1] == 'S' && charArray[i-1][j-1] == 'M' && charArray[i-1][j+1] == 'M' && charArray[i+1][j-1] == 'S')
                { xmasCounter++;}
                if(charArray[i+1][j+1] == 'M' && charArray[i-1][j-1] == 'S' && charArray[i-1][j+1] == 'M' && charArray[i+1][j-1] == 'S')
                { xmasCounter++;}
                if(charArray[i+1][j+1] == 'M' && charArray[i-1][j-1] == 'S' && charArray[i-1][j+1] == 'S' && charArray[i+1][j-1] == 'M')
                { xmasCounter++;}
                if(charArray[i+1][j+1] == 'S' && charArray[i-1][j-1] == 'M' && charArray[i-1][j+1] == 'S' && charArray[i+1][j-1] == 'M')
                { xmasCounter++;}
            }
        }
    }
    cout<<xmasCounter;
}


