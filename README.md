# IMG420 - Assignment 2 Invasion Defense  

A fast-paced arcade-style space shooter built with **Godot**.  
Your goal: survive as long as possible and rack up points while dodging and blasting enemies.  


## Assignment goals 
### Main Goals
- [x] **At least two new features that are developed by extending Sprite2D into a new Node:** Extended Sprite2d into BouncingSprite that travels the map bouncing off of the wall and rotating 
- [x] **Each of these features should have at least 1 parameter that can be manipulated via the editor:** the traveling part has a velocity feature in the editor you can manipulate and the rotating has a rotating speed that you can change 
- [x] **One signal that is emitted by this node that triggers a method in one of the existing nodes in your Scene:** The c++ emits a hit_edge signal and when _on_bouncing_sprite_hit_edge in a node it makes the velocity 1.1 times faster every bounce 
- [x] **One method in this node that is triggered by emitting a signal in one of the existing nodes in your Scene:** There is an emit in the editor when the godot icon is hit that makes the meteor rotate faster by 15 in the c++ next time it appears it stacks and becomes very fast after five kills also on kill the c++ function reset_position is called to move the sprite back to where the godot icon is 


## How to Play  
- **Start Game**  Click the **Start Game** button on the main menu.  
- **Movement** Use the **Arrow Keys** (↑ ↓ ← →) to move your ship.  
- **Shooting**  Press **Spacebar** to fire lasers.  
- **Avoid Collisions**  Touching any UFO or Satellite destroys your ship and ends the game.
- **NEW** New Evil Godot Icon that spawns in after you gain more than 25 points. The godot icon shoots a sprite2d extension called BouncingSprite of a meteor to try and distract you and get you killed, kill the Godot Icon to be rid of this annoying pest! 


## Power-Ups  
- **Satellite Power-Up**: Occasionally appears during gameplay.  
  - Shoot it before it disappears to unlock the **Shotgun Buff** (spread shot) for a few seconds.  
  - Time is limited don’t miss your chance!  


## Evil Godot Icon
- This evil godot icon wants your ship to be destroyed by the ufos, and to do this it tries to distract you with a rotating meteor that bounces around the screen gaining speed every bounce.
- If you destroy the evil godot icon, he will come back with a new meteor that is back to its normal speed but a new faster rotation since he was slain and wants to distract you more. 
- Keep destroying him for points and to get that pesky meteor out of your face!

## Installation  
1. Download or clone this repository.  
2. Open **Godot**.  
3. Import the project:  
   - Either select the **project.godot** file  
   - Or import directly from the downloaded ZIP.
   - Compile the C++ 
4. Run the project to start playing.  


## Goal  
- Earn as many points as possible before your ship is destroyed.  
- Test your reflexes and survive the invasion!  



## Credits  
Developed as part of **IMG420 - Assignment 1**.  
Built with the [Godot Engine](https://godotengine.org/).  
