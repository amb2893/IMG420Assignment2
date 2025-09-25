#include "bouncing_sprite.h"
#include <godot_cpp/core/math.hpp>

using namespace godot;

// Constructor
BouncingSprite::BouncingSprite() {

}

// Destructor
BouncingSprite::~BouncingSprite() {

}

// Called when the node enters the scene tree
void BouncingSprite::_ready() {
    // Get the viewport size for edge detection
    if (get_viewport()) {
        screen_size = get_viewport()->get_visible_rect().size;
    }
}

//  method to increase velocity I used this to test the speed increase but now it does not do anything here
void BouncingSprite::increase_speed() {
    velocity *= 1;
}

// Rotation speed setter/getter
void BouncingSprite::set_rotation_speed(double p_speed) {
    rotation_speed = p_speed;
}

double BouncingSprite::get_rotation_speed() const {
    return rotation_speed;
}

// Called every frame

void BouncingSprite::_process(double delta) {
    // Move the sprite based on velocity
    set_position(get_position() + velocity * delta);

    // Rotate the sprite
    set_rotation_degrees(get_rotation_degrees() + rotation_speed * delta);

    Vector2 pos = get_position();
    bool hit = false;

    // Check horizontal bounds
    if (pos.x < 0 || pos.x > screen_size.x) {
        velocity.x = -velocity.x;
        hit = true;
    }

    // Check vertical bounds
    if (pos.y < 0 || pos.y > screen_size.y) {
        velocity.y = -velocity.y;
        hit = true;
    }

    // Emit signal and increase speed if an edge was hit
    if (hit) {
        increase_speed();          // scale velocity on bounce
        emit_signal("hit_edge");   // notify GDScript
    }
}


// Method to reset position to center of screen
void BouncingSprite::reset_position() {
    set_position(0,0);

}


void BouncingSprite::on_explode() {
  
    set_rotation_speed(rotation_speed+15)
    
}

void BouncingSprite::_bind_methods() {
    // Bind getter and setter for velocity
    ClassDB::bind_method(D_METHOD("get_velocity"), &BouncingSprite::get_velocity);
    ClassDB::bind_method(D_METHOD("set_velocity", "velocity"), &BouncingSprite::set_velocity);

    // Expose as a property
    ADD_PROPERTY(PropertyInfo(Variant::VECTOR2, "velocity"), "set_velocity", "get_velocity");

    // Bind getter/setter for rotation speed
    ClassDB::bind_method(D_METHOD("set_rotation_speed", "rotation_speed"), &BouncingSprite::set_rotation_speed);
    ClassDB::bind_method(D_METHOD("get_rotation_speed"), &BouncingSprite::get_rotation_speed);
    ClassDB::bind_method(D_METHOD("on_explode"), &BouncingSprite::on_explode);



    // Expose rotation_speed as a property in editor
    ADD_PROPERTY(
        PropertyInfo(Variant::FLOAT, "rotation_speed"), // type and name
        "set_rotation_speed",                           // setter
        "get_rotation_speed"                            // getter
    );
    // Bind increase_speed method 
    ClassDB::bind_method(D_METHOD("increase_speed"), &BouncingSprite::increase_speed);

    // Signal
    ADD_SIGNAL(MethodInfo("hit_edge"));
    ADD_SIGNAL(MethodInfo("explode"));


    // Other method
    ClassDB::bind_method(D_METHOD("reset_position"), &BouncingSprite::reset_position);
}

