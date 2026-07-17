#ifndef MY_CLASS_H
#define MY_CLASS_H

#include <godot_cpp/classes/node.hpp>

namespace godot {

    class MyClass : public Node {
        GDCLASS(MyClass, Node)

    private:
        int counter = 0;

    protected:
        static void _bind_methods();

    public:
        MyClass();
        ~MyClass();

        void increment();
        int get_counter() const;
    };

}

#endif
