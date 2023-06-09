/** @file Display.h
 *  @brief Prototypy funkci pro display kalkulacky
 *
 *  Obsahuje prototypy funkci displaye
 *  potazmo vsechna makra a globalni promene
 *  
 *
 *  @author David Lauer (xlauer00)
 *  @author Tereza Fortelna (xforte03)
 *  @bug Dosud nejsou zname zadne chyby
 */
#pragma once
#ifndef _DISPLAY_H_
#define _DISPLAY_H_ //makro pro Display.h
#include<string>
#include<SFML/Graphics.hpp>
#include<iostream>

/** @brief Trida Display
* Nachazi se zde konstruktory displaye
* Zaroven jsou zde veskere potrebne funkce pro praci s displayem
* napriklad pro nastaveni textury, nebo zobrazeni textu
* Samotny display se chova jako obycejny sf::Shape
* na ktery se vypisuje text. Tez se jedna o obycejny sf::Text
*/
class Display
{
public:
	/** @brief zakladni konstruktor
	*/
	Display(); 

	/** @brief destruktor displaye
	*/
	~Display();

	/**@brief Konstruktor displaye
	*
	* Jedna se o konstruktor okna 
	* rozsireny o paramtery
	* 
	* @param TextFile Text pro zobrazeni na display
	*/
	Display(const std::string TextFile);

	/**@brief Konstruktor displaye
	*
	* Jedna se o konstruktor okna
	* rozsireny o paramtery
	*
	* @param TextFile Text pro zobrazeni na display
	* @param Size Velikost displaye v okne
	*/
	Display(const std::string TextFile, const sf::Vector2f Size);

	/**@brief Konstruktor displaye
	*
	* Jedna se o konstruktor okna
	* rozsireny o paramtery
	*
	* @param TextFile Text pro zobrazeni na display
	* @param Size Velikost displaye v okne
	* @param Position Pozice displaye v okne
	*/
	Display(const std::string TextFile, const sf::Vector2f Size, const sf::Vector2f Position);

	/** @brief Nastavi texturu pro display
	 *
	 *  Nastavi texturu pro vykresleni u diplaye
	 *  Kdyz neni texture nalezena vypise error a ukonci program
	 *
	 *  @param TextFile Odkaz na texturu ulozenou na disku
	 */
	void SetTexture(const std::string TextFile);

	/** @brief Nastavi texturu pro display a zaroven velikost displaye
	 *
	 *  Nastavi texturu pro vykresleni u diplaye
	 *  Kdyz neni texture nalezena vypise error a ukonci program
	 *  Zaroven nastavi velikost displaye pro vykresleni
	 *
	 *  @param TextFile Odkaz na texturu ulozenou na disku
	 *  @param Size Velikost okna
	 */
	void SetTextureAndSize(const std::string TextFile, const sf::Vector2f Size);

	/** @brief Nastavi pozici displaye v okne
	 *
	 * Nastavi Pozici displaye v okne
	 * Ukotveni je v levem hornim rohu
	 *
	 *  @param Position Pozice displaye v okne
	 */
	void SetPosition(const sf::Vector2f Position);

	/** @brief Slouzi pro ziskani shape displaye
	 *
	 *  @return Ukazetel na shape displaye
	 */
	sf::RectangleShape* GetShape() { return &this->Shape; }

	/** @brief Slouzi pro ziskani textury displaye
	 *
	 *
	 *  @return Ukazatel na texturu displaye
	 */
	sf::Texture* GetTexture() { return &this->Texture; }


private:
	/** @brief Shape displaye
	*/
	sf::RectangleShape Shape;
	/** @brief Textura displaye
	*/
	sf::Texture Texture;
};



#endif // !_DISPLAY_H_
/*** Konec souboru Display.h ***/



