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



void readFile();
void secondPart();


int main() {

    secondPart();
    /*readFile();*/


}


void readFile(){
    std::regex exp  (R"(mul\((\d{1,3}),(\d{1,3})\))");
    std::smatch res;
    std::ifstream t("C:\\Users\\ivanc\\CLionProjects\\newProject\\inputday3.txt");
    std::string str((std::istreambuf_iterator<char>(t)),
                     std::istreambuf_iterator<char>());
    int sum = 0;
    string::const_iterator searchStart( str.cbegin() );
    while ( regex_search( searchStart, str.cend(), res, exp ) )
    {
      sum += stoi(res[1])*stoi(res[2]);
        searchStart = res.suffix().first;
    }
    cout<<sum;
}
void secondPart() {
    std::regex exp  (R"(mul\((\d{1,3}),(\d{1,3})\))");
    std::smatch res;
    std::ifstream t("C:\\Users\\ivanc\\CLionProjects\\newProject\\inputday3.txt");
    std::string str((std::istreambuf_iterator<char>(t)),
                     std::istreambuf_iterator<char>());
    int sum = 0;
    map<int,int> dodont();
    int dont = 0;
    int dos = 0;
    do {
        auto firstDont = str.find("don't()");
        auto firstDo = str.find("do()",firstDont);
        dont = firstDont;
        dos = firstDo;

        if(firstDont != std::string::npos && firstDo != std::string::npos) {
            str.erase(firstDont, firstDo-firstDont);
        }
    }
    while (dont != std::string::npos && dos != std::string::npos);
    cout<<str;
    string::const_iterator searchStart( str.cbegin() );
    while ( regex_search( searchStart, str.cend(), res, exp ) )
    {
        sum += stoi(res[1])*stoi(res[2]);
        searchStart = res.suffix().first;
    }
    cout<<sum;
}


