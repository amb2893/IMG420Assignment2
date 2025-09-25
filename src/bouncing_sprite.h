#pragma once

#include <godot_cpp/classes/sprite2d.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/classes/viewport.hpp>


using namespace godot;

class BouncingSprite : public Sprite2D {
    GDCLASS(BouncingSprite, Sprite2D);

private:
    Vector2 velocity = Vector2(100, 100); // Default speed
    Vector2 screen_size;

    // New variables
    double rotation_speed = 0.0;   // degrees per second, editable in editor
    float speed_multiplier = 1.1;  // how much velocity increases per bounce

public:
    // Existing velocity getters/setters
    Vector2 get_velocity() const { return velocity; }
    void set_velocity(const Vector2& v) { velocity = v; }

    // New rotation speed getters/setters
    void set_rotation_speed(double p_speed);
    double get_rotation_speed() const;

    // Optional: increase velocity
    void increase_speed();

protected:
    static void _bind_methods();

public:
    BouncingSprite();
    ~BouncingSprite();

    void _ready();
    void _process(double delta);
    void BouncingSprite::on_explode();
   

    // Method to reset position
    void reset_position();
};
