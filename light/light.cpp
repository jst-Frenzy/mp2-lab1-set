// MyLib.cpp : Определяет функции для статической библиотеки.
//

#include "light.h"

// TODO: Это пример библиотечной функции.
pLight::pLight() : state(2), maxState(2) {
    state.InsElem(1);
};

void pLight::switchLight() {
    if (state.IsMember(1)) {
        state.DelElem(1);
        state.InsElem(0);
    }
    else {
        state.DelElem(0);
        state.InsElem(1);
    }
}

bool pLight::isGreen() const {
    return state.IsMember(1);
}

bool pLight::isYellow() const {
    return false;
}

bool pLight::isRed() const {
    return state.IsMember(0);
}

cLight::cLight() : state(3), maxState(3) { // 3 состояния у светофора, 0 - зеленый 1 - желтый 2 - красный
    state.InsElem(2);
}

void cLight::switchLight() {
    if (state.IsMember(0)) {
        state.DelElem(0);
        state.InsElem(1);
    }
    else if (state.IsMember(1)) {
        state.DelElem(1);
        state.InsElem(2);
    }
    else if (state.IsMember(2)) {
        state.DelElem(2);
        state.InsElem(0);
    }
}

bool cLight::isGreen() const {
    return state.IsMember(0);
}

bool cLight::isYellow() const {
    return state.IsMember(1);
}

bool cLight::isRed() const {
    return state.IsMember(2);
}

Crossroad::Crossroad() {
    while (!cl.isRed()) {
        cl.switchLight();
    }
    while (!pl.isGreen()) {
        pl.switchLight();
    }
}

void Crossroad::switchLight() {
    cl.switchLight();
    if (cl.isRed()) {
        while (!pl.isGreen()) {
            pl.switchLight();
        }
    }
    else {
        while (!pl.isRed()) {
            pl.switchLight();
        }
    }
}

std::ostream& Crossroad::printL(std::ostream& out, const Light& l) const {
    if (l.isGreen()) out << "Green";
    else if (l.isYellow()) out << "Yellow";
    else if (l.isRed()) out << "Red";
    return out;
}

std::ostream& operator<< (std::ostream& out, const Crossroad& r) {
    out << "p : "; r.printL(out, r.pl) << endl;
    out << "C : "; r.printL(out, r.cl) << endl;
    return out;
}