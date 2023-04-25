#ifndef _NAMESPACES_
#define _NAMESPACES_
#include<iostream>
#include<vector>
#include<string>
#include<sstream>

#define AllMathSymbols "*/:x^%^-+"

namespace mathematic {
	using namespace std;

	inline bool isInteger(double Val)
	{
		return int(Val) == Val;
	}

	inline bool isNumber(char c)
	{
		return (c >= '0' && c <= '9');
	}

	inline double MySqrt(double number, double precision)
	{
		double start = 0, end = number;
		double mid;

		double ans  = 0;

		while (start <= end) {
			mid = (start + end) / 2;
			if (mid * mid == number) {
				ans = mid;
				break;
			}

			if (mid * mid < number) {
				start = mid + 1;
				ans = mid;
			}

			else {
				end = mid - 1;
			}
		}

		float increment = 0.1;
		for (int i = 0; i < precision; i++) {
			while (ans * ans <= number) {
				ans += increment;
			}

			ans = ans - increment;
			increment = increment / 10;
		}
		return ans;
	}

	inline double factorial(double value) {
		double return_value = value;
		while (value != 1)
		{
			double hold = value--;
			return_value = return_value * hold;
		}
		return return_value;
	}

	inline double MathCounting(double Value1, double Value2, char Operation)
	{
		if (Operation == '*' || Operation == 'x') {
			return Value1 * Value2;
		}
		if (Operation == ':' || Operation == '/') {
			if (Value2 == 0) {
				return NULL;
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

	inline double StringToNumber(std::string Num)
	{
		double result = 0;
		stringstream ss;
		ss << Num;
		ss >> result;

		return result;
	}

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
						Operators.push_back(task[i]);
					}
				}
			Numbers.push_back(StringToNumber(Helpere));
			if (Factorial_Positive)
			{
				if (Numbers.size() != 1) {
					return 0;
				}
				else
				{
					Numbers.push_back(NULL);
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
