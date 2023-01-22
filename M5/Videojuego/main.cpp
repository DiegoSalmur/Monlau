// M5_Juego.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <iostream>
#include<time.h>

using namespace std;


//Atributos del Enemigo
int enemyHP = 2500 + rand() % (2700 - 2500);
int enemydamage = 1500 + rand() % (2500 - 1500);
string Enemyname = "Malo";
bool Vivo1 = true;
int hitEnemy = 1;


//Atributos del Enemigo 2
int enemyHP2 = 2000 + rand() % (2300 - 2000);
int enemydamage2 = 1500 + rand() % (2500 - 1500);
string Enemyname2 = "Malo2";
bool Vivo3 = true;
int hitEnemy2 = 2;

//Atributos del Héroe
string heroname;
int herodamage;
int attacktype = 0;
int attacktype1 = 1300 + rand() % (2500 - 1300);
int attacktype2 = 2000 + rand() % (3000 - 2000);
int attacktype3 = 4000 + rand() % (5000 - 4000);
int heroHP = 7000 + rand() % (10000 - 7000);
bool Vivo2 = true;

//ATRIBUTOS DEL JUEGO
int attacktype;
int limitattack1 = 5;
int limitattack2 = 10;
int enemyChoosed = 0;
int EnemyChoose = 0;

void gameStart() {
    cout << "El enemigo " << Enemyname << " acaba de aparecer y tiene " << enemyHP << " de vida" "\n";
    cout << "Inserta el nombre del heroe que lo va a derrotar\n";
    cin >> heroname;
    cout << "El nombre del héroe es " << heroname << "\n";
}

bool checkEnemyStatus1() {
        if (enemyHP <= 0) {
            cout << "Has derrotado al enemigo 1 " << heroname << "Bien hecho\n";
            return false;

        }
        else {
            cout << "El enemigo le queda " << enemyHP << "puntos de salud." << endl;
        }
    }

bool checkEnemyStatus2() {

    if (enemyHP2 <= 0) {
        cout << "Has derrotado al enemigo 2 " << heroname << "Bien hecho\n";
        return false;

    }
    else {
        cout << "El enemigo le queda " << enemyHP2 << "puntos de salud." << endl;
    }
}

int TypeAttack() {
    attacktype = 0;

    while (attacktype != 1 && attacktype != 3) {

        if (attacktype == 1) {
            attacktype = attacktype1;
            enemyHP = enemyHP - herodamage;
            cout << "A que enemigo le quieres dar";
            cin >> hitEnemy;
        }
        if (attacktype == 2) {
            attacktype = attacktype2;
            enemyHP = enemyHP - herodamage;
            cout << "Te quedan" << (limitattack1 - 1) << " Ataques Igneos";
            cout << "A que enemigo le quieres dar";
            cin >> hitEnemy;

        }
        if (limitattack1 == 0) {
            cout << "Has pasado tu limite de movimientos y no golpeas al enemigo" << endl;
            // Continuar programa
            continue;
        }
        if (attacktype == 3) {
            attacktype = attacktype3;
            cout << "Te quedan " << (limitattack2 - 1) << " Balas de Plata";
            cout << "A que enemigo le quieres dar";
            cin >> hitEnemy;

        }
        if (limitattack2 == 0) {
            cout << "Has pasado tu limite de movimientos y no golpeas al enemigo" << endl;
            // Continuar programa
            continue;
        }
    }
}
int ChooseEnemy() {
    while (EnemyChoose != 1 && EnemyChoose != 2) {
        cout << "A que enemigo quieres atacar= \n";
        cin >> EnemyChoose;
            if (Vivo1) {
                cout << "1.- " << Enemyname << " \n";
            }
        if (Vivo2) {
            cout << "2.- " << Enemyname2 << " \n";
        }
        cin >> EnemyChoose;
        if (EnemyChoose <= 0 || EnemyChoose > 2) {
            cout << "La opcion no es correcta. Por favor, pon una opcion viable. \n";
        }
        if (!Vivo1 && EnemyChoose = 1) {
            cout << "El enemigo " << Enemyname << "Ya esta muerto. Porfavor, elige a otro enemigo que este vivo, y deja de martilizarlo." " \n";
        }
        if (!Vivo2 && EnemyChoose = 2) {
            cout << "El enemigo " << Enemyname2 << "Ya esta muerto. Porfavor, elige a otro enemigo que este vivo, y deja de martilizarlo." " \n";
        }
        return EnemyChoose;
    }
}
int main()
{
    gameStart();
    // 
    enemyChoosed = ChooseEnemy();
        // Tipo de Ataque, y daño

        while (Vivo1 == true && Vivo2 == true && Vivo3 == true) {
            // Tipo de Ataque, y daño
            
            TypeAttack();
            herodamage = attacktype;
            ChooseEnemy();

            if (enemyChoosed == 1) {
                enemyHP = attacktype1 - enemyHP;
                Vivo1 = checkEnemyStatus1();
            }
            else {
                enemyHP2 = attacktype1 - enemyHP2;
                Vivo3 = checkEnemyStatus2();

                if (Vivo1 && Vivo2) {
                    heroHP = enemydamage - heroHP;
                }
                if (Vivo3 && Vivo2) {
                    heroHP = enemydamage2 - heroHP;
                }

            }
        }
}
