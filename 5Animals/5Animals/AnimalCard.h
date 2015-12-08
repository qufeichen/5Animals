//5Animals
//CSI2372 Final Project
//Professor Jochen Lang
//Qufei Chen - 6771326
//Robert Luo -
//Due Date: December 9th, 2015

#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
#ifndef ANIMALCARD_H
#define ANIMALCARD_H

using namespace std;

enum EvenOdd {
    
    EVEN,
    ODD,
    DEFAULT

};

enum Orientation{
    
    UP,
    DOWN
    
};


class AnimalCard{
    
private:
    Orientation orientation;
    EvenOdd evenOdd;
    EvenOdd next;
    char cardMatrix[2][2];
    char topLeft, topRight, bottomLeft, bottomRight;

public:

	//should functions be optional?
	virtual void setOrientation(Orientation)=0;
	virtual void setRow(EvenOdd)=0;
	virtual EvenOdd getRow()=0;
	virtual void printRow( ostream &, EvenOdd )=0;
    virtual char getAnimal(int, int)=0;
	virtual void printRow(EvenOdd )=0;
    
    inline friend ostream & operator <<(ostream &out, const AnimalCard& card){
        
        out << card.orientation << endl;
        out << card.evenOdd << endl;
        out << card.cardMatrix[0][0] << endl;
        out << card.cardMatrix[0][1] << endl;
        out << card.cardMatrix[1][0] << endl;
        out << card.cardMatrix[1][1] << endl;
        out << card.topLeft << endl;
        out << card.topRight << endl;
        out << card.bottomLeft << endl;
        out << card.bottomRight << endl;
        
        return out;
        
    }
    
    inline friend istream & operator >>(istream &in, AnimalCard& card){
        
        string o;
        in >> o;
        if(o == "UP"){
            card.orientation = Orientation::UP;
        } else {
            card.orientation = Orientation::DOWN;
        }
        int eo;
        in >> eo;
        if(eo == 0){
            card.evenOdd = EvenOdd::EVEN;
            card.next = EvenOdd::ODD;
        } else {
            card.evenOdd = EvenOdd::ODD;
            card.next = EvenOdd::EVEN;
        }
        
        in>>card.cardMatrix[0][0];
        in>>card.cardMatrix[0][1];
        in>>card.cardMatrix[1][0];
        in>>card.cardMatrix[1][1];
        in >> card.topLeft;
        in >> card.topRight;
        in >> card.bottomLeft;
        in >> card.bottomRight;
        
        return in;
    }

};

#endif