#include "Collide.hpp"
#include <cmath>
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace std;

Collide::~Collide(){
    
}

Collide::Collide(sf::RectangleShape& body):body(body){
    
}

//BOARD COLLISION
bool Collide::CheckCollision(const Collide & other, float push){
    sf::Vector2f otherPosition = other.GetPosition();
    sf::Vector2f otherHalfSize = other.GetHalfSize();
    sf::Vector2f thisPosition = GetPosition();
    sf::Vector2f thisHalfSize = GetHalfSize();

    float deltaX = otherPosition.x - thisPosition.x;
    float deltaY = otherPosition.y - thisPosition.y;
    
    float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
    float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

    if(intersectX < 0.0f && intersectY < 0.0f){
        push = min(max(push,0.0f),1.0f);
        if(intersectX > intersectY){
            if(deltaX>0.0f){
                Move(intersectX * (1.0f - push), 0.0f);
                other.Move(-intersectX * push, 0.0f);
            }
            else{
                Move(-intersectX * (1.0f - push), 0.0f);
                other.Move(intersectX * push, 0.0f);
            }
        }
        else{
            if(deltaY>0.0f){
                Move(0.0f, intersectY * (1.0f - push));
                other.Move(0.0f, -intersectY * push);
            }
            else{
                Move(0.0f, -intersectY * (1.0f - push));
                other.Move(0.0f,intersectY * push);
            }
        }
        return true;
    }
    return false;
}

//BALL COLLISION
bool Collide::CheckCollisionBall(const Collide & other, float push){
    sf::Vector2f otherPosition = other.GetPosition();
    sf::Vector2f otherHalfSize = other.GetHalfSize();
    sf::Vector2f thisPosition = GetPosition();
    sf::Vector2f thisHalfSize = GetHalfSize();
    float deltaX = otherPosition.x - thisPosition.x;
    float deltaY = otherPosition.y - thisPosition.y;
    
    float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
    float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);
    
    
    if(intersectX < 0.0f && intersectY < 0.0f){
        push = min(max(push,0.0f),1.0f);
        if(intersectX > intersectY){
            if(deltaX>0.0f){
                MoveBall(-1000,-800); //MOVES BALLS WHEN PACMAN HITS THEM
                other.Move(-intersectX * push, 0.0f);
            }
            else{
                MoveBall(-1000,-800);//MOVES BALLS WHEN PACMAN HITS THEM
                other.Move(intersectX * push, 0.0f);
            }
        }
        else{
            if(deltaY>0.0f){
                MoveBall(-1000,-800);//MOVES BALLS WHEN PACMAN HITS THEM
                other.Move(0.0f, -intersectY * push);
            }
            else{
                MoveBall(-1000,-800);//MOVES BALLS WHEN PACMAN HITS THEM
                other.Move(0.0f,intersectY * push);
            }
        }
        return true;
    }
    return false;
}

//GHOST COLLSION
bool Collide::CheckCollisionGhost(const Collide & other, float push){
    sf::Vector2f otherPosition = other.GetPosition();
    sf::Vector2f otherHalfSize = other.GetHalfSize();
    sf::Vector2f thisPosition = GetPosition();
    sf::Vector2f thisHalfSize = GetHalfSize();

    float deltaX = otherPosition.x - thisPosition.x;
    float deltaY = otherPosition.y - thisPosition.y;
    
    float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
    float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);
    
    
    if(intersectX < 0.0f && intersectY < 0.0f){
        push = min(max(push,0.0f),1.0f);
        if(intersectX > intersectY){
            if(deltaX>0.0f){
                Moveghost(50.0f,-75.0f); //MOVES GHOSTS WHEN PACMAN HITS THEM
                other.MovePac(0.0f,-400.0f);
            }
            else{
                Moveghost(50.0f,-75.0f);//MOVES GHOSTS WHEN PACMAN HITS THEM
                other.MovePac(0.0f,-400.0f);
            }
        }
        else{
            if(deltaY>0.0f){
                Moveghost(50.0f,-75.0f);//MOVES GHOSTS WHEN PACMAN HITS THEM
                other.MovePac(0.0f,-400.0f);
            }
            else{
                Moveghost(50.0f,-75.0f);//MOVES GHOSTS WHEN PACMAN HITS THEM
                other.MovePac(0.0f,-400.0f);
            }
        }
        return true;
    }
    return false;
}




