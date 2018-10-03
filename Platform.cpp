#include "Platform.hpp"
Platform::Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position){ //CREATES THE BOARD AND PAC DOTS
    body.setSize(size);
    body.setOrigin(size/2.0f);
    body.setTexture(texture);
    body.setPosition(position);
}
Platform::~Platform(){
    
}

void Platform::Draw(sf::RenderWindow& window){
    window.draw(body);
}


