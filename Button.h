#pragma once
/** @file Button.h
 *  @brief Prototypy funkci pro tlacitka kalkulacky
 *
 *  Obsahuje prototypy funkci pro tlacitka
 *  potazmo vsechna makra a globalni promene
 *
 *
 *  @author David Lauer (xlauer00)
 *  @author Pavol Sloboda (xslobo08)
 *  @bug Dosud nejsou zname zadne chyby
 */
#ifndef _BUTTON_H_
#define _BUTTON_H_ //makro pro Button.h
#include<SFML/Graphics.hpp>

/**
* @brief Trida tlacitka
* 
* Nachazi se zde veskere konstruktory tlacitka
* zaroven funkce pro samotnou praci s tlacitkem
* jako hledani kolize a nebo mneneni barvy
* Tlacitko je zalozene na objektu sf::Shape
*/
class Button
{
public:

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
	Button(std::string Text, sf::Font& Font, sf::Color Color, sf::Color BorderColor, sf::Color TextColor, 
		sf::Vector2f TextPosition, float BorderThickness, unsigned int SizeOfText);
	/**
	* @brief Zakladni konstruktor tlacitka
	*/
	Button();
	/**
	* @brief Destruktor tlacitka
	*/
	~Button() { };

	//functions
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
	bool ButtonColision(sf::Vector2i* MousePosition, sf::Color ChangeColor, sf::RenderWindow* window);
	/** @brief Detekce kolize s tlacitkem
	*
	* Detekuje kolizi mezi mysi a tlaciitkem
	*
	* @param MousePosition Ukazatel na pozici mysi v okne
	* @param window Ukazatel na aktualni okno
	*
	* @return True, kdyz nastala kolize, jinak false
	*/
	bool ButtonColision(sf::Vector2i* MousePosition, sf::RenderWindow* window);
	/** @brief Vykresleni tlacitka do okna
	*
	* @param window Ukazatel na aktualni okno
	*
	* @return Void
	*/
	void Display(sf::RenderWindow* window);

	//accessors

	/** @brief Ziskani barvy tlacitka 
	* 
	*  @return Barva tlacitka
	*/
	sf::Color GetButtonColour() { return this->ButtonColour; };
	/** @brief Ziskani shape tlacitka
	*
	*  @return Shape tlacitka
	*/
	sf::RectangleShape GetButtonShape() { return this->ButtonShape; };
	/** @brief Ziskani textu na tlacitku
	*
	*  @return Text na tlacitku
	*/
	sf::Text GetButtonText() { return this->ButtonText; };
	/** @brief Ziskani velikosti tlacitka
	*
	*  @return Velikost tlacitka
	*/
	sf::Vector2f GetButtonSize() { return this->ButtonSizeDefault; };

private:
	sf::Color ButtonColour; //Barva tlacitka
	int SizeDefault; //Zakladni velikost tlacitka
	sf::RectangleShape ButtonShape; //Shape tlacitka
	sf::Text ButtonText; //Text na tlacitku
	sf::Vector2f ButtonSizeDefault; //Zakladni velikost tlacitka pro obe osy

};

#endif // !_BUTTON_H_


