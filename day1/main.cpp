#include <algorithm>
#include <fstream>
#include <iostream>
#include <ranges>
#include <set>

using namespace std;



void readFile( multiset<int> & fs, multiset<int> &ss);
void writeOutSum(multiset<int> & fs, multiset<int> &ss);
void writeOutSimilarityScore(multiset<int> & fs, multiset<int> &ss);
bool comp(int a, int b) {
    return a >= b;
}
int main() {
    multiset<int> firstSet;
    multiset<int> secondSet;
    readFile(firstSet, secondSet);
    writeOutSum(firstSet, secondSet);
    writeOutSimilarityScore(firstSet, secondSet);

}


void readFile( multiset<int> & fs, multiset<int> &ss){
    std::ifstream file("C:\\Users\\ivanc\\CLionProjects\\newProject\\inputday1.txt");
    std::string str;
    while (std::getline(file, str))
    {
        string delimiter = "   ";
        fs.insert(stoi(str.substr(0, str.find(delimiter))));
        str.erase(0, str.find(delimiter) + delimiter.length());
        ss.insert(stoi(str.substr(str.find(delimiter) + 1, str.length())));
    }
}


void writeOutSum(multiset<int> & fs, multiset<int> &ss) {
    int sum = 0;
    auto it1 = fs.begin();
    auto it2 = ss.begin();
    while (it1 != fs.end() && it2 != ss.end()) {
        int i1 = *it1;
        int i2 = *it2;
        sum += abs(i1-i2);
        it1++;
        it2++;
    }
    cout<<sum<<endl;
}
void writeOutSimilarityScore(multiset<int> & fs, multiset<int> &ss) {
    int simScore = 0;
    for ( auto it = fs.begin(); it != fs.end(); it++ ) {
        int b =  ss.count(*it);
        simScore += abs(*it*b);
    }
    cout<<simScore<<endl;
}