#include "pch.h"
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "windows.h"
#include "Shapes.h"

using namespace std;


sf::Vector2i mousePos = sf::Mouse::getPosition(window);

int length = 1;
int width = 1;
int xi = 800;
int yi = 500;
float gamma;

Turtle tur;
vector<bool> turi = {0};

vector<bool> temp;

void dline(float x, float y, float theta, float dis) {
	sf::RectangleShape line(sf::Vector2f(dis, width));
	line.setPosition(x + xi, y + yi);
	line.setFillColor(sf::Color(255, 255, 255));
	line.rotate(-theta);
	window.draw(line);
}

int main() {
	//-------------------------
	
	tur.pendown();

	//-------------------------
	while (window.isOpen()) {
		//pause
		Sleep(0);

		//clear window and get mousepos
		window.clear();
		mousePos = sf::Mouse::getPosition(window);

		//check for closing window
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Escape)
					window.close();
			}
		}
		//-------------------------
		temp = turi;
		turi.push_back(0);
		for (int n = temp.size() - 1; n >= 0; n--) {
			if (temp[n]) {
				turi.push_back(0);
			}
			else {
				turi.push_back(1);
			}
		}

		for (int n = 0; n < turi.size(); n++) {
			if (turi[n]) {
				gamma -= 90;
			}
			else {
				gamma += 90;
			}
			tur.move(gamma, length);
		}

		for (int n = 0; n < lx.size(); n++) {
			dline(lx[n], ly[n], ang[n], length);
		}
		//-------------------------
		//display 
		window.display();
	}
	return 0;
}
