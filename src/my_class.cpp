#include "my_class.h"

using namespace godot;

void MyClass::_bind_methods() {
    ClassDB::bind_method(D_METHOD("increment"), &MyClass::increment);
    ClassDB::bind_method(D_METHOD("get_counter"), &MyClass::get_counter);
}

MyClass::MyClass() {
  counter = 0;
}

MyClass::~MyClass() {

}

void MyClass::increment() {
    counter++;
}

int MyClass::get_counter() const {
    return counter;
}
