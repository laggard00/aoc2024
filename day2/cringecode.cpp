#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <ranges>
#include <set>
#include <sstream>
#include <unordered_set>
#include <vector>

using namespace std;



void readFile();
bool IsSafe( vector<int> &vect);
bool secondPart(vector<int> &vect);
bool comp(int a, int b) {
    return a >= b;
}
int main() {

    readFile();


}


void readFile(){
    std::ifstream file("C:\\Users\\ivanc\\CLionProjects\\newProject\\inputday2.txt");
    std::string str;
    int counter = 0;

    while (std::getline(file, str))
    {
        stringstream stream(str);
        std::vector<int> values;
        int n;
        while(stream >> n){
            values.push_back(n);
        }
        if(secondPart(values)){
            counter++;
        }
    }
    cout<<counter;

}
bool IsSafe( vector<int> &vect)
{
    if(vect.front() < vect.back()) {
        for(int i = 1; i < vect.size(); i++) {
            if(vect[i] <= vect[i-1]) {
                return false;
            }
            if(vect[i]- vect[i-1] >=4) {
                return false;
            }
        }
    } else if (vect.front() > vect.back()) {
        for(int i = vect.size()-1; i >=1; i--) {
            if(vect[i] >= vect[i-1]) {
                return false;
            }
            if(vect[i-1] - vect[i] >=4) {
                return false;
            }
        }
    }
    else if (vect.front() == vect.back()){
        return false;
    }
    return true;
}
bool secondPart( vector<int> &vect) {
    bool b = true ;
    auto originalVect = vect;
    if(vect.front() < vect.back()) {
        for(int i = 1; i < vect.size(); i++) {
            if(vect[i] <= vect[i-1]) {
                auto d = vect;
                auto g = vect;
                d.erase(d.begin()+i);
                g.erase(g.begin()+i-1);
                b= IsSafe(d) || IsSafe(g);
                break;
            }
            if(vect[i]- vect[i-1] >=4) {
                auto d = vect;
                auto g = vect;
                d.erase(d.begin()+i);
                g.erase(g.begin()+i-1);
                b= IsSafe(d) || IsSafe(g);
                break;
            }
        }
    } else if (vect.front() > vect.back()) {
        for(int i = vect.size()-1; i >=1; i--) {
            if(vect[i] >= vect[i-1]) {
                auto d = vect;
                auto g = vect;
                d.erase(d.begin()+i);
                g.erase(g.begin()+i-1);
                b= IsSafe(d) || IsSafe(g);
                break;
            }
            if(vect[i-1] - vect[i] >=4) {
                auto d = vect;
                auto g = vect;
                d.erase(d.begin()+i);
                g.erase(g.begin()+i-1);
                b= IsSafe(d) || IsSafe(g);
                break;
            }
        }
    }
    else if (vect.front() == vect.back()){
        auto d = vect;
        auto g = vect;
        d.erase(d.begin());
        g.erase(g.end());
        b= IsSafe(d) || IsSafe(g);

    }
    return b;

}

