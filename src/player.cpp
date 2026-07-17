//
// Created by Jason Evans on 17/07/2026.
//

#include "player.h"
using namespace godot;

void Player::_bind_methods() {

}

Player::Player() {

}

Player::~Player() {
}

void Player::HandleInput(const Input *input, double deltaTime) {

    Vector2 velocity;

    if (input->is_action_pressed("move_right")) {
        velocity.x += 1;
        sprite->play("Walk-Side");
        sprite->set_flip_h(false);
    }
    if (input->is_action_pressed("move_left")) {
        velocity.x -= 1;
        sprite->play("Walk-Side");
        sprite->set_flip_h(true);
    }
    if (input->is_action_pressed("move_up")) {
        velocity.y -= 1;
        sprite->play("Walk-Up");
    }
    if (input->is_action_pressed("move_down")) {
        velocity.y += 1;
        sprite->play("Walk-Down");

    }
    if (velocity.x == 0 && velocity.y == 0) {
        sprite->play("Idle-Side");
    }

    velocity = velocity.normalized() * 100.0f;
    set_position(get_position() + velocity * deltaTime);
}

void Player::_ready() {
    set_position(Vector2(100,200));
    sprite = get_node<AnimatedSprite2D>("AnimatedSprite2D");
    sprite->play("Idle-Side");
}

void Player::_process(double deltaTime) {
    HandleInput(Input::get_singleton(), deltaTime);
}


