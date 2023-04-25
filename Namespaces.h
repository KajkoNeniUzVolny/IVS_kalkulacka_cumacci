/** @file Namespaces.h
 *  @brief Prototypy funkci pro praci se zakladnimi matematickymi operacemi
 *
 *  Obsahuje prototypy funkci matematyckych operaci
 *  potazmo vsechna makra a globalni promene
 *
 *
 *  @author Tereza Fortelna (xforte03)
 *  @author Pavol Sloboda (xslobo08)
 *  @bug Dosud nejsou zname zadne chyby
 */
#ifndef _NAMESPACES_
#define _NAMESPACES_
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<cmath>

#define AllMathSymbols "*/:x^%^-+"

/**
* @brief trida matematika
*
* Nachazi se zde veskere funkce pro vyuzivani zakladnich matematickych operaci, zavorek a
* 
*/
namespace mathematic {
	using namespace std;

	/** @brief Urceni zda je Val integer
	*
	* @param Val Znak, u ktereho je treba zjistit zda je integer
	*
	* @return True, pokud Val je integer
	*/
	inline bool isInteger(double Val)
	{
		return int(Val) == Val;
	}

	/** @brief Urceni zda je c cislo
	*
	* @param c Znak, u ktereho je treba zjistit zda je cislo od 1 do 9
	*	
	* @return False, pokud c neni cislo od 1 do 9
	*/
	inline bool isNumber(char c)
	{
		return (c >= '0' && c <= '9');
	}

	/** @brief Vypocet odmocniny
	*
	* @param number Cislo, ktere chceme odmocnit
	* @param precision Cislo, kterym odmocnujeme
	*
	* @return Hodnota odmocneneho cisla
	*/
	inline double MySqrt(double number, double precision)
	{
		return pow(number,(1/precision));
	}

	/** @brief Vypocet faktorialu
	*
	* @param value Cislo, jehoz faktorial je pocitan
	*
	* @return Hodnota faktorialu 
	*/
	inline double factorial(double value) {
		double return_value = value;
		while (value != 1)
		{
			value--;
			return_value = return_value * value;
		}
		return return_value;
	}

	/** @brief Zavadeni funkcnosti zakladnich matematickych operaci
	* 
	* Funkce zavadi operace dvou cisel nasobeni, deleni, scitani, odcitani, umocnovani, odmocnovani, faktorial a zbytek po deleni
	*
	* @param Value1 Prvni cislo vypoctu
	* @param Value2 Druhe cislo vypoctu
	*
	* @return Vysledek vypoctu
	*/
	inline double MathCounting(double Value1, double Value2, char Operation)
	{
		if (Operation == '*' || Operation == 'x') {
			return Value1 * Value2;
		}
		if (Operation == ':' || Operation == '/') {
			if (Value2 == 0) {
				return 0;
			}
			return Value1 / Value2;
		}
		if (Operation == '+') {
			return Value1 + Value2;
		}
		if (Operation == '-') {
			return Value1 - Value2;
		}
		if (Operation == '^') {
			return pow(Value1, Value2);
		}
		if (Operation == 's')
		{
			return MySqrt(Value2, Value1);
		}
		if (Operation == '!')
		{
			return factorial(Value1);
		}
		if (Operation == '%') {
			if (static_cast<int>(Value2) == 0)
			{
				return EXIT_FAILURE;
			}
			return  static_cast<int>(Value1) % static_cast<int>(Value2);
		}
		else {
			abort();
		}
	}

	/** @brief Prevedeni retezce na cislo
	*
	* @return Prevedeny retezec na cislo
	*/
	inline double StringToNumber(std::string Num)
	{
		double result = 0;
		stringstream ss;
		ss << Num;
		ss >> result;

		return result;
	}

