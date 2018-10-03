#ifndef Ghost_hpp
#define Ghost_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "Random.hpp"
#include "Collide.hpp"
#include "Animation.hpp"
class Ghost{
public:
    Ghost(sf::RectangleShape& body);

    Ghost(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
    ~Ghost();
    
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
    Collide GetCollider() {return Collide(body);}
    
    float movementSpeed = 0.75f;
    float movementLength = 500.0f;
    int direction = 0;
    int counter = 0;
    void updateMovement(float deltaTime);
    
private:
    sf::RectangleShape body;
    Animation animation;
    unsigned int row;
    float speed;
    int faceRight;
    
};
#endif /* Ghost_hpp */
