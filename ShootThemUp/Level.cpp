//
//  Level.h
//  ShootThemUp
//
//  Created by Nicolas Valaise on 18/03/2015.
//  Copyright (c) 2015 Nicolas Valaise. All rights reserved.
//

#include "Level.h"
#include "const.h"

using namespace std;

/*
 * default constructor
 */
Level::Level() : _levelNumber(LEVEL_NUMBER), _nbEnemies(LEVEL_ENEMY_NUMBER){

    addEnemies();

    _ally = new Ally();
    _ally->setLevel(this);

    #ifdef __linux__
    _boss = nullptr;
    #else
    _boss = 0;
    #endif
}

/*
 * destructor
 * info : virtual
 */
Level::~Level(){

    for (auto p : _tabEnemies) {
        delete p;
    }
    _tabEnemies.clear();

    for (auto p : _tabBullets) {
        delete p;
    }
    _tabBullets.clear();

    for (auto enemy : _tabEnemies) {
        delete enemy;
    }
    _tabEnemies.clear();

    delete _ally;

    delete _boss;

}

//----------METHODS----------
/*
 * returns : true if the level is finish.
 * info : constant
 */
bool Level::isFinish() const{

    #ifdef __linux__
    return _tabEnemies.size() <= 0 && _boss == nullptr;
    #else
    return _tabEnemies.size() <= 0 && _boss == 0;
    #endif
}

/*
 * returns : string of enemy's toString
 * info : constant
 */
string Level::toString() const{
    string str;

    for(auto p : _tabEnemies){
        str += p->toString();
    }

    return str;
}

/*
 * check for all graphic element in the level if there are collision between them
 */