	/** @brief Funkce zavadi spravnou funkcnost zavorek
	*
	* @param task Pole prvku aritmetickeho prikladu, ktery obsahuje zavorky
	* @param task_position Pozice, na ktere byla nalezena zavorka 
	*
	* @return Hodnotu zavorky
	*/
	inline double StringToCountForBrackets(std::string task, size_t* task_position)
	{
		std::vector<double> Numbers;
		std::string Operators;
		bool Factorial_Positive = false;
		{
			std::string Helper = "";
			int position_shift = *task_position;
			position_shift++;
			for (size_t i = position_shift; i < task.length(); i++)
				if (task[i] != ' ')
				{
					if (task[i] == '(')
					{
						Numbers.push_back(StringToCountForBrackets(task, &i));
					}
					else if (task[i] == ')')
					{
						Numbers.push_back(StringToNumber(Helper));
						*task_position = i;
						goto label;
					}
					else if (isNumber(task[i]) || task[i] == '.')
					{
						Helper.push_back(task[i]);
					}
					else if (task[i] == '!')
					{
						Factorial_Positive = true;
						Operators.push_back(task[i]);
					}
					else if (task[i] == '+' || task[i] == '-' || task[i] == '/' || task[i] == ':' || task[i] == '*' ||
						task[i] == 'x' || task[i] == '^' || task[i] == '%' || task[i] == 's')
					{
						Operators.push_back(task[i]);
						if (Helper != "")
						{
							Numbers.push_back(StringToNumber(Helper));
							Helper = "";
						}
					}
				}
		}
	label:
		do
		{
			if (Numbers.size() == 0)
			{
				return Numbers[0];
			}
			std::string MathematicalOperations = "";

			for (size_t i = 0; i < Operators.length(); i++)
			{
				if (Operators[i] == '^' || Operators[i] == '%') {
					MathematicalOperations = "^%";
					break;
				}
				if (Operators[i] == '*' || Operators[i] == '/' || Operators[i] == ':' || Operators[i] == 'x') {
					MathematicalOperations = "*/:x^";
				}
			}
			if (MathematicalOperations == "") {
				MathematicalOperations = "+-";
			}
			for (size_t i = 0; i < Operators.size(); i++)
			{
				for (size_t j = 0; j < MathematicalOperations.length(); j++)
					if (Operators[i] == MathematicalOperations[j])
					{
						double Val = MathCounting(Numbers[i], Numbers[i + 1], Operators[i]);
						Operators.erase(Operators.begin() + i);
						Numbers.erase(Numbers.begin() + i);
						Numbers.erase(Numbers.begin() + i);
						Numbers.insert(Numbers.begin() + i, Val);
						break;
					}
			}

		} while (!Operators.empty());
		return Numbers[0];
	}

	/** @brief Funkce pocita hodnotu matematickeho prikladu obsazenem v retezci
	*
	* @param task Retezec obsahujici pocitany matematicky priklad
	*
	* @return Hodnotu pocitaneho prikladu
	*/
	inline double StringToCount(std::string task)
	{
		std::vector<double> Numbers;
		std::string Operators;
		bool Factorial_Positive = false;
		{
			std::string Helpere = "";

			for (size_t i = 0; i < task.length(); i++)
				if (task[i] != ' ')
				{
					if (task[i] == '(')
					{
						Numbers.push_back(StringToCountForBrackets(task, &i));
					}
					else if (isNumber(task[i]) || task[i] == '.')
					{
						Helpere.push_back(task[i]);
					}
					else if (task[i] == '+' || task[i] == '-' || task[i] == '/' || task[i] == ':' || task[i] == '*' ||
						task[i] == 'x' || task[i] == '^' || task[i] == '%' || task[i] == 's' || task[i] == '!')
					{
						Operators.push_back(task[i]);
						if (Helpere != "")
						{
							Numbers.push_back(StringToNumber(Helpere));
							Helpere = "";
						}
					}
					if (task[i] == '!')
					{
						Factorial_Positive = true;
					}
				}
			Numbers.push_back(StringToNumber(Helpere));
			if (Factorial_Positive)
			{
				if (Numbers.size() > 2) {
					return 0;
				}
			}
		}
		do
		{
			if (Numbers.size() == 0)
			{
				return Numbers[0];
			}
			std::string MathematicalOperations = "";

			for (size_t i = 0; i < Operators.length(); i++)
			{
				if (Operators[i] == '^' || Operators[i] == '%' || Operators[i] == 's' || Operators[i] == '!') {
					MathematicalOperations = "^%s!";
					break;
				}
				if (Operators[i] == '*' || Operators[i] == '/' || Operators[i] == ':' || Operators[i] == 'x') {
					MathematicalOperations = "*/:x^";
				}
			}
			if (MathematicalOperations == "") {
				MathematicalOperations = "+-";
			}
			for (size_t i = 0; i < Operators.size(); i++)
			{
				for (size_t j = 0; j < MathematicalOperations.length(); j++)
					if (Operators[i] == MathematicalOperations[j])
					{
						double Val = MathCounting(Numbers[i], Numbers[i + 1], Operators[i]);
						Operators.erase(Operators.begin() + i);
						Numbers.erase(Numbers.begin() + i);
						Numbers.erase(Numbers.begin() + i);
						Numbers.insert(Numbers.begin() + i, Val);
						break;
					}
			}
		} while (!Operators.empty());
		return Numbers[0];
	}
}
#endif // !_NAMESPACES_
/*** Konec souboru Namespaces.h ***/
