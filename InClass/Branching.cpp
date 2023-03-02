#include <iostream>
#include <string>

using namespace std;

int main() {
    string strChoice = "Blue";
    string strOutcome;
    int flag = 0;

    bool bChoseRed = (strChoice == "Red");

    if (bChoseRed) {
        strOutcome = "Rabbit Hole";
        flag = 1;
    }
    else strOutcome = "Believe whatever";

    cout << strOutcome << endl;

    if (flag) cout << "Rabbit" << endl;
    else cout << "Believe" << endl;

    return 0;
}