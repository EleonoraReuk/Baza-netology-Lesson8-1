#include <iostream>
#include <string>
#include <exception>
using namespace std;

class bad_length : public exception {
public:
	const char* what() const noexcept override {
		return "Вы ввели слово запретной длины! До свидания!";
	}
};

int function(string str, int forbidden_length) {
	int length = str.length();
	if (length == forbidden_length) {
		throw bad_length();
	}
	return length;
}

int main() {
	int forbidden_length;

	cout << "Введите запретную длину: ";
	cin >> forbidden_length;

	cin.ignore();
	string word;

	while (true) {
		cout << "Введите слово: ";
		getline(cin, word);


		try {
			int length = function(word, forbidden_length);
			cout << "Длина слова \"" << word << "\" равна " << length << endl;
		}

		catch (const bad_length& e) {
			cout << e.what() << endl;
			break;
		}
	}
	return 0;

}

