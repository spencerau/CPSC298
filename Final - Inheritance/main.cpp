#include "Shape.h"

using namespace std;

int main() {

    Rectangle *r = new Rectangle(2.0, 3.0);
    Circle *c = new Circle(2.0, 2.0);

    Shape *shapes[2];

    shapes[0] = c;
    shapes[1] = r;

    for (int i = 0; i < 2; i++) {
        shapes[i]->displayProperties();
        cout << "Area: " << shapes[i]->area() << endl;
        cout << "Perimeter: " << shapes[i]->perimeter() << endl;
        shapes[i]->scale(2.0);
        shapes[i]->displayProperties();
        cout << "Area: " << shapes[i]->area() << endl;
        cout << "Perimeter: " << shapes[i]->perimeter() << endl;
    }

    // free memory via delete

    delete r;
    delete c;
    

}