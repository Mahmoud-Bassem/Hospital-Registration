#include<bits\stdc++.h>
#define endl '\n'
#define pb push_back
#define mp make_pair
#define forn(i,n) for(int i=0;i<n;i++)
using namespace std;

struct patient{
    int status;
    string name;
    int spec;
};

vector<deque<pair<string,int>>>v(100);


void menu(){
    cout<<"1)Add new patient"<<endl;
    cout<<"2)Print all patients"<<endl;
    cout<<"3)Get next patient"<<endl;
    cout<<"4)Exit"<<endl;
}

void add(){
    patient p;
    cout<<"Enter specialization, name, status: ";
    cin>>p.spec>>p.name>>p.status;
    if(v[p.spec].size()>4) cout<<"sorry, we cant add more patients for this specialization"<<endl;
    else if(p.status)
    v[p.spec].push_front(mp(p.name,p.spec));
    else v[p.spec].pb(mp(p.name,p.spec));
}

void pri(){
    forn(i,v.size()){
        if(v[i].size()>0){
            cout<<"There are "<<v[i].size()<<" in specialization "<<i<<endl;
            for( auto it: v[i]){
                cout<<it.first<<' ';
                cout<<(it.second==1? "urgent": "regular");
                cout<<endl;
            }
        }
    }
}


void call(){
    int i;
    cout<<"Enter specialization: ";
    cin>>i;
    if(v[i].size()>0){
            cout<<v[i][0].first<<" please go with the dr "<<endl;
            v[i].pop_front();
    }
    else cout<<"No patients at the moment. Have rest, Dr"<<endl;
}


signed main(){
    m:
    menu();
    int choice;
    cin>>choice;
    if(choice ==1 ) {
        add(); goto m;
    }
    else if(choice == 2){
        pri(); goto m;
    }
    else if(choice ==3){
        call(); goto m;
    }
    else return 0;
}