void Level::checkCollisions(){

    bool collision = false;

    #ifdef __linux__
    if(_ally != nullptr && _tabBullets.size() > 0){
    #else
    if(_ally != 0 && _tabBullets.size() > 0){
    #endif
        //collision between ally and bullets
        int a = 0;
        for (auto bullet : _tabBullets) {
            if(_ally->collisions(bullet)){
                //cout << "Vous avez pris une balle !" << endl;
                _ally->setHealth(_ally->getHealth() - bullet->getDamage());
                collision = true;

                if(_ally->isDead()){
                    //cout << "Vous etes mort" << endl;
                }

                _tabBullets.erase(_tabBullets.begin() + a);
                delete bullet;
                a--;
            }
            a++;
        }
    }

    #ifdef __linux__
    if(_boss != nullptr && _tabBullets.size() > 0){
    #else
    if(_boss != 0 && _tabBullets.size() > 0){
    #endif
        //collision between boss and bullets
        int b = 0;
        for (auto bullet : _tabBullets) {
            if(_boss->collisions(bullet)){
                //cout << "Un boss à pris une balle !" << endl;
                _boss->setHealth(_boss->getHealth() - bullet->getDamage());
                collision = true;

                if(_boss->isDead()){
                    //cout << "Vous avez tué le boss" << endl;
                    #ifdef __linux__
                    _boss = nullptr;
                    #else
                    _boss = 0;
                    #endif
                }

                _tabBullets.erase(_tabBullets.begin() + b);
                delete bullet;
                b--;
            }
            b++;
        }
    }

    if(_tabBullets.size() > 0 && _tabEnemies.size() > 0){
        //collision between enemies and bullets
        int j = 0;
        for (auto enemy : _tabEnemies) {
            int i = 0;
            for(auto bullet : _tabBullets){
                if(enemy->collisions(bullet)){
                    //cout << "Un ennemi a pris une balle !" << endl;
                    enemy->setHealth(enemy->getHealth() - bullet->getDamage());
                    collision = true;

                    _tabBullets.erase(_tabBullets.begin() + i);
                    delete bullet;
                    
                    _ally->setScore(_levelNumber*2);

                    if(enemy->isDead()){
                        _tabEnemies.erase(_tabEnemies.begin() + j);
                        delete enemy;
                        j--;
                    }
                    i--;
                }
                i++;
            }
            j++;
        }
    }

        #ifdef __linux__
        if(_ally != nullptr && _tabEnemies.size() > 0){
        #else
        if(_ally != 0 && _tabEnemies.size() > 0){
        #endif
        //collision between ally and enemies
        int k = 0;
        for (auto enemy : _tabEnemies) {
            if(_ally->collisions(enemy)){

                _ally->setHealth(_ally->getHealth() - (_ally->getHealth() / 4));

                //cout << "Vous avez tué un ennemi" << endl;

                _tabEnemies.erase(_tabEnemies.begin() + k);
                delete enemy;
                k--;
            }
            k++;
        }
    }

        #ifdef __linux__
        if(_ally != nullptr && _boss != nullptr){
        #else
        if(_ally != 0 && _boss != 0){
        #endif
        //collision between ally and boss
        if(_ally->collisions(_boss)){

            _ally->setHealth(_ally->getHealth() - (_ally->getHealth() / 4));
            _boss->setHealth(_boss->getHealth() - (_boss->getHealth() / 4));
            if(_boss->isDead()){
                //cout << "Vous avez tué un ennemi" << endl;
                #ifdef __linux__
                _boss = nullptr;
                #else
                _boss = 0;
                #endif
                
            }
        }
    }

    /*
    if(_tabBullets.size() > 0){
        for(int i = 0; i < _tabBullets.size(); i++){
            for(int j = 0; j < _tabBullets.size(); j++){
                if(i!=j && _tabBullets[i]->collisions(_tabBullets[j])){
                    cout << "Collision entre les balles" << endl;
                    
                    _tabBullets.erase(_tabBullets.begin() + i);
                    _tabBullets.erase(_tabBullets.begin() + j);
                    
                    delete _tabBullets[i];
                    delete _tabBullets[j];
                    i--;
                    
                    
                }
            }
        }
    }
    */

    if(!collision){
        //cout << "Aucune collision pour le moment" << endl;
    }

    //uniquement pour le model, sinon pour la vue, c'est que la fonction qui verifie si la balle et encore dans la fenetre
    /*for(auto bullet : _tabBullets){
        delete bullet;
    }
    _tabBullets.clear();
    */

    //pour détruire la balle quand elle est hors du cadre, utilisé pour la vue

    /* for(auto bullet : _tabBullets){
        int i = 0;
        if((bullet->getX()+bullet->getWidth() >= SCREEN_WIDTH) || (bullet->getX() <= 0) || (bullet->getY()+bullet->getHeight() >= SCREEN_HEIGHT) ||(bullet->getY()<= 0)){
            //cout << "balle en dehors du cadre" << endl;
            
            _tabBullets.erase(_tabBullets.begin() + i);
            delete bullet;
            i--;
        }
        i++;
     }*/
}

/*
 * add a bullet in the bullet's vector
 * params : bullet
 */
void Level::addBullet(Bullet* bullet){
    _tabBullets.push_back(bullet);
}

/*
 * move enemies in the level
 * info : constant
 */
void Level::moveEnemies() const{
    for(auto enemy : _tabEnemies){
        enemy->move(enemy->getX(), enemy->getY() + enemy->getSpeedY());
    }
}

/*
 * allows all enemies shoot
 * info : constant
 */
void Level::EnemiesShoot() const{

    for (auto enemy : _tabEnemies) {
        enemy->shoot();
    }

}

void Level::addBoss(){
    _boss = new Boss(SCREEN_WIDTH / 2 - BOSS_PICTURE_WIDTH / 2 * 3, -200, BOSS_LIFE, BOSS_FIRERATE);
    _boss->setLevel(this);
}

void Level::addEnemies(){

    srand((unsigned int)time(NULL));

    
    for(int i = 0; i < _nbEnemies; i++){
        
        int type = rand()%3;

        if(type == 0){
            int x = rand()%(SCREEN_WIDTH - MIGHTY_PICTURE_WIDTH);
            int y = i * - 100;
            
            Enemy* enemy = Enemy::Mighty(x, y);
            enemy->setLevel(this);
            _tabEnemies.push_back(enemy);

        }
        else if (type == 1){
            int x = rand()%(SCREEN_WIDTH - SUBMARINE_PICTURE_WIDTH);
            int y = i * - 200;
            
            Enemy* enemy = Enemy::Submarine(x, y);
            enemy->setLevel(this);
            _tabEnemies.push_back(enemy);

        }
        else if (type == 2){
            int x = rand() % (SCREEN_WIDTH - TINY_PICTURE_WIDTH);
            int y = i * - 100;
            
            Enemy* enemy = Enemy::Tiny(x, y);
            enemy->setLevel(this);
            _tabEnemies.push_back(enemy);
        }
    }
}

void Level::deleteAllEnemy(){

    for (auto enemy : _tabEnemies) {
        delete enemy;
    }

    _tabEnemies.clear();

}

//----------GETTERS----------
/*
 * returns : ally
 * info : constant
 */
Ally* Level::getAlly() const{
    return _ally;
}

Boss* Level::getBoss() const{
    return _boss;
}
vector<Enemy*> Level::getEnemies() const{
    return _tabEnemies;
}

vector<Bullet*> Level::getBullets() const{
    return _tabBullets;
}

/*
 * returns : enemies who are still in live
 * info : constant
 */
int Level::getEnemiesNumber() const{
    return (int)_tabEnemies.size();
}

int Level::getNbEnemies() const{
    return _nbEnemies;
}

int Level::getLevelNumber() const{
    return _levelNumber;
}

void Level::setNbEnemies(int nbEnemies){
    _nbEnemies = nbEnemies;
}

void Level::setLevelNumber(int levelNumber){
    _levelNumber = levelNumber;
}

int Level::getNumberOfBullets() const{
    return (int)_tabBullets.size();
}

int Level::getNumberOfEnemies() const{
    return (int)_tabEnemies.size();
}

void Level::moveBullets(){
    for(auto b : _tabBullets){
        b->move(b->getX()+b->getSpeedX(), b->getY()+b->getSpeedY());
    }
}











