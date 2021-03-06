//
//  const.h
//  ShootThemUp
//
//  Created by Maxime Maheo on 05/03/2015.
//  Copyright (c) 2015 Maxime Maheo. All rights reserved.
//

#ifndef __CONST_H__
#define __CONST_H__

#include <string>

//##############################################################################################

/*
 * SCREEN
 */
const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 750;
const int SCREEN_FPS = 50;

//##############################################################################################

/*
 * MODEL
 */
const int MODEL_WIDTH = 400;
const int MODEL_HEIGHT = SCREEN_HEIGHT;

//##############################################################################################

/*
 * SCORE FILE
 */
const std::string LINUX_SCORE_FILE = "ShootThemUp/score.txt" ;
const std::string SCORE_FILE = "score.txt";
const std::string YOUR_FILE = LINUX_SCORE_FILE; //please, change hear the constancy to execute the code

//##############################################################################################

/*
 * GRAPHIC ELEMENT
 */
const float GRAPHIC_ELEMENT_X = 0;
const float GRAPHIC_ELEMENT_Y = 0;
const float GRAPHIC_ELEMENT_SPEED_X = 1;
const float GRAPHIC_ELEMENT_SPEED_Y = 1;
const int GRAPHIC_ELEMENT_WIDTH = 10;
const int GRAPHIC_ELEMENT_HEIGHT = 10;

//##############################################################################################

/*
 * ALLY
 */
const int ALLY_LIFE = 300;
const float ALLY_FIRERATE = 0.3;
const int ALLY_PICTURE_HEIGHT = 49;
const int ALLY_PICTURE_WIDTH = 183;
const float ALLY_SPEEDX = 5;
const float ALLY_SPEEDY = 5;
const int ALLY_NUMBER_OF_LIFE = 3;
const int ALLY_BULLET_TYPE = 0;

//##############################################################################################

/*
 * ENEMY
 */
const int ENEMY_FIRERATE = 1.4;
const float ENEMY_SPEEDX = 1;
const float ENEMY_SPEEDY = 1;

//##############################################################################################

/*
 * TINY
 */
const int TINY_LIFE = 70;
const int TINY_DAMAGE = 20;
const int TINY_PICTURE_HEIGHT = 31;
const int TINY_PICTURE_WIDTH = 96;

//##############################################################################################

/*
 * MIGHTY
 */
const int MIGHTY_LIFE = 90;
const int MIGHTY_DAMAGE = 40;
const int MIGHTY_PICTURE_HEIGHT = 45;
const int MIGHTY_PICTURE_WIDTH = 180;

//##############################################################################################

/*
 * SUBMARINE
 */
const int SUBMARINE_LIFE = 110;
const int SUBMARINE_DAMAGE = 30;
const int SUBMARINE_PICTURE_HEIGHT = 197;
const int SUBMARINE_PICTURE_WIDTH = 82;

//##############################################################################################

/*
 * BOSS
 */
const int BOSS_LIFE = 200;
const int BOSS_PICTURE_HEIGHT = 74;
const int BOSS_PICTURE_WIDTH = 279;
const float BOSS_DEFAULT_SPEEDX = 3;
const float BOSS_DEFAULT_SPEEDY = 3;
const float BOSS_FIRERATE = 0.9;

//##############################################################################################

/*
 * ALLY BULLET
 */
const float ALLY_BULLET_SPEEDX = 0;
const float ALLY_BULLET_SPEEDY = -8;

//##############################################################################################

/*
 * ENEMY BULLET
 */
const float ENEMY_BULLET_SPEEDX = 0;
const float ENEMY_BULLET_SPEEDY = 8;

//##############################################################################################

/*
 * STANDARD BULLET
 */
const int STANDARD_DAMAGE = 20;
const int STANDARD_PICTURE_WIDTH = 9;
const int STANDARD_PICTURE_HEIGHT = 9;
const int STANDARD_PRICE = 100;

//##############################################################################################

/*
 * FIREBALL BULLET
 */
const int FIREBALL_DAMAGE = 30;
const int FIREBALL_PICTURE_HEIGHT = 18;
const int FIREBALL_PICTURE_WIDTH = 18;
const int FIREBALL_PRICE = 150;


//##############################################################################################

/*
 * TINYLASER BULLET
 */
const int TINYLASER_DAMAGE = 40;
const int TINYLASER_PICTURE_HEIGHT = 20;
const int TINYLASER_PICTURE_WIDTH = 9;
const int TINYLASER_PRICE = 200;

//##############################################################################################

/*
 * LASER BULLET
 */
const int LASER_DAMAGE = 60;
const int LASER_PICTURE_HEIGHT = 30;
const int LASER_PICTURE_WIDTH = 9;
const int LASER_PRICE = 300;

//##############################################################################################

/*
 * DOUBLE TINY LASER BULLET
 */
const int DOUBLE_TINY_LASER_DAMAGE = 50;
const int DOUBLE_TINY_LASER_PICTURE_HEIGHT = 16;
const int DOUBLE_TINY_LASER_PICTURE_WIDTH = 17;
const int DOUBLE_TINY_LASER_PRICE = 250;

//##############################################################################################

/*
 * OTHER
 */
const int SHIP_OFFSET_SHOOT = 20;
const int RESTRAURE_LIFE_PRICE = 300;
const int ADD_LIFE_PRICE = 100;
const int DEFAULT_SCORE = 0;
const int DEFAULT_POINT = 20;
const int LEVEL_NUMBER = 1;
const int LEVEL_ENEMY_NUMBER = 3;
const int LEVEL_INITIAL_ENEMY_OFFSET = 50;

//##############################################################################################

/*
 * SECOND THEME
 */


const int SECOND_ALLY_HEIGHT = 230;
const int SECOND_ALLY_WIDTH = 46;

const int SECOND_TINY_HEIGHT = 41;
const int SECOND_TINY_WIDTH = 50;

const int SECOND_MIGHTY_HEIGHT = 90;
const int SECOND_MIGHTY_WIDTH = 50;

const int SECOND_SUBMARINE_HEIGHT = 80;
const int SECOND_SUBMARINE_WIDTH = 71;

const int SECOND_BULLET_HEIGHT = 20;
const int SECOND_BULLET_WIDTH = 92;

//##############################################################################################


#endif
