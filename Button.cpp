#include "Button.h"

Button::Button(std::string Text, sf::Font& Font, sf::Color Color, sf::Color BorderColor, sf::Color TextColor, sf::Vector2f TextPosition, float BorderThickness, unsigned int SizeOfText)
{
	this->ButtonText.setPosition(TextPosition);
	this->ButtonText.setCharacterSize(SizeOfText);
	this->ButtonText.setString(Text);
	this->ButtonText.setFont(Font);
	this->ButtonText.setFillColor(TextColor);
	this->ButtonText.setOutlineThickness(BorderThickness);
	this->ButtonText.setOutlineColor(BorderColor);

	this->ButtonShape.setFillColor(Color);
	this->ButtonShape.setPosition(this->ButtonText.getPosition().x, this->ButtonText.getPosition().y + this->ButtonText.getGlobalBounds().height / 10);
	this->ButtonShape.setSize(sf::Vector2f(this->ButtonText.getGlobalBounds().width, this->ButtonText.getGlobalBounds().height));

	this->ButtonSizeDefault = this->ButtonShape.getSize();
}

Button::Button()
{
}

bool Button::ButtonColision(sf::Vector2i* MousePosition, sf::Color ChangeColor, sf::RenderWindow* window)
{ 
	if (this->ButtonShape.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*window))))
	{
		this->ButtonShape.setFillColor(ChangeColor);
		this->ButtonText.setCharacterSize(SizeDefault + SizeDefault / 10);
		this->ButtonShape.setSize(sf::Vector2f(ButtonSizeDefault.x + ButtonSizeDefault.x / 10, ButtonSizeDefault.y + ButtonSizeDefault.y / 10));
		return true;
	}

	this->ButtonText.setCharacterSize(SizeDefault);
	this->ButtonShape.setFillColor(ButtonColour);
	this->ButtonShape.setSize(ButtonSizeDefault);
	return false;
}

bool Button::ButtonColision(sf::Vector2i* MousePosition, sf::RenderWindow* window)
{
	if (this->ButtonShape.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*window))))
	{
		return true;
	}
	return false;
}

void Button::Display(sf::RenderWindow* window)
{
	window->draw(this->ButtonShape);
	window->draw(this->ButtonText);
}