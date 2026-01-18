#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    vector<string> hold;
    vector<string>::iterator delta;
    string command,student,temp,held;
    multimap<string,string> School;
    typedef multimap<string,string>::iterator test;
    pair<test,test> result;
    while(command != "q")
    {
        cout << "What do you want to do: ";
        cin >> command;
        if (command == "ns")
        {
            cin >> held;
             if (find(hold.begin(),hold.end(),held) != hold.end())
            {
                cout << "School is already in the database";
            }
            else if(School.find(held)!=School.end())
            {
                cout << "School is already in the database";
            }
            else
            {
                hold.push_back(held);
            }
        }
        if (command == "nc")
        {
            cin >> temp >> student;
            if (find(hold.begin(),hold.end(),temp) != hold.end())
            {
                if(School.find(student)==School.end())
                {
                    School.insert({temp,student});
                    delta = find(hold.begin(),hold.end(),temp);
                    hold.erase(delta);
                }
                else
                {
                    cout << "There is already a student with that name in that school";
                }
            }
            else if(School.find(temp)!=School.end())
            {
                School.insert({temp,student});
            }
            else 
            {
                cout << "That school does not exist yet";
            }
        }
        if (command == "ps")
        {
            for (int i=0; i<hold.size();i++)
            {
                cout<<hold[i]<<endl;
            }
            for(auto& p: School)
            {
                cout<<p.first<<endl;
            }
        }
        if (command == "pc")
        {
            cin >> temp;
            result = School.equal_range(temp);
            for (auto p = result.first;p!=result.second;p++)
            {
                cout <<p->second<<endl;
            }
        }
        cout <<endl;
    }
    return 0;
}