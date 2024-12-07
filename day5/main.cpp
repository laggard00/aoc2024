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
    /*secondPart();*/


}


void firstPart() {
    std::ifstream t("C:\\Users\\ivanc\\CLionProjects\\newProject\\inputday5.txt");
    std::string str;

    std::map<std::string, std::vector<std::string>> myMap;
    vector<string> manuals;
    bool found= false;
    int count=0;
    int xmasCounter=0;
    while(std::getline(t,str)){

        if(str.find('|')==string::npos) {
            found = true;

        }
        if(!found) {
            myMap[str.substr(0,2)].push_back(str.substr(3,4));
        }
        else {
            if(str.find(',')!=string::npos) {
                manuals.push_back(str);
            }
        }
    }
    vector<string> wronglyOrdered;
    for(int i = 0; i<manuals.size(); i++) {
        bool hasCommonElement = false;
        string number;
        vector<string> numbers;

        auto b = manuals.at(i);
        auto ss = std::stringstream(b);
        while(std::getline(ss,number,',')){
            numbers.push_back(number);
        }
        for (auto it = numbers.end() - 1; it >= numbers.begin(); --it) {
            std::vector<std::string> newVec(numbers.begin(), it);

            if (myMap.find(*it) != myMap.end()) {
                std::vector<std::string> contains = myMap[*it];


                for (const auto& elem : newVec) {
                    if (std::find(contains.begin(), contains.end(), elem) != contains.end()) {
                        hasCommonElement = true;
                        break;

                    }
                }
            }
        }
        if(!hasCommonElement) {

            xmasCounter+=stoi(numbers[numbers.size() / 2]);
        }
        else {
            wronglyOrdered.push_back(manuals.at(i));
        }
    }
    cout<<xmasCounter<<endl;



    int xmasCounter2=0;
    for(int j = 0; j<wronglyOrdered.size(); j++) {
        bool hasCommonElement = false;
        string number;
        vector<string> numbers;

        auto b = wronglyOrdered.at(j);
        auto ss = std::stringstream(b);
        while(std::getline(ss,number,',')){
            numbers.push_back(number);
        }

        string tempArr[numbers.size()];
        for (const auto& currentNumber : numbers) {
            if (myMap.find(currentNumber) != myMap.end()) {
                const std::vector<std::string>& contains = myMap[currentNumber];
                int matchCount = 0;

                for (const auto& number : numbers) {
                    if (std::find(contains.begin(), contains.end(), number) != contains.end()) {
                        matchCount++;
                    }
                }
                tempArr[numbers.size()-1-matchCount] = currentNumber;
            }
        }
        xmasCounter2+=stoi(tempArr[numbers.size() / 2]);
    }
    cout<<xmasCounter2<<endl;

}




