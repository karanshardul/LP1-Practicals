#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <unistd.h>
using namespace std;

class Node{
    public:
    int id;
    Node(){
        id = 0;
    }
    Node(int i){
        id =i;
    }
};

class Ring{
    public:
    int num;
    vector<Node> ans;

    Ring(){
        cout << "Enter the number of Nodes: ";
        cin >> num;

        int i=0;
        while(i<num){
            Node obj;
            cout << "Enter the id of Node "<< i+1 << ": ";
            cin >> obj.id;
            ans.push_back(obj);
            i++;
        }


    }

    void detect(){
        sort(ans.begin(),ans.end(),[] (const Node& ls, const Node& rs){
            return ls.id < rs.id;
        });
        // cout << ans[num-1].id;
        sleep(2);
            cout << "The Coordinator is: " << ans.back().id ;
            sleep(1);
            cout << "The Coordinator " << ans.back().id << " failed!\n";
            ans.pop_back();
            num--;
    }

    void elect(){
            cout << "LET " << ans.back().id << " is New Coordinator";
            cout << "\n\n";
            sleep(2);
            int i=0;
            int  index = num - 1;
            while(i<num){
                cout << "Message passed from " << ans[index].id << " to " << ans[(index+1) % num].id << endl;
                sleep(2);
                i++;
                index = (index + 1) % num;
            } 
            cout << "New coordinator is: " << ans.back().id << endl;
    }
};

class Bully{
    public:
    int num;
    vector<Node> ans;

    Bully(){
        cout << "Enter the number of Nodes: ";
        cin >> num;

        int i=0;
        while(i<num){
            Node obj;
            cout << "Enter the id of Node "<< i+1 << ": ";
            cin >> obj.id;
            ans.push_back(obj);
            i++;
        }


    }

    void detect(){
        sort(ans.begin(),ans.end(),[] (const Node& ls, const Node& rs){
            return ls.id < rs.id;
        });
        // cout << ans[num-1].id;
        sleep(2);
            cout << "The Coordinator is: " << ans.back().id ;
            sleep(1);
            cout << "The Coordinator " << ans.back().id << " failed!\n";
            ans.pop_back();
            num--;
    }

    void elect(){
        int newco = rand()%num;
        sleep(1);
        cout << "Detected by: " << newco << endl;
        sleep(1);
        cout << "ELECTION ALGORITHM"<< endl;
        sleep(1);

        while(newco != num+1){
            int j = newco;
            for(int i=newco; i<=num; i++){
                if(j>num+1) break;
                sleep(1);
                cout << "Message send from "<< newco << " to " << ++j << endl;

            }
            
        }
    }
};
int main()
{
    Ring rng;
    rng.detect();
    rng.elect();
    return 0;
}
