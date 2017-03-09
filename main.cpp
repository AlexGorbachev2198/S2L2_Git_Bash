#include <iostream>
#include <string.h>
using namespace std;

class Football_Player {
    string Surname;
    double Transfer_cost;
    bool k;
public:
    Football_Player() {
        Transfer_cost = 0;
        Surname = "";
    }
    Football_Player(string NS, double TC) {
        Transfer_cost = TC;
        Surname = NS;
    }
    void set (string NS, double TC)
    {
        Transfer_cost = TC;
        Surname = NS;
    }
    bool getFP(double summ) {
        if (Transfer_cost <= summ){ k = true; return true;}
        else{k = false; return false;}
    }
    void print()
    {

        if(k) {cout<<Surname << " Transfer cost: " << Transfer_cost<< endl;}
    }
};

int main()
{
    int amount_of_avail = 0;
    int n;
    double sum =0;
    double cost;
    string name;
    cout<< "Amount of players" << endl;
    cin >> n;
    Football_Player **F_P;
    F_P = new Football_Player*[n];
    for (unsigned int i =0; i < n ; ++i) {
        cout << "Name of the player:" << endl;
        cin >> name;
        cout << "Cost of the player:" << endl;
        cin >> cost;
        F_P[i]= new Football_Player(name, cost);
    }
    cout << "How much money do you have?" << endl;
    cin >> sum;
    for(unsigned int i =0; i < n ; ++i)
    {
        if(F_P[i]->getFP(sum)) amount_of_avail++;
    }
    cout<< "Amount of available players: " << amount_of_avail<< endl;
    for(unsigned int i =0; i < n ; ++i)
    {
        F_P[i]->print();
    }

    for(unsigned int i =0; i < n ; ++i)
    {
        delete[]F_P[i];
    }
   delete []F_P;
};