/** @file Button.cpp
 *  @brief Zavadeni funkcnosti tlacitek kalkulacky
 *
 *  @author Tereza Fortelna (xforte03)
 *  @author Pavol Sloboda (xslobo08)
 *  @bug Dosud nejsou zname zadne chyby
 */
#include "Button.h"

 /** @brief Konstruktor tlacitka s parametry
 *
 * Tento konstruktor slouzi pro kompletni nastaveni tlacitka
 * zde se nastavuji veskere potrebne parametry
 * tlacitko se chova jako obycejny objekt typu sf::Shape
 * vzhled tlacitka si lze libovolne prizpusobit
 *
 * @param Text Text pro zobrazeni na tlacitko
 * @param Font Ukazatel na font pro zhled textu
 * @param Color Zakladni barva tlacitka
 * @param BorderColor Barva okraje tlacitka
 * @param TextColor Barva text tlacitka
 * @param TextPosition Pozicce textu na tlacitku
 * @param Border Thickness Tloustka okraje tlacitka
 * @param SizeOfText Velikost textu na tlacitku
 *
 */
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

/**
* @brief Zakladni konstruktor tlacitka
*/
Button::Button()
{
}

/** @brief Detekce kolize s tlacitkem
*
* Detekuje kolizi mezi mysi a tlaciitkem
* meni barvu v zavislosti na kolizi
*
* @param MousePosition Ukazatel na pozici mysi v okne
* @param ChangeColor Barva, na kterou se zemeni tlacitko pri kolizi
* @param window Ukazatel na aktualni okno
*
* @return True, kdyz nastala kolize, jinak false
*/
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

/** @brief Detekce kolize s tlacitkem
*
* Detekuje kolizi mezi mysi a tlaciitkem
*
* @param MousePosition Ukazatel na pozici mysi v okne
* @param window Ukazatel na aktualni okno
*
* @return True, kdyz nastala kolize, jinak false
*/
bool Button::ButtonColision(sf::Vector2i* MousePosition, sf::RenderWindow* window)
{
	if (this->ButtonShape.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*window))))
	{
		return true;
	}
	return false;
}

/** @brief Vykresleni tlacitka do okna
*
* @param window Ukazatel na aktualni okno
*
* @return Void
*/
void Button::Display(sf::RenderWindow* window)
{
	window->draw(this->ButtonShape);
	window->draw(this->ButtonText);
}
/*** Konec souboru Button.cpp ***/