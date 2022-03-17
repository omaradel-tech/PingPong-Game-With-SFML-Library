#include "menu1.h"


menu1::menu1(float width, float height)
{
	if (font.loadFromFile("fonts/212 Leahlee Sans.ttf"))
	{

	}
	Menu[0].setFont(font);
	Menu[0].setFillColor(Color::Red);
	Menu[0].setCharacterSize(90);
	Menu[0].setString("play");
	Menu[0].setPosition(Vector2f(width / 2-50, height / (max_num_of_items + 1) * 1-30));


	Menu[1].setFont(font);
	Menu[1].setFillColor(Color::White);
	Menu[1].setCharacterSize(90);
	Menu[1].setString("options");
	Menu[1].setPosition(Vector2f(width / 2-50,height / (max_num_of_items + 1) * 2-20));

	Menu[2].setFont(font);
	Menu[2].setFillColor(Color::White);
	Menu[2].setCharacterSize(90);
	Menu[2].setString("exit");
	Menu[2].setPosition(Vector2f(width /2-50, height / (max_num_of_items + 1) * 3));
	

	selecteditemindex = 0;
}
menu1::~menu1()
{
	
}
void menu1::draw(RenderWindow& menu)
{
	for (int i = 0; i < max_num_of_items; i++)
	{
		menu.draw(Menu[i]);
	}
}

void menu1::MoveUp()
{
	if (selecteditemindex - 1 >= 0)
	{
		Menu[selecteditemindex].setFillColor(Color::White);
		selecteditemindex--;
		Menu[selecteditemindex].setFillColor(Color::Red);
		if (selecteditemindex == -1)
			selecteditemindex = 2;
	}
}
void menu1::MoveDown()
{
	if (selecteditemindex + 1 <= max_num_of_items)
	{
		Menu[selecteditemindex].setFillColor(Color::White);
		selecteditemindex++;
		Menu[selecteditemindex].setFillColor(Color::Red);
		if (selecteditemindex == 3)
			selecteditemindex = 0;
	}
}
