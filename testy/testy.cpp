#include <iostream>
#include<string>
#include<cstdlib>
#include<sstream>
#include <fstream>

using namespace std;

int test(string input, double output) {
	ifstream file("text.txt");
	system(("./kaukulacka_pro_cumacky \"" + input + "\" > temp.txt").c_str());

	double result;

	ifstream fin("temp.txt");

	fin >> result;

	system("rm temp.txt");

	cout << "text :" << input << " vysledek :" << result << endl;
	if (result == output)
	{
		cout << "Test approved " << input << result << endl;
		return 1;
	}
	else {
		cout << "Test failed; " << "Vstup: " << input << " Predpoklad: " << output << " Vysledek: " << result << endl;
		return 0;
	}
}

int main()
{
	int pocet_testu = 18;
	int test_dobre = 0;
	test_dobre += test("4+5=", 9);
	test_dobre += test("20-8=", 12);
	test_dobre += test("1-8=", -7);
	test_dobre += test("500:2=", 250);
	test_dobre += test("4*12=", 48);
	test_dobre += test("5!=", 120);
	test_dobre += test("5^3=", 125);
	test_dobre += test("4s16=", 2);
	test_dobre += test("31%4=", 3);
	test_dobre += test("6:2*(1+2)=", 9);
	test_dobre += test("5997:0=", 0);
	test_dobre += test("2^5+5*8*(50-48)=", 112);
	test_dobre += test("5-2s81*5*(1*2)=", -85);
	test_dobre += test("80+0-45=", 35);
	test_dobre += test("(6:(0-2)*(0-2))^2=", 36);
	test_dobre += test("5^(1*(0-2))=", 0.04);
	test_dobre += test("0.05*(0-10)=", -0.5);
	test_dobre += test("16^(0-0.5)=", 0.25);
	cout << "Testy dobre: " << test_dobre << " z poctu testu: " << pocet_testu << endl;
	return 0;
}

