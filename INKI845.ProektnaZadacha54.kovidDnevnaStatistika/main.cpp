#include <iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

struct covidMK {
    string grad;
    int novi;
    int ozdraveni;
};

void zamena(int &a, int &b) {
   int temp;
   temp = a;
   a = b;
   b = temp;
}

void sortiranje(covidMK *stats, int size) {
   int i, j, imax;
   for(i = 0; i<size-1; i++) {
      imax = i;
      for(j = i+1; j<size; j++)
         if(stats[j].novi > stats[imax].novi)
            imax = j;
         swap(stats[i], stats[imax]);
   }
}

bool my_cmp(const covidMK& a, const covidMK& b)
{
    return a.novi > b.novi;
}

int main()
{
    ofstream file;
    covidMK stats[8];
    vector <covidMK> v;
    stats[0].grad = "Kumanovo";
    stats[0].novi = 239;
    stats[0].ozdraveni = 13111;
    stats[1].grad = "Stip";
    stats[1].novi = 184;
    stats[1].ozdraveni = 6733;
    stats[2].grad = "Prilep";
    stats[2].novi = 625;
    stats[2].ozdraveni = 10652;
    stats[3].grad = "Tetovo";
    stats[3].novi = 121;
    stats[3].ozdraveni = 11412;
    stats[4].grad = "Veles";
    stats[4].novi = 177;
    stats[4].ozdraveni = 7467;
    stats[5].grad = "Bitola";
    stats[5].novi = 885;
    stats[5].ozdraveni = 9183;
    stats[6].grad = "Struga";
    stats[6].novi = 65;
    stats[6].ozdraveni = 3930;
    stats[7].grad = "Debar";
    stats[7].novi = 6;
    stats[7].ozdraveni = 1458;
    for (int i = 0; i < 8; i++) {
        v.push_back(stats[i]);
    }
    cout<<"Sodrzinata na vektorot pred sortiranje e: "<<endl;
    for (covidMK i: v) {
      cout<<"Grad: " << i.grad <<" || Novozarazeni: " << i.novi << " || Ozdraveni: "<< i.ozdraveni;
      cout<<endl;
    }
    sort(v.begin(), v.end(), my_cmp);
    cout<<"\nSodrzinata na vektorot posle sortiranje e: "<<endl;
    for (covidMK i: v) {
      cout<<"Grad: " << i.grad <<" || Novozarazeni: " << i.novi << " || Ozdraveni: "<< i.ozdraveni;
      cout<<endl;
    }
    file.open("INKI845.covid2401.txt");
    for (covidMK i: v) {
        file << i.grad << " " << i.novi << " " << i.ozdraveni << "\n";
    }
    file.close();

    return 0;
}
