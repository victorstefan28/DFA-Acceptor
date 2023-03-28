#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <fstream>
#include <algorithm>
#include <cstring>

using namespace std;



int main()
{
    string init;
    vector<string> drum;
    vector<array<string, 3> > tranzitii;
    vector<string> finale;
    ifstream in("../input.in");

    int n = 0; /// nr tranzitii
    in>>n;
    in>>init;
    for(int i = 0; i<n; i++)
    {
        string x,y,z;
        in>>x>>y>>z;
        std::array<string,3> t = {x,y,z};
        tranzitii.push_back(t);

    }
    string x;
    while(in>>x)
        finale.push_back(x);

    std::string cuvant;
    getline(std::cin, cuvant);
    do
    {

        reverse(cuvant.begin(), cuvant.end());
        std::string curent = init;
        drum.push_back(curent);
        while(cuvant.size() > 0)
        {
            for(auto i: tranzitii)
                if(!i[1].compare(string(&cuvant.back())) && !i[0].compare(curent))
                {
                    drum.push_back(i[2]);
                    curent = i[2];
                    break;
                }
            cuvant.pop_back();
        }

        if(std::find(finale.begin(), finale.end(), curent) != finale.end()) {
            cout << "Acceptat\n";
            cout<<"Drum:";
            for(auto x:drum)
                cout<<x<<' ';
            cout<<'\n';
        }
        else
            cout<<"Refuzat\n";
        getline(std::cin, cuvant);
        drum.clear();
    }while(strcmp(cuvant.c_str(), "=") != 0);
    return 0;
}