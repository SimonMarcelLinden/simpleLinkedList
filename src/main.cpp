/**
 * @editor     CLion
 * @since      1.0.0
 * @package    simpleLinkedList
 * @subpackage ./src
 * @author Jakob Hoefker <jakob.hoefker@smail.th-koeln.de>
 * @author Simon Marcel Linden <simon_marcel.linden@smail.th-koeln.de>
 * @date 05.12.2018
 *
 * Algorithmen und Datenstrukturen
 * Praktikum - 2
 * @team Team 25
 */

#include "./header/main.h"

string getString() {
    string input;
    getline(cin, input);
    getline(cin, input);
    return input;
}

//    char *name[] = {
//            "Schmitz, Josef",
//            "Mueller, Josi",
//            "Schmitz, Anna",
//            "Mueller, Josef",
//            "Schmitz, Josi",
//            "Mueller, Anna",
//            "Meier, Josef",
//            "Zacher, Josi",
//            "Anker, Anna"
//    };


int main() {
    char *name[] = {
            "Maier, Josef",
            "Baumhard, Eckhard",
            "Kleinoth, Matthias",
            "Althoff, Anna"
    };

    const int nameCount = 4;

    string input;
    TEXT * text = new TEXT();
    EVKD * el = nullptr;
    int choice;

    while (true) {

        cout << "1) Listenobjekt erstellen" << endl;
        cout << "2) Liste anzeigen" << endl;
        cout << "3) Element anhaengen" << endl;
        cout << "4) Element sortiert einfuegen" << endl;
        cout << "5) Element loeschen" << endl;
        cout << "6) Liste sortieren" << endl;
        cout << "7) Programm beenden" << endl;

        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Anzahl der alten Datensaetze: " << text->getAmount() << endl;
                for (int i = 0; i < nameCount; i++) {
                    text->insert(name[i]);
                }
                cout << "Anzahl der neuen Datensaetze: " << text->getAmount() << endl;
                break;
            }
            case 2: {
                text->printData();
                cout << "-- Es sind " << text->getAmount() << " vorhanden --" << endl;
                break;
            }
            case 3: {
                input = getString();
                text->insert(input.c_str());
                break;
            }
            case 4: {
                input = getString();
                text->insertSort(new EVKD(input.c_str(), nullptr), text->getAmount());
                break;
            }
            case 5: {
                cout << "Welches Element soll entfernt werden?" << endl;
                cin >> choice;
                el = text->deleteItem(choice);
                if(el != nullptr)
                    cout << "Loesche eintrag: " << el->getData() << "\n";
                else
                    cout << "Nicht gefunden.\n";
                delete el;
                break;
            }
            case 6: {
                text->iSort();
                break;
            }
            case 7: {
                cout << "Ende" << endl;
                return 0;
            }
            default: {
                cout << "Falsche Eingabe" << endl;
                break;
            }
        }
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}