#include <iostream>

using namespace std;


int incrementByReturn(int x){
    x = x+1;

    return x;
}

void incrementByValue(int x){
    x = x+1;
}

void incrementByAddress(int* x){
    cout << "Inside function, value of x: " << x;
    *x = *x + 1;
}

void incrementByReference(int& x){
    x = x+1;
}


int main(){
    int x=5;

    // scanf("%d", &x);
    // cin >> x;

    //printf("x=%d", x);
    cout << "Initial x= " << x << "\n\n";

    x = incrementByReturn(x);

    cout << "Inc by return x= " << x << "\n\n\n";

    incrementByValue(x);

    cout << "Inc by val x= " << x << endl;

    incrementByAddress(&x);

    cout << "Inc by addr x= " << x << endl;


    incrementByReference(x);

    cout << "Inc by referencer x= " << x << endl;


    //int v[3]; // static allocation
    int* v = (int*)malloc(3* sizeof(int));

    for(int i=0;i<3;i++){
        cout<<"v["<<i<<"]=";
        cin >> v[i];
        cout << endl;
    }

    for(int i=0;i<3;i++){
        cout<<"v["<<i<<"]=" << v[i] << " ";
    }

    cout << endl << "First element of v: " << *v;
    cout << endl << "Second element of v: " << *(v+1);
    cout << endl << "Second element of v: " << 1[v];
    cout << endl << "First element of v: " << *v;

    return 0;
}