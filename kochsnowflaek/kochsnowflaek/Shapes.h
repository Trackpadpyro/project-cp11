#pragma once

#include "pch.h"
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <stdlib.h>


using namespace std;

sf::RenderWindow window(sf::VideoMode(1600, 1000), "dragon curve");

vector<float> lx;
vector<float> ly;
vector<float> ang;

float rad = 3.14159 / 180;

class Turtle
{

public:

	float x, y;
	bool penstate;

	void penup() {
		penstate = 0;
	}

	void pendown() {
		penstate = 1;
	}

	void move(float theta, float dis) {
		if (penstate) {
			lx.push_back(x);
			ly.push_back(y);

			x += dis * cos(-theta * rad);
			y += dis * sin(-theta * rad);

			ang.push_back(theta);
		}
		else {
			x += dis * cos(-theta * rad);
			y += dis * sin(-theta * rad);
		}
	}
};
