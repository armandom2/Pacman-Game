#ifndef Player_hpp
#define Player_hpp
#include "Animation.hpp"
#include "Collide.hpp"
#include <stdio.h>

class Player{
public:
    Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
    ~Player();
    
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
    
    Collide GetCollider() {return Collide(body);}
    
private:
    sf::RectangleShape body;
    Animation animation;
    unsigned int row;
    float speed;
    int faceRight;
};
#endif /* Player_hpp */
