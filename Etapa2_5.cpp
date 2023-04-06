#include <iostream>
#include <string>

using namespace std;

int main() {
   string palavra;
   cout << "Digite uma palavra: ";
   getline(cin, palavra);

   int tamanhoPalavra = palavra.length();

   for (int i = 0; i < tamanhoPalavra/2; i++) {
      char temp = palavra[i];
      palavra[i] = palavra[tamanhoPalavra-i-1];
      palavra[tamanhoPalavra-i-1] = temp;
   }

   cout << "A palavra invertida fica assim: " << palavra << endl;
}
