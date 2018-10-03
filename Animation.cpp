#include "Animation.hpp"

Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime){
    this->imageCount = imageCount;
    this->switchTime = switchTime;
    totalTime = 0;
    currentImage.x = 0;
    uvrect.width = texture->getSize().x/ float(imageCount.x);
    uvrect.height = texture->getSize().y/ float(imageCount.y);
}
Animation::~Animation(){
    
}
void Animation::update(int row, float deltaTime,int faceRight){
    currentImage.y = row;
    totalTime +=deltaTime;
    if(totalTime>= switchTime){
        totalTime-=switchTime;
        currentImage.x++;
        if(currentImage.x>=imageCount.x){
            currentImage.x = 0;
        }
    }
    uvrect.left = currentImage.x * uvrect.width;
    if(faceRight ==1){ //CREATES ANIMATION OF MOUTH MOVEMENT FOR PACMAN AND EYE MOVEMENT FOR GHOSTS
        uvrect.top = currentImage.y * uvrect.height;
    }
    else if(faceRight ==2){
        uvrect.top = (currentImage.y) * uvrect.height;
    }
    else if(faceRight ==3){
        uvrect.top = (currentImage.y) * uvrect.height;
    }
    else if(faceRight ==4){
        uvrect.top = (currentImage.y) * uvrect.height;
    }
}
