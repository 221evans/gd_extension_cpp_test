//
// Created by Jason Evans on 17/07/2026.
//

#include "player.h"
#include <godot_cpp/classes/engine.hpp>

using namespace godot;

void Player::_bind_methods() {

}

Player::Player() {
    attacking = false;
}

Player::~Player() = default;

void Player::HandleInput(const Input *input, double deltaTime) {

    Vector2 velocity;

    attacking = input->is_action_pressed("attack_side");

    if (attacking) {
        sprite->play("Attack-Side");
    }
    else if (input->is_action_pressed("attack_side")) {
        sprite->play("Attack-Side");
    }

    else if (input->is_action_pressed("move_right")) {
        velocity.x += 1;
        sprite->play("Walk-Side");
        sprite->set_flip_h(false);
    }
    else if (input->is_action_pressed("move_left")) {
        velocity.x -= 1;
        sprite->play("Walk-Side");
        sprite->set_flip_h(true);
    }
    else if (input->is_action_pressed("move_up")) {
        velocity.y -= 1;
        sprite->play("Walk-Up");
    }
    else if (input->is_action_pressed("move_down")) {
        velocity.y += 1;
        sprite->play("Walk-Down");

    }
    else if (velocity.x == 0 && velocity.y == 0) {
        sprite->play("Idle-Side");
    }

    velocity = velocity.normalized() * 100.0f;
    set_position(get_position() + velocity * deltaTime);
}

void Player::_ready() {
    set_position(Vector2(100,200));
    sprite = get_node<AnimatedSprite2D>("AnimatedSprite2D");
}

void Player::_process(double deltaTime) {

    if (Engine::get_singleton()->is_editor_hint()) {
        return;
    }

    HandleInput(Input::get_singleton(), deltaTime);
}


