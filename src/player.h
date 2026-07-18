//
// Created by Jason Evans on 17/07/2026.
//

#ifndef GD_EXTENSION_CPP_EXAMPLE_PLAYER_H
#define GD_EXTENSION_CPP_EXAMPLE_PLAYER_H
#include <godot_cpp/classes/node2d.hpp>

#include "godot_cpp/classes/animated_sprite2d.hpp"
#include "godot_cpp/classes/input.hpp"


namespace godot {

    class Player : public Node2D {
        GDCLASS(Player, Node2D)

    private:
        // Data goes here
        AnimatedSprite2D *sprite = nullptr;
        bool attacking;

    protected:
        static void _bind_methods();

    public:
        Player();
        ~Player() override;

        void HandleInput(const Input* input, double deltaTime);
        void _ready() override;
        void _process(double deltaTime) override;
    };
}

#endif //GD_EXTENSION_CPP_EXAMPLE_PLAYER_H
