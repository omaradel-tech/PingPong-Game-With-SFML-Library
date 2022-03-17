#pragma once
#include"SFML/Graphics.hpp"
#define max_num_of_items 3
using namespace sf;
class menu1
{
public:
	menu1(float width, float height);
	 void draw(RenderWindow &menu);
	 void MoveUp();
	 void MoveDown();
	 int getpresseditem() { return selecteditemindex; }
	 ~menu1();
private:
	int selecteditemindex;
	Font font;
	Text Menu[max_num_of_items];
};
