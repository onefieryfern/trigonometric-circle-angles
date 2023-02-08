#include <iostream>
#include <graphics.h>
#include <cmath>

constexpr double pi{ 3.14159265358979 };

struct UnghiRad {
    int coeficient{};
    int numitor{};
};

struct Punct {
    int x{};
    int y{};
};

Punct transfCoord (Punct punct, int max_y) {
    punct.y = max_y - punct.y;
    return punct;
}

int main() {

    initwindow(600, 400, "Desenare Unghiuri (radiani)");

    int raza{};
    std::cin >> raza;

    UnghiRad unghi;
    std::cin >> unghi.coeficient;
    std::cin >> unghi.numitor;

    double unghi_final = pi;//(unghi.coeficient * pi) / unghi.numitor;

    int sinDist{ static_cast<int>(raza * std::cos(unghi_final)) };
    int cosDist{ static_cast<int>(raza * std::sin(unghi_final)) };

    Punct p { sinDist, cosDist };

    std::cout << p.x << ' ' << p.y;

    circle(300, 200, raza);
    line (300, 200, p.x, p.y);

    getch();
    closegraph();

    return 0;
}
