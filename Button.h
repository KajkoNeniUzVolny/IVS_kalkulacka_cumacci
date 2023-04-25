#pragma once
#ifndef _BUTTON_H_
#define _BUTTON_H_
#include<SFML/Graphics.hpp>

class Button
{
public:

	Button(std::string Text, sf::Font& Font, sf::Color Color, sf::Color BorderColor, sf::Color TextColor, 
		sf::Vector2f TextPosition, float BorderThickness, unsigned int SizeOfText);
	Button();
	~Button() { };

	//functions

	bool ButtonColision(sf::Vector2i* MousePosition, sf::Color ChangeColor, sf::RenderWindow* window);
	bool ButtonColision(sf::Vector2i* MousePosition, sf::RenderWindow* window);
	void Display(sf::RenderWindow* window);

	//accessors

	sf::Color GetButtonColour() { return this->ButtonColour; };
	sf::RectangleShape GetButtonShape() { return this->ButtonShape; };
	sf::Text GetButtonText() { return this->ButtonText; };
	sf::Vector2f GetButtonSize() { return this->ButtonSizeDefault; };

private:
	sf::Color ButtonColour;
	int SizeDefault;
	sf::RectangleShape ButtonShape;
	sf::Text ButtonText;
	sf::Vector2f ButtonSizeDefault;

};

#endif // !_BUTTON_H_


