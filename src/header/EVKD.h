/**
 * @editor     CLion
 * @since      1.0.0
 * @package    simpleLinkedList
 * @subpackage ./src/header
 * @author Jakob Hoefker <jakob.hoefker@smail.th-koeln.de>
 * @author Simon Marcel Linden <simon_marcel.linden@smail.th-koeln.de>
 * @date 05.12.2018
 *
 * Algorithmen und Datenstrukturen
 * Praktikum - 2
 * @team Team 25
 */

#ifndef SIMPLYLINKEDLIST_EVKD_H
#define SIMPLYLINKEDLIST_EVKD_H


class EVKD {
public:
    EVKD(const char * LPSZDaten, EVKD * n);
    EVKD(const EVKD& orig);
    virtual ~EVKD();

private:
    char * daten;
    int anz;
    EVKD * next;

public:
    int getAnz() const;
    EVKD * getNext() const;
    char * getData() const;
    void setNext(EVKD * obj);

    bool operator>(const EVKD &e) const;
    bool operator==(const EVKD &e) const;
};


#endif //SIMPLYLINKEDLIST_EVKD_H
