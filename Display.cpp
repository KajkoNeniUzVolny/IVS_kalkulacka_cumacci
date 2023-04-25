/** @file Display.cpp
 *  @brief Zavadi funkcnost displaye kalkulacky
 *
 *
 *  @author David Lauer (xlauer00)
 *  @author Pavol Sloboda (xslobo08)
 *  @bug Dosud nejsou zname zadne chyby
 */
#include "Display.h"

 /** @brief Konstruktor dispaye
 */
Display::Display()
{
}

/** @brief Destruktor displaye
*/
Display::~Display()
{
}

/**@brief Konstruktor displaye
*
* Jedna se o konstruktor okna
* rozsireny o paramtery
*
* @param TextFile Text pro zobrazeni na display
*/
Display::Display(const std::string TextFile)
{
	if (this->Texture.loadFromFile(TextFile))
	{
		std::cerr << "Problem with loading file:" << __FILE__ << std::endl;
	}
	this->Shape.setTexture(&this->Texture);
}

/**@brief Konstruktor displaye
*
* Jedna se o konstruktor okna
* rozsireny o paramtery
*
* @param TextFile Text pro zobrazeni na display
* @param Size Velikost displaye v okne
*/
Display::Display(const std::string TextFile, const sf::Vector2f Size)
{
	if (this->Texture.loadFromFile(TextFile))
	{
		std::cerr << "Problem with loading file:" << __FILE__ << std::endl;
	}
	this->Shape.setTexture(&this->Texture);
	this->Shape.setSize(Size);
}

/**@brief Konstruktor displaye
*
* Jedna se o konstruktor okna
* rozsireny o paramtery
*
* @param TextFile Text pro zobrazeni na display
* @param Size Velikost displaye v okne
* @param Position Pozice displaye v okne
*/
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

/** @brief Nastavi texturu pro display
 *
 *  Nastavi texturu pro vykresleni u diplaye
 *  Kdyz neni texture nalezena vypise error a ukonci program
 *
 *  @param TextFile Odkaz na texturu ulozenou na disku
 */
void Display::SetTexture(const std::string TextFile)
{
	if (this->Texture.loadFromFile(TextFile))
	{
		std::cerr << "Problem with loading file:" << __FILE__ << std::endl;
	}
	this->Shape.setTexture(&this->Texture);
}

/** @brief Nastavi texturu pro display a zaroven velikost displaye
 *
 *  Nastavi texturu pro vykresleni u diplaye
 *  Kdyz neni texture nalezena vypise error a ukonci program
 *  Zaroven nastavi velikost displaye pro vykresleni
 *
 *  @param TextFile Odkaz na texturu ulozenou na disku
 *  @param Size Velikost okna
 */
void Display::SetTextureAndSize(const std::string TextFile, const sf::Vector2f Size)
{
	if (this->Texture.loadFromFile(TextFile))
	{
		std::cerr << "Problem with loading file:" << __FILE__ << std::endl;
	}
	this->Shape.setTexture(&this->Texture);
	this->Shape.setSize(Size);
}

/** @brief Nastavi pozici displaye v okne
 *
 * Nastavi Pozici displaye v okne
 * Ukotveni je v levem hornim rohu
 *
 *  @param Position Pozice displaye v okne
 */
void Display::SetPosition(const sf::Vector2f Position)
{
	this->Shape.setPosition(Position);
}
/*** Konec souboru Display.cpp ***/