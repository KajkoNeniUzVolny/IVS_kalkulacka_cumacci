#include <SFML/Graphics.hpp>
#include<iostream>
#include"Button.h"
#include"Display.h"
#include<vector>
#include<string>
#include<sstream>
#include"Namespaces.h"

#define BUTTONCOUNT 24
#define FONT_ON_DISPLAY_SIZE 40
#define CHARACTER_SIZE 65

using namespace sf;
using std::vector;
using std::string;

RenderWindow window(VideoMode(600, 800), "Calculator", Style::Close | Style::Titlebar);

char Buttonchars[BUTTONCOUNT] = { 'C', '<', '!', 's', '.', '^', '%', ':', '7', '8', '9', '*', '4', '5', '6', '-', '1', '2', '3', '+', '0','(', ')', '='};
const Color MouseOnButtonColour = Color::Color(110, 110, 110, 50);
RectangleShape HoverShape;

const Vector2f ButtonSize = { 150.f, 100.f };

vector<RectangleShape> Buttons;

string CurrentTask = "";
Text TextOnDisplay;
string PrevTask = "";

bool MouseHeld = false;

Font font;


//call once
void FirstSetUp()
{
	TextOnDisplay.setCharacterSize(FONT_ON_DISPLAY_SIZE);
	TextOnDisplay.setFont(font);
	TextOnDisplay.setString(CurrentTask);
	int YNumber = 2;
	bool Corner = true;

	for (size_t i = 0; i < BUTTONCOUNT; i++)
	{
		int XNumber = 1;
		Color ButtonColor = Color::Color(16, 16, 16);

		if (Buttonchars[i] == 'C' || Buttonchars[i] == '<')
		{
			ButtonColor = Color::Color(25, 25, 25);
		}
		Buttons.push_back(RectangleShape({ ButtonSize.x * XNumber, ButtonSize.y }));
		Buttons[i].setFillColor(ButtonColor);

		if (Corner)
		{
			Buttons[i].setPosition(0.f, YNumber * 100.f); Corner = false;
		}
		else
		{
			Buttons[i].setPosition(Buttons[i - 1].getPosition().x + Buttons[i - 1].getSize().x, YNumber * 100.f);
		}
		Buttons[i].setOutlineThickness(3.f);
		Buttons[i].setOutlineColor(Color::Color(37, 37, 37));

		if (i >= 0 && Buttons[i].getPosition().x + Buttons[i].getSize().x >= window.getSize().x)
		{
			YNumber++;
			Corner = true;
		}
	}
}

void DisplayALL()
{
	for (size_t i = 0; i < Buttons.size(); i++)
	{
		window.draw(Buttons[i]);
		Text ButtonChar;
		ButtonChar.setCharacterSize(Buttons[i].getSize().x / 6);
		ButtonChar.setFont(font);
		ButtonChar.setString(Buttonchars[i]);
		ButtonChar.setPosition(Buttons[i].getPosition().x + Buttons[i].getGlobalBounds().width / 2 - ButtonChar.getGlobalBounds().width,
			Buttons[i].getPosition().y + Buttons[i].getGlobalBounds().height / 2 - ButtonChar.getGlobalBounds().height);

		window.draw(ButtonChar);
	}

	window.draw(HoverShape);

	TextOnDisplay.setPosition(window.getSize().x - TextOnDisplay.getGlobalBounds().width - 10, Buttons[0].getPosition().y - ButtonSize.y / 1.5);

	window.draw(TextOnDisplay);

	Text PreviousText;
	PreviousText.setFont(font);
	PreviousText.setCharacterSize(CHARACTER_SIZE - 10);
	PreviousText.setString(PrevTask);
	PreviousText.setOutlineThickness(2.f);
	PreviousText.setOutlineColor(Color::Black);
	PreviousText.setPosition(window.getSize().x - PreviousText.getGlobalBounds().width - 10, TextOnDisplay.getPosition().y - ButtonSize.y);

	window.draw(PreviousText);
}

void update()
{
	bool HoveredPositiv = false;

	for (size_t i = 0; i < Buttons.size(); i++)
	{
		if (Buttons[i].getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
		{
			HoveredPositiv = true;
			HoverShape.setSize({ Buttons[i].getSize() });
			HoverShape.setFillColor(MouseOnButtonColour);
			HoverShape.setPosition(Buttons[i].getPosition());
			if (Keyboard::isKeyPressed(Keyboard::Enter))
			{
				PrevTask = CurrentTask;

				double result = mathematic::StringToCount(CurrentTask);

				if (mathematic::isInteger(result)) CurrentTask = std::to_string(int(result));
				else CurrentTask = std::to_string(result);
			}
			if (Mouse::isButtonPressed(Mouse::Left) && !MouseHeld)
			{
				MouseHeld = true;

				if (Buttonchars[i] == 'C') CurrentTask = "";

				else if (Buttonchars[i] == '<')
				{
					if (CurrentTask.length() <= 0) break;
					string newTask = "";
					for (size_t i = 0; i < CurrentTask.length() - 1; i++)
						newTask += CurrentTask[i];

					CurrentTask = newTask;
				}
				else if (Buttonchars[i] == '=')
				{
					PrevTask = CurrentTask;

					double result =mathematic::StringToCount(CurrentTask);

					if (mathematic::isInteger(result)) CurrentTask = std::to_string(int(result));
					else CurrentTask = std::to_string(result);
				}
				else
				{
					bool CharPositive = true;

					for (const auto& M : AllMathSymbols)
					{
						if (Buttonchars[i] == M)
						{
							if (CurrentTask.length() <= 0)
							{
								CharPositive = false;
								break;
							}
							for (const auto& K : AllMathSymbols)
							{
								if (CurrentTask[CurrentTask.length() - 1] == K)
									CharPositive = false;
							}
						}
					}
					if (Buttonchars[i] == '.')
						if (CurrentTask.length() <= 0) CharPositive = false;
					if (CharPositive)
						CurrentTask += Buttonchars[i];
				}
				TextOnDisplay.setString(CurrentTask);
			}
			if (!Mouse::isButtonPressed(Mouse::Left)) {
				MouseHeld = false;
			}
		}
	}
	if (!HoveredPositiv) {
		HoverShape.setPosition(window.getSize().x, window.getSize().y);
	}
}

int main()
{
    window.setVerticalSyncEnabled(true);
	font.loadFromFile("FontCalculator.ttf");

	FirstSetUp();


	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) {
				window.close();
			}
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Escape)
				{
					window.close();
				}
			}
		}


		update();

		window.clear(Color(45,45,45));

		DisplayALL();

		window.display();
	}

    return 0;
}