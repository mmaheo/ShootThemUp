//
//  Ally.h
//  ShootThemUp
//
//  Created by Maxime Maheo on 18/03/2015.
//  Copyright (c) 2015 Maxime Maheo. All rights reserved.
//

#ifndef __ShootThemUp__Ally__
#define __ShootThemUp__Ally__

#include <stdio.h>
#include <string>
#include <iostream>

#include <vector>

#include "Ship.h"
#include "Bullet.h"

class Ally : public Ship{
    
private:

    std::vector<Bullet * > _othersBullets;
    
    Bullet * _bonusShoot;
    
    int _numberShootWithBonus;
    int _numberShootWithBonusMax;
    int _numberLifeBuy;
    int _numbersOfLife;
    int _score;

    std::string _name;

public:

    //CONSTRUCTOR
    Ally();
    Ally(const float x, const float y, const int health);

    //DESTRUCTOR
    virtual ~Ally();

    //METHODS
    bool isOver() const;
    std::string toString() const override;
    void changeBonus(int type);
    bool improveOneBulletBonus(int type);
    bool canBuyItem(int type) const;
    virtual void move(const float x, const float y) override;
    void deleteOneLetter();
    void addLetter(std::string letter);
    
    //GETTERS
    int getNumberOfLife() const;
    int getScore() const;
    int getNumberShootBonus() const;
    int getNumberShootBonusMax() const;
    int getBulletBonusType() const;
    int getMainBulletType() const;
    Bullet * getBulletBonus() const;
    Bullet * getOneBulletBonus(int type) const;
    bool bonusShoot();
    void resetBonus();
    void reduceScore(int less);
    int getNumberLifeBuy() const;
    std::string getName() const;
    
    //SETTERS
    void setNumberOfLife(int numberOfLive);
    void setScore(int expPoint);
    void setNumberLifeBuy(int i);

};

#endif /* defined(__ShootThemUp__Ally__) */
