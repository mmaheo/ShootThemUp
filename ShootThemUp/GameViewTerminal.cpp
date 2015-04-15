//
//  GameView.cpp
//  ShootThemUp
//
//  Created by Maxime Maheo on 05/03/2015.
//  Copyright (c) 2015 Maxime Maheo. All rights reserved.
//

#include "GameViewTerminal.h"
#include "Player.h"

using namespace std;

/*
 * default constructor
 */
GameViewTerminal::GameViewTerminal(): _gameModel(nullptr){
    _menu = new Menu();
}

/*
 * destructor
 */
GameViewTerminal::~GameViewTerminal(){
    delete _menu;
}

//----------METHODS----------

/*
 * principal methods to draw. Show variables values
 * info : constant
 */
void GameViewTerminal::draw() const{
    if(_menu->getIntro()) {
        _menu->showIntro();
    }

    if(_menu->getMenu()){
        cout << "---- Menu ----" << endl
        << "1) Jouer" << endl
        << "2) Scores" << endl
        << "3) Quitter" << endl ;

        char choice;
        cin >> choice;
        switch (choice) {
            case '1':
                _menu->setIntro(false);
                _menu->setGame(true);
                _menu->setLevel(true);
                _menu->setShop(false);
                _menu->setMenu(false);
                _menu->setScore(false);
                _menu->setEnding(false);
                break;

            case '2':
                _menu->setIntro(false);
                _menu->setGame(false);
                _menu->setLevel(false);
                _menu->setShop(false);
                _menu->setMenu(false);
                _menu->setScore(true);
                _menu->setEnding(false);
                break;

            case '3':
                _menu->setIntro(false);
                _menu->setGame(false);
                _menu->setLevel(false);
                _menu->setShop(false);
                _menu->setMenu(false);
                _menu->setScore(false);
                _menu->setEnding(true);
                break;
            default:
                cout << "Mauvais choix" << endl;
                break;
        }
    }

    if(_menu->getGame()) {
        if(_menu->getLevel()) {
            cout << "Informations sur le niveau" << endl;
            cout << "\tNiveau : " << _gameModel->getLevel()->getLevelNumber() << endl;
            cout << "\tTour n° : " << _gameModel->getNumberTour() << endl;
            cout << "\tNombre d'ennemis : " << _gameModel->getLevel()->getEnemiesNumber() << endl;
            cout << "\tPortée du tir : " << DEFAULT_SHIP_OFFSET_SHOOT << endl << endl;

            cout << _gameModel->getLevel()->getAlly()->toString() << endl;

            if(_gameModel->getLevel()->getEnemiesNumber() > 0){
                cout << _gameModel->getLevel()->toString() << endl;
            }

            if(_gameModel->getLevel()->getEnemiesNumber() <= 0){
                if(_gameModel->getLevel()->getBoss() != nullptr){
                    cout << _gameModel->getLevel()->getBoss()->toString() << endl;
                }
            }

            char choice;
            float posX;
            float posY;

            cout << "Quel voulez vous faire ?" << endl;
            cout << "\t1) Tirer sur un ennemi" << endl;
            cout << "\t2) Bouger" << endl;
            cout << "Votre choix : ";
            cin >> choice;

            switch (choice) {
                case '1':
                    _gameModel->getLevel()->getAlly()->shoot();
                    break;

                case '2':
                    cout << "Entrer les nouvelles position : " << endl;
                    cout << "position X : ";
                    cin >> posX;
                    cout << "position Y : ";
                    cin >> posY;
                    _gameModel->getLevel()->getAlly()->move(posX, posY);
                    break;

                default:
                    cout << "Mauvais choix" << endl;
                    break;
            }
        }
        if(_menu->getShop()){
            cout << "Bienvenue dans le shop" << endl;
            cout << "Vous pouvez acheter des missiles si vous les souhaitez : " << endl;
            cout << "\t1)Acheter le missile boule de feu : " << DEFAULT_FIREBALL_DAMAGE << " dommages." << endl;
            cout << "\t\tPrix : " << DEFAULT_FIREBALL_PRICE << " $" << endl;

            cout << "\t2)Acheter le missile petit laser : " << DEFAULT_TINYLASER_DAMAGE << " dommages." << endl;
            cout << "\t\tPrix : " << DEFAULT_TINYLASER_PRICE << " $" << endl;

            cout << "\t3)Acheter le missile laser : " << DEFAULT_LASER_DAMAGE << " dommages." << endl;
            cout << "\t\tPrix : " << DEFAULT_LASER_PRICE << " $" << endl;

            cout << "\t4)Restaurer sa vie"<< endl;
            cout << "\t\tPrix : " << DEFAULT_RESTRAURE_LIFE_PRICE << " $" << endl;

            cout << "\t5)Acheter une vie suplémentaire" << endl;
            cout << "\t\tPrix : " << DEFAULT_ADD_LIFE_PRICE << " $" << endl;

            cout << "\t6)Ne rien acheter" << endl;
            char choice;
            cin >> choice;
            switch (choice) {

                case '1':
                    if(_gameModel->getLevel()->getAlly()->getScore() > DEFAULT_FIREBALL_PRICE){
                        _gameModel->getLevel()->getAlly()->setBulletType(1);
                        _gameModel->getLevel()->getAlly()->setScore(_gameModel->getLevel()->getAlly()->getScore() - DEFAULT_FIREBALL_PRICE);
                        cout << "Boule de feu achetée." << endl;
                    }
                    else{
                        cout << "Vous possédez " << _gameModel->getLevel()->getAlly()->getScore() << " $. Il faut " << DEFAULT_FIREBALL_PRICE << " $ pour l'acheter. Revient quand tu auras les sous"<< endl;
                    }
                    break;

                case '2':
                    if(_gameModel->getLevel()->getAlly()->getScore() > DEFAULT_TINYLASER_PRICE){
                        _gameModel->getLevel()->getAlly()->setBulletType(2);
                        _gameModel->getLevel()->getAlly()->setScore(_gameModel->getLevel()->getAlly()->getScore() - DEFAULT_TINYLASER_PRICE);
                        cout << "Petit laser acheté." << endl;

                    }
                    else{
                        cout << "Vous possédez " << _gameModel->getLevel()->getAlly()->getScore() << " $. Il faut " << DEFAULT_TINYLASER_PRICE << " $ pour l'acheter. Revient quand tu auras les sous"<< endl;
                    }
                    break;

                case '3':
                    if(_gameModel->getLevel()->getAlly()->getScore() > DEFAULT_LASER_PRICE){
                        _gameModel->getLevel()->getAlly()->setBulletType(3);
                        _gameModel->getLevel()->getAlly()->setScore(_gameModel->getLevel()->getAlly()->getScore() - DEFAULT_LASER_PRICE);
                        cout << "Laser achetée." << endl;
                    }
                    else{
                        cout << "Vous possédez " << _gameModel->getLevel()->getAlly()->getScore() << " $. Il faut " << DEFAULT_LASER_PRICE << " $ pour l'acheter. Revient quand tu auras les sous"<< endl;
                    }
                    break;

                case '4':
                    if(_gameModel->getLevel()->getAlly()->getScore() > DEFAULT_RESTRAURE_LIFE_PRICE){
                        _gameModel->getLevel()->getAlly()->setHealth(DEFAULT_SHIP_LIFE);
                        _gameModel->getLevel()->getAlly()->setScore(_gameModel->getLevel()->getAlly()->getScore() - DEFAULT_RESTRAURE_LIFE_PRICE);
                        cout << "Vie restaurée." << endl;
                    }
                    else{
                        cout << "Vous possédez " << _gameModel->getLevel()->getAlly()->getScore() << " $. Il faut " << DEFAULT_RESTRAURE_LIFE_PRICE << " $ pour l'acheter. Revient quand tu auras les sous"<< endl;
                    }
                    break;

                case '5':
                    if(_gameModel->getLevel()->getAlly()->getScore() > DEFAULT_ADD_LIFE_PRICE){
                        _gameModel->getLevel()->getAlly()->setNumberOfLife(_gameModel->getLevel()->getAlly()->getNumberOfLife() + 1);
                        _gameModel->getLevel()->getAlly()->setScore(_gameModel->getLevel()->getAlly()->getScore() - DEFAULT_ADD_LIFE_PRICE);
                        cout << "1 vie ajoutée." << endl;
                    }
                    else{
                        cout << "Vous possédez " << _gameModel->getLevel()->getAlly()->getScore() << " $. Il faut " << DEFAULT_ADD_LIFE_PRICE << " $ pour l'acheter. Revient quand tu auras les sous"<< endl;
                    }
                    break;

                case '6':
                    cout << "Au revoir" << endl;
                    _menu->setIntro(false);
                    _menu->setGame(true);
                    _menu->setLevel(true);
                    _menu->setShop(false);
                    _menu->setMenu(false);
                    _menu->setScore(false);
                    _menu->setEnding(false);
                    break;

                default:
                    cout << "Mauvais choix !" << endl;
                    break;
            }
            cout << "Au revoir" << endl;
            _menu->setIntro(false);
            _menu->setGame(true);
            _menu->setLevel(true);
            _menu->setShop(false);
            _menu->setMenu(false);
            _menu->setScore(false);
            _menu->setEnding(false);
        }
    }

    if(_menu->getScore()){
        cout << "Liste des scores" << endl;
        std::vector<Player> players = _menu->showScores(LINUX_SCORE_FILE);

        int i = 1;
        for(auto p : players){
            cout << "Position " << i << endl;
            cout << p.toString() << endl;
            i++;
        }

        _menu->setIntro(false);
        _menu->setGame(false);
        _menu->setLevel(false);
        _menu->setShop(false);
        _menu->setMenu(true);
        _menu->setScore(false);
        _menu->setEnding(false);
    }
    if(_menu->getEnding()){
        int score = _gameModel->getLevel()->getAlly()->getScore();
        cout << "Quel est votre nom ? " ;
        string name ;
        cin >> name;

        _menu->saveScore(score, name, LINUX_SCORE_FILE);

        cout << "La partie est fini" << endl;
    }
}


//----------SETTERS----------
/*
 * params : game model
 */
void GameViewTerminal::setModel(GameModel *gameModel){
    _gameModel = gameModel;
}

bool GameViewTerminal::treatEvent(){
    return _menu->getEnding();
}

void GameViewTerminal::setModelMenu(){
    _gameModel->setMenu(_menu);
}



