#include "options.h"

options::options(float width, float height)
{
	if (font.loadFromFile("fonts/212 Leahlee Sans.ttf"))
	{

	}
	Option[0].setFont(font);
	Option[0].setFillColor(Color::Red);
	Option[0].setCharacterSize(90);
	Option[0].setString("Easy");
	Option[0].setPosition(Vector2f(width / 2-80, height / (max_items + 1) * 1-30));
	
	Option[1].setFont(font);
	Option[1].setFillColor(Color::Green);
	Option[1].setCharacterSize(90);
	Option[1].setString("Normal");
	Option[1].setPosition(Vector2f(width / 2-80, height / (max_items + 1)* 2-20));

	Option[2].setFont(font);
	Option[2].setFillColor(Color::Green);
	Option[2].setCharacterSize(90);
	Option[2].setString("Hard");
	Option[2].setPosition(Vector2f(width / 2-80, height / (max_items + 1) * 3));
	

	selectedindex = 0;
}
options::~options()
{

}
void options::draw(RenderWindow& window)
{
	for (int i = 0; i < max_items; i++)
	{
		window.draw(Option[i]);
	}
		
}
void options::moveup()
{
	if (selectedindex - 1 >= 0)
	{
		Option[selectedindex].setFillColor(Color::Green);
			selectedindex--;
			Option[selectedindex].setFillColor(Color::Red);
				if (selectedindex == -1)
					selectedindex = 2;
	}
}
void options::movedown()
{
	if (selectedindex + 1 <= max_items)
	{
		Option[selectedindex].setFillColor(Color::Green);
		selectedindex++;
		Option[selectedindex].setFillColor(Color::Red);
		if (selectedindex == 3)
			selectedindex =0;
	}
}



