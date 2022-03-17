#include<SFML\Graphics.hpp>
#include<iostream>
#include"menu1.h"
#include"options.h"
#include<SFML/Audio.hpp>
using namespace sf;
using namespace std;
int main()
{
	const int xscreen = 800, yscreen = 600;
	double xvelocity_ball= -.7;
	double yvelocity_ball = -.7;
	bool play = false;
	bool option = false;

	RenderWindow window(VideoMode(xscreen, yscreen), "pong game");
	menu1 Menu(xscreen, yscreen);
	options Option(window.getSize().x, window.getSize().y);
	Event event;

	//font
	Font font;
	if (!font.loadFromFile("fonts/212 Leahlee Sans.ttf"))
		throw("COULD NOT LOAD FONT !");


	// "score"
	Text score;
	score.setFont(font);
	score.setCharacterSize(90);
	score.setFillColor(Color::Black);
	score.setStyle(Text::Bold);
	score.setPosition(Vector2f(350, 30));
	score.setString("score");

	// how to move in menu
	Text menu;
	menu.setFont(font);
	menu.setCharacterSize(40);
	menu.setFillColor(Color::Green);
	menu.setStyle(Text::Bold);
	menu.setPosition(Vector2f(0, 0));
	menu.setString(" press ( W ) to move up , press ( S )  to move down  and ");
	
	Text menu2;
	menu2.setFont(font);
	menu2.setCharacterSize(40);
	menu2.setFillColor(Color::Green);
	menu2.setStyle(Text::Bold);
	menu2.setPosition(Vector2f(0, 50));
	menu2.setString("press  (enter) in order for your choice to be accepted");

	// how to move in options
	Text option1;
	option1.setFont(font);
	option1.setCharacterSize(40);
	option1.setFillColor(Color::Yellow);
	option1.setStyle(Text::Bold);
	option1.setPosition(Vector2f(0, 0));
	option1.setString(" press ( Q )  to move up , press ( A )  to move down  and");

	Text option2;
	option2.setFont(font);
	option2.setCharacterSize(40);
	option2.setFillColor(Color::Yellow);
	option2.setStyle(Text::Bold);
	option2.setPosition(Vector2f(0, 50));
	option2.setString("press ( space ) in order for your choice to be accepted");


	//backgruond of menu and options
	Texture menu_ground;
	if (!menu_ground.loadFromFile("abstract-dark-blue-polygonal-background-abstraktsiia-geometr.jpg"))
	{
		cout << "not found";
	}
	menu_ground.setRepeated(true);
	Sprite menusprt;
	menusprt.setTexture(menu_ground);
	menusprt.setTextureRect((IntRect(0, 0, 800, 600)));


	//background of game
	Texture background;
	if (!background.loadFromFile("Free_Pink_Background_Vector.png"))
	{
		cout << "can't load it";
	}
	background.setRepeated(true);
	Sprite sprt;
	sprt.setTexture(background);
	sprt.setTextureRect(sf::IntRect(0, 0, 800, 800));


	//sound of missing the ball
	SoundBuffer buffer;
	if (!buffer.loadFromFile("FX_Click_Positiv_8-bit.wav"))
	{
		cout << "error";
	}
	Sound missing_ball;
	missing_ball.setBuffer(buffer);


	// game sound
	SoundBuffer buffer2;
	if (!buffer2.loadFromFile("happy music .wav"))
	{
		cout << "error";
	}
	Sound game_sound;
	game_sound.setBuffer(buffer2);


	// sound of hitting
	SoundBuffer buffer3;
	if (!buffer3.loadFromFile("HIT_Click_Positive_Single.wav"))
	{
		cout << "error";
	}
	Sound hitting;
	hitting.setBuffer(buffer3);


	//left paddle
	RectangleShape left_paddle;
	left_paddle.setSize(Vector2f(15, 100));
	left_paddle.setPosition(0, 200);
	left_paddle.setFillColor(Color::Blue);


	//right paddle
	RectangleShape right_paddle;
	right_paddle.setSize(Vector2f(15, 100));
	right_paddle.setPosition(785, 200);
	right_paddle.setFillColor(Color::Green);


	// ball
	CircleShape ball;
	ball.setRadius(15.0);
	ball.setPosition(400, 300);
	ball.setFillColor(Color::Yellow);


	// score of left paddle
	int score_left = 0;
	Text textscore_left;
	string strscore_left = to_string(score_left);
	textscore_left.setString(strscore_left);
	textscore_left.setFont(font);
	textscore_left.setCharacterSize(60);
	textscore_left.setPosition(Vector2f(100, 50));
	textscore_left.setFillColor(Color::Blue);


	// score of right paddle
	int score_right = 0;
	Text textscore_right;
	string strscore_right = to_string(score_right);
	textscore_right.setString(strscore_right);
	textscore_right.setFont(font);
	textscore_right.setCharacterSize(60);
	textscore_right.setPosition(Vector2f(700, 50));
	textscore_right.setFillColor(Color::Green);


	// game loop
	while (window.isOpen())
	{

		while (window.pollEvent(event))
		{
			
			switch (event.type)
			{

	        // restarting the game
			case Event::Closed:
				play = false;
				score_right = 0;
				strscore_right = to_string(score_right);
				textscore_right.setString(strscore_right);
			
				score_left = 0;
				strscore_left = to_string(score_left);
				textscore_left.setString(strscore_left);

				ball.setPosition(400, 300);

				left_paddle.setPosition(0, 200);
				right_paddle.setPosition(785, 200);
				break;
			}

			// menu control
			switch (event.type)
			{
			case Event::KeyReleased:
				switch (event.key.code)
				{
				case Keyboard::W:
					Menu.MoveUp();
					break;
				case Keyboard::S:
					Menu.MoveDown();
					break;

				}
			}

			// option control
			switch (event.type)
			{
			case Event::KeyReleased:
				switch (event.key.code)
				{
				case Keyboard::Q:
					Option.moveup();
					break;
				case Keyboard::A:
					Option.movedown();
					break;

				}
			}

			if (event.type == Event::KeyReleased)
			{
				if (event.key.code == Keyboard::Space)
				{
					if (Option.presseditem() == 0)
					{
						xvelocity_ball = -.7, yvelocity_ball = -.7;
						option = false;
					}
					if (Option.presseditem() == 1)
					{

						xvelocity_ball = -1.0, yvelocity_ball = -1.0;
						option = false;
					}
					if (Option.presseditem() == 2)
					{
						xvelocity_ball = -1.4, yvelocity_ball = -1.4;
						option = false;
					}

				}
				
			}
		}

			if (event.type == Event::KeyReleased)
			{
				if (event.key.code == Keyboard::Return)
				{
					if (Menu.getpresseditem() == 0)
					{
						play = true;
					}
					if (Menu.getpresseditem() == 1)
					{
						option = true;

					}

					if (Menu.getpresseditem() == 2)
					{
						window.close();
					}

				}

			}
			
		// displaying the game
		if (play == true)
		{
			// left paddle movement
			if (Keyboard::isKeyPressed(Keyboard::Down))
				left_paddle.move(Vector2f(0, 1));

			if (Keyboard::isKeyPressed(Keyboard::Up))
				left_paddle.move(Vector2f(0, -1));

			// right paddle movement
			if (Keyboard::isKeyPressed(Keyboard::Left))
				right_paddle.move(Vector2f(0, 1));

			if (Keyboard::isKeyPressed(Keyboard::Right))
				right_paddle.move(Vector2f(0, -1));


			//left paddle control
			if (left_paddle.getPosition().y < 0)
				left_paddle.setPosition(0, 0);

			if (left_paddle.getPosition().y > 500)
				left_paddle.setPosition(0, 500);


			//right paddle control
			if (right_paddle.getPosition().y < 0)
				right_paddle.setPosition(785, 0);

			if (right_paddle.getPosition().y > 500)
				right_paddle.setPosition(785, 500);


			// ball movement
			ball.move(xvelocity_ball, yvelocity_ball);


			// ball control
			if (ball.getPosition().y < 0)
			{
				yvelocity_ball = -yvelocity_ball;
			}

			if (ball.getPosition().y > 580)
			{
				yvelocity_ball = -yvelocity_ball;	
			}

			if (ball.getGlobalBounds().intersects(left_paddle.getGlobalBounds()) == true)
			{
				xvelocity_ball = -xvelocity_ball;
		        hitting.play();
			}

			if (ball.getGlobalBounds().intersects(right_paddle.getGlobalBounds()) == true)
			{
				xvelocity_ball = -xvelocity_ball;
				hitting.play();
			}


			// when right paddle wins
			if (ball.getPosition().x < 0)
			{
				missing_ball.play();
				ball.setPosition(400, 300);
			    score_right++;
				strscore_right = to_string(score_right);
				textscore_right.setString(strscore_right);
			}


			// when left paddle wins
			if (ball.getPosition().x > 800)
			{
				missing_ball.play();
				ball.setPosition(400, 300);
				score_left++;
				strscore_left = to_string(score_left);
				textscore_left.setString(strscore_left);
			}

		
			window.clear();
			window.draw(sprt);
			window.draw(left_paddle);
			window.draw(right_paddle);
			window.draw(ball);
			window.draw(textscore_left);
			window.draw(textscore_right);
			window.draw(score);
			window.display();
		}

	

        // displaying the menu
		if (play == false&&option==false)
		{
			window.clear();
			window.draw(menusprt);
			game_sound.play();
			Menu.draw(window);
			window.draw(menu);
			window.draw(menu2);
			window.display();

		}
	

	// displaying the options	
		if (option == true)
		{
			window.clear();
			window.draw(menusprt);
			game_sound.play();
			Option.draw(window);
			window.draw(option1);
			window.draw(option2);
			window.display();

		}
		
		

	}



	return 0;
}