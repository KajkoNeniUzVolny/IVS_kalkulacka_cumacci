#pragma once
#ifndef _DISPLAY_H_
#define _DISPLAY_H_
#include<string>
#include<SFML/Graphics.hpp>
#include<iostream>


class Display
{
public:
	Display();
	~Display();

	Display(const std::string TextFile);
	Display(const std::string TextFile, const sf::Vector2f Size);
	Display(const std::string TextFile, const sf::Vector2f Size, const sf::Vector2f Position);

	void SetTexture(const std::string TextFile);
	void SetTextureAndSize(const std::string TextFile, const sf::Vector2f Size);
	void SetPosition(const sf::Vector2f Position);

	sf::RectangleShape* GetShape() { return &this->Shape; }
	sf::Texture* GetTexture() { return &this->Texture; }


private:
	sf::RectangleShape Shape;
	sf::Texture Texture;
};



#endif // !_DISPLAY_H_



