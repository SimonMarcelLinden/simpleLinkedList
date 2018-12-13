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

#ifndef SIMPLYLINKEDLIST_TEXT_H
#define SIMPLYLINKEDLIST_TEXT_H


class TEXT {
public:
    TEXT();
    TEXT(const TEXT& orig);
    virtual ~TEXT();

private:
    EVKD * start;
    int anz;

public:
    int getAmount() const;
    void insert(const char * ln);
    void insertSort(EVKD * ln, const int max);
    EVKD * deleteItem(const int pos);
    void printData() const;
    void iSort();

};


#endif //SIMPLYLINKEDLIST_TEXT_H
