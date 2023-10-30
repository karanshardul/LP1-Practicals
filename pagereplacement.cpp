// pageReplace.cpp
#include <bits/stdc++.h>
using namespace std;
void print_queue(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front()<<" < ";
        q.pop();
    }
    cout << endl;
}
bool checkValue(queue<int> q, int temp)
{
bool t = 0;
    while (!q.empty())
    {
        if(q.front() == temp){
        t = 1;
        break;
        }
        else{
        q.pop();
        }
    }
    return t;
}
void FIFO(){
// system("clear");
int index = -1;
int n, frame, temp,pagef=0,hits=0;;
cout<<"Enter the number of reference & frame slots\n";
cin>>n>>frame;
queue <int> q;
cout<<"Enter the page reference in sequence-\n";
for(int i=0;i<n;i++){
cin>>temp;
if(checkValue(q, temp)){
hits++;

}
else{
pagef++;
cout << index << endl;
if(index>=frame-1){
q.pop();
q.push(temp);
}
else{
q.push(temp);
index++;
}
}
print_queue(q);
// cout<<"Index: "<<index<<endl;
}
cout<<"\n\tPage Faults :. "<<pagef<<
 "\n\tHits        :. "<<hits<<"\n";


}
bool search(int key, vector<int>& fr)
{
    for (int i = 0; i < fr.size(); i++)
        if (fr[i] == key)
            return true;
    return false;
}
int predict(int pg[], vector<int>& fr, int pn, int index)
{
    int res = -1, farthest = index;
    for (int i = 0; i < fr.size(); i++) {
        int j;
        for (j = index; j < pn; j++) {
            if (fr[i] == pg[j]) {
                if (j > farthest) {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }
        if (j == pn)
            return i;
    }
    return (res == -1) ? 0 : res;
}

void Optimal()
{
// system("clear");
    vector<int> F;
    int hit = 0;
    int n,frame;
    cout<<"Enter the number of reference & frame slots\n";
    cin>>n>>frame;
    int page[n];
    cout<<"Enter the page reference in sequence-\n";
    for(int i=0;i<n;i++){
    cin>>page[i];
    }

    for (int i=0;i<n;i++) {

        if (search(page[i], F)) {
            hit++;
            continue;
        }
        if (F.size() < frame)
            F.push_back(page[i]);
        else {
            int j = predict(page, F, n, i + 1);
            F[j] = page[i];
        }
    }
    cout<<"\n\tPage Faults :. "<<n-hit<<
 "\n\tHits        :. "<<hit<<"\n";
}
void Least()
{
// system("clear");
int n, frame,pagef=0;
cout<<"Enter the number of reference & frame slots\n";
cin>>n>>frame;
int pages[n];
    cout<<"Enter the page reference in sequence-\n";
for(int i=0;i<n;i++){
cin>>pages[i];
}
    vector<int> s;
    unordered_map<int, int> indexes;
    for (int i=0; i<n; i++)
    {
        if (s.size() < frame)
        {
            if (indexes[pages[i]]==0)
            {
                s.push_back(pages[i]);
                pagef++;
            }
            indexes[pages[i]]++;
        }

        else
        {
            if (indexes[pages[i]]==0)
            {
                int lru = INT_MAX, val;
                int k=0;
                for (int i=0;i<s.size();i++)
                {
                    if (indexes[s[i]] < lru)
                    {
                        lru = indexes[s[i]];
                        val = s[i];
                        k=i;
                    }
                }
                cout<<k<<"    ";
                s.erase(s.begin()+k);
                s.push_back(pages[i]);
                indexes[val]=0;
                pagef++;
            }
            indexes[pages[i]]++;
        }
       
    }
    cout<<"\n\tPage Faults :. "<<pagef<<
 "\n\tHits        :. "<<n-pagef<<"\n";
}
int main(){
// system("clear");
cout<<"Choose the Page Replacement algorithm.\n";
cout<<"\ta. FIFO\n"<<
 "\tb. Optimal Page Replacement.\n"<<
 "\tc. Least Recently Used\n"
 "\tx. EXIT\n";
char choice;
cin>>choice;
switch(choice){
case 'a':
FIFO();
break;
case 'b':
Optimal();
break;
case 'c':
Least();
break;
case 'x':
break;
}
return 0;
}
