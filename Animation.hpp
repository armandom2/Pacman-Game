#ifndef Animation_hpp
#define Animation_hpp
#include <SFML/Graphics.hpp>

#include <stdio.h>
class Animation{
public:
    Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
    ~Animation();
    sf::IntRect uvrect;
    void update(int row, float deltaTime,int faceRight);
    
private:
    sf::Vector2u imageCount;
    sf::Vector2u currentImage;
    
    float totalTime;
    float switchTime;
    
    
    
};

#endif /* Animation_hpp */
