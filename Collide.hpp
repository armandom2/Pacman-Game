#pragma once
#ifndef Collide_hpp
#define Collide_hpp
#include <SFML/Graphics.hpp>
#include <stdio.h>
class Collide{
public:
    Collide(sf::RectangleShape& body);
    ~Collide();
    
    void Move(float dx, float dy)const{ body.move(dx,dy);}
    void MoveBall(float dx, float dy)const{ body.setPosition(dx,dy);} //FUNCTION TO REMOVE BALLS
    void Moveghost(float dx, float dy)const{ body.setPosition(dx,dy);}//FUNCTION TO MOVE GHOST BACK TO CENTER
    void MovePac(float dx, float dy)const{body.setPosition(dx,dy);} // FUNCTION TO MOVE PACMAN TO THE CENTER IF COLLIDED WITH GHOSTS
    sf::Vector2f getPos()const {return body.getPosition();}
    
    bool CheckCollision( const Collide & other, float push);
    bool CheckCollisionBall (const Collide & other, float push);
    bool CheckCollisionGhost (const Collide &other, float push);
    
    sf::Vector2f GetPosition()const {return body.getPosition();}
    sf::Vector2f GetHalfSize()const {return body.getSize()/ 2.0f;}
    
    float movementSpeed = 2.0f;
    int direction = 0;
    int counter = 0;
    void updateMovement();
    
    
    
    
private:
    sf::RectangleShape& body;

    
};

#endif /* Collide_hpp */
