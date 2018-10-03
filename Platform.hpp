#ifndef Platform_hpp
#define Platform_hpp
#include <SFML/Graphics.hpp>
#include "Collide.hpp"
#include <stdio.h>

class Platform{
public:
    Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
    ~Platform();
    void Draw(sf::RenderWindow& window);
    Collide GetCollider(){return Collide(body);}
    sf::Vector2f getpos()const {return body.getPosition();}

private:
    sf::RectangleShape body;
    
};
#endif /* Platform_hpp */
