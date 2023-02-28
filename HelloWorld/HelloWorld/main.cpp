#include <iostream>
#include <cmath>

using namespace std;

int get_max(int num1, int num2){
    if(num1 >= num2){
        return num1;
    } else {
        return num2;
    }
}

int main() {
    
    cout << get_max(4, 4) << endl;
    
    return 0;
}

