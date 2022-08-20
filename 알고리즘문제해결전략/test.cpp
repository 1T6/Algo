#include <iostream>
#include <vector>
#include <string>


using namespace std;

int main()
{
     /*
     int m;
     cin>>m;
     vector<string> words;
     for(int i=0; i<m; i++){
          string tmp;
          cin>>tmp;
          words.push_back(tmp);
     }

     for(int i=0; i<m; i++){
          cout<<words[i]<<endl;
     }
     */

    string tmp;
    getline(cin, tmp);
    cout<<tmp<<endl;


     return 0;
}