#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;

struct qns {
    string qn;
};

int main() {

    ifstream myfile("example.txt");
    ifstream ansfile("answer.txt");
    string line;
    int index = 0;
    vector<string> ans;

    while (getline(myfile, line)) {
        cout<<line<<endl;
        string temp;
        getline(cin, temp);
        ans.push_back(temp);
        try{
            string atemp;
            getline(ansfile, atemp);
            if(atemp==""){
                throw exception();
            }
            transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
            if (atemp == temp) {
                cout<<"Answer is correct"<<endl;
            }else{
                cout<<"Answer is inCorrect"<<endl;
            }
        }
        catch(exception& e){
            cout<<"Answer is not Verified"<<endl;
        }
    }

    ansfile.close();
    myfile.close();    
    return 0;
}