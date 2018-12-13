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

EVKD::EVKD(const char * LPSZDaten, EVKD * n) {
    anz = strlen(LPSZDaten);
    this->daten = new char[anz];
    memcpy(this->daten, LPSZDaten, anz);
    next = n;
}

EVKD::EVKD(const EVKD& orig) {
    anz = orig.anz;
    this->daten = new char[anz];
    memcpy(this->daten, orig.daten, anz);
    next = orig.next;
}

EVKD::~EVKD() {
    delete daten;
}

int EVKD::getAnz() const {
    return anz;
}

EVKD * EVKD::getNext() const {
    return next;
}

char * EVKD::getData() const {
    char * buf = new char[anz + 1];
    memcpy(buf, daten, anz);
    buf[anz] = '\0';
    return buf;
}

void EVKD::setNext(EVKD * obj) {
    next = obj;
}

bool EVKD::operator>(const EVKD &e) const {
    const char * s1 = this->getData();
    const char * s2 = e.getData();
    const bool res = strcmp(s1, s2) > 0;
    delete s1;
    delete s2;
    return res;
}

bool EVKD::operator==(const EVKD &e) const {
    const char * s1 = this->getData();
    const char * s2 = e.getData();
    const bool res = strcmp(s1, s2) == 0;
    delete s1;
    delete s2;
    return res;
}