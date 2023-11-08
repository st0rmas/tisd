#include "MenuItem.h"
#include <iostream>

using namespace std;

MenuItem::MenuItem(string label, void (*action)()) : label(label), action(action) {}

void MenuItem::execute() {
    action();
}

string MenuItem::getLabel()  {
    return label;
}
