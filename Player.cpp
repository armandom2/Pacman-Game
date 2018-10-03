#include "Player.hpp"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed): animation(texture,imageCount,switchTime){
    this->speed  = speed;
    row = 0;
    faceRight= 0;
    
    body.setSize(sf::Vector2f(100.0f,100.0f));//creates a box named box
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(0.0f,-400.0f);
    body.setTexture(texture);
    
}
Player::~Player(){
    
}
void Player::update(float deltaTime){
    sf::Vector2f movement(0.0f, 0.0f);
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        movement.y -= speed * deltaTime;
        row = 1;//CALLS THE ROW FROM SPRITE SHEET SO PACMAN FACES UP
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        movement.y =speed * deltaTime;
        row = 3;//CALLS THE ROW FROM SPRITE SHEET SO PACMAN FACES DOWN
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        movement.x -=speed * deltaTime;
        row = 2;//CALLS THE ROW FROM SPRITE SHEET SO PACMAN FACES LEFT
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        movement.x =speed * deltaTime;
        row = 0;//CALLS THE ROW FROM SPRITE SHEET SO PACMAN FACES RIGHT
    }

    if(row == 0){
        faceRight = 1;
    }
    else if(row ==1){
        faceRight = 2;
    }
    else if(row ==2){
        faceRight = 3;
    }
    else if(row ==3){
        faceRight = 4;
    }
    
    animation.update(row,deltaTime,faceRight);//CREATES THE ANIMATION BY GOING THROUGH ROW
    body.setTextureRect(animation.uvrect);
    body.move(movement);
    
}
void Player::draw(sf::RenderWindow& window){
    window.draw(body);
    
}

