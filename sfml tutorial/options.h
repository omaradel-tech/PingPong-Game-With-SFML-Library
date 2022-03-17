#pragma once
#include"SFML/Graphics.hpp"
#define max_items 3
using namespace sf;
class options
{
public:
	options(float width, float height);
	void draw(RenderWindow& window);
	void moveup();
	void movedown();
	int presseditem() { return selectedindex; }
	~options();
private:
	int selectedindex;
	Font font;
	Text Option[max_items];
};

