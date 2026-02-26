#include<bits/stdc++.h>
using namespace std;

int main(){
    cout<<"Line Intersection"<<endl;

    int a1, b1, c1;
    int a2, b2, c2;

    cin >> a1 >> b1 >> c1;
    cin >> a2 >> b2 >> c2;

    int determinant = a1 * b2 - a2 * b1;
    
    if (determinant == 0) {
        cout << "No unique solution (parallel or coincident lines)";
    } else {
        double x = (c1 * b2 - c2 * b1) / (double)determinant;
        double y = (a1 * c2 - a2 * c1) / (double)determinant;

        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
    }

    return 0;
}


