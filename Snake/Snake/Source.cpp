#include"GameController.h"

int  print_menu() {
    int variant = 0;
    system("cls");
    std::cout << "What do you want to do?\n";
    std::cout << "1. Play \n";
    std::cout << "2. Set Flag(see info)\n";
    std::cout << "3. Set Speed(see info)\n";
    std::cout << "4. Info\n";
    std::cout << "5. Exit\n";
    std::cout << ">";
    std::cin >> variant;
    return variant;
}


int main() {
    Snake snake;
	GameController gameController;
    int variant = 0;
    int flag = 1;
    int speed = 40;
    gameController.setFlag(flag);
    gameController.setSpeed(speed);
    do {
        variant = print_menu();

        switch (variant) {
        case 1:
            gameController.play(snake);

        case 2:
            std::cout << "Flag: ";
            std::cin >> flag;
            gameController.setFlag(flag);
            break;

        case 3:
            std::cout << "Speed: ";
            std::cin >> speed;
            gameController.setFlag(flag);
            break;

        case 4:
            std::cout << "Info:\n";
            std::cout << "Movement on WASD\n";
            std::cout << "Flag - this is game mode (By default Flag = 1)\n";
            std::cout << "Set Flag(1): If you want GAME OVER, when you collision with the wall\n";
            std::cout << "Set Flag(2): If you want to appear from the other side when in collision with the wall\n";
            std::cout << "Speed - this is how fast the speed of the game will be, the larger the number, the slower it will go(By default Speed = 40)\n";
            system("pause");
            break;
        case 5:
            std::cout << "Exit..." << std::endl;
            break;
        default:
            std::cerr << "You choose wrong variant" << std::endl;
        }
    } while (variant != 3);

}
