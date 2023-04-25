#include "Display.h"

Display::Display()
{
}

Display::~Display()
{
}

Display::Display(const std::string TextFile)
{
	if (this->Texture.loadFromFile(TextFile))
	{
		std::cerr << "Problem with loading file:" << __FILE__ << std::endl;
	}
	this->Shape.setTexture(&this->Texture);
}

Display::Display(const std::string TextFile, const sf::Vector2f Size)
{
	if (this->Texture.loadFromFile(TextFile))
	{
		std::cerr << "Problem with loading file:" << __FILE__ << std::endl;
	}
	this->Shape.setTexture(&this->Texture);
	this->Shape.setSize(Size);
}

Display::Display(const std::string TextFile, const sf::Vector2f Size, const sf::Vector2f Position)
{
	if (this->Texture.loadFromFile(TextFile))
	{
		std::cerr << "Problem with loading file:" << __FILE__ << std::endl;
	}
	this->Shape.setTexture(&this->Texture);
	this->Shape.setSize(Size);
	this->Shape.setPosition(Position);
}

void Display::SetTexture(const std::string TextFile)
{
	if (this->Texture.loadFromFile(TextFile))
	{
		std::cerr << "Problem with loading file:" << __FILE__ << std::endl;
	}
	this->Shape.setTexture(&this->Texture);
}

void Display::SetTextureAndSize(const std::string TextFile, const sf::Vector2f Size)
{
	if (this->Texture.loadFromFile(TextFile))
	{
		std::cerr << "Problem with loading file:" << __FILE__ << std::endl;
	}
	this->Shape.setTexture(&this->Texture);
	this->Shape.setSize(Size);
}

void Display::SetPosition(const sf::Vector2f Position)
{
	this->Shape.setPosition(Position);
}
