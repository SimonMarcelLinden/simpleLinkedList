/**
 * @editor     CLion
 * @since      1.0.0
 * @package    simpleLinkedList
 * @subpackage ./src/classes
 * @author Jakob Hoefker <jakob.hoefker@smail.th-koeln.de>
 * @author Simon Marcel Linden <simon_marcel.linden@smail.th-koeln.de>
 * @date 05.12.2018
 *
 * Algorithmen und Datenstrukturen
 * Praktikum - 2
 * @team Team 25
 */

#include "../header/main.h"

TEXT::TEXT() {
    start = nullptr;
    anz = 0;
}

TEXT::TEXT(const TEXT& orig) {
    anz = orig.anz;
    start = new EVKD(*orig.start); // use copy constructor
}

TEXT::~TEXT() {
    if (start != nullptr) delete start;
}

int TEXT::getAmount() const {
    return anz;
}

void TEXT::insert(const char * ln) {
    if (start == nullptr) {
        start = new EVKD(ln, nullptr);
    } else {
        EVKD * el = start;
        while (el->getNext() != nullptr) el = el->getNext();
        el->setNext(new EVKD(ln, nullptr));
    }
    anz++;
}

void TEXT::insertSort(EVKD * ln, const int max) {
    EVKD * temp;
    EVKD * next = start;
    EVKD * prev = nullptr; //NULL;

    if (start == NULL) {//NULL) {
        start = ln;
    } else if (*start > *ln) {
        ln->setNext(start);
        start = ln;
    } else {
        for (int i = 0; i < max; i++) {

            if (*ln > *next) {
                prev = next;
                next = next->getNext();
            } else i = max;

        }
        prev->setNext(ln);
        ln->setNext(next);
    }
    anz++;
}

EVKD * TEXT::deleteItem(const int pos) {
    // NUR ausketten! Pos ist 1 basierend!!!!!

    if (start == nullptr) return nullptr;
    if (this->anz < pos) return nullptr;

    EVKD * el = start;
    if (pos == 1) {
        start = start->getNext();
        anz--;
        return el;
    }

    EVKD * pre = start;
    for (int i = 2; i < pos; i++) {
        if (pre == nullptr) return nullptr;
        pre = pre->getNext();
    }

    el = pre->getNext();
    if (el->getNext() == nullptr) {
        pre->setNext(nullptr);
    } else {
        pre->setNext(el->getNext());
        el->setNext(nullptr); // remove link
    }

    anz--;
    return el;
}

void TEXT::printData() const {
    // print data + pointer address
    EVKD * el = start;
    while (el != nullptr) {
        std::cout << "Adresse: " << el << "\tInahlt: " << el->getData() << std::endl;
        el = el->getNext();
    }
}

void TEXT::iSort() {
    EVKD * temp;
    EVKD * begin;
    for (int i = 1; i < anz; i++) {
        temp = deleteItem(i + 1);
        this->insertSort(temp, i);
    }
}