#include <iostream>
#include <cmath>
using namespace std;

bool fibonacci(int numEscolhido)
{
    int primeiro = 0; 
    int segundo = 1; 
    int seguinte = 0; 

    while(seguinte <= numEscolhido)
    {
        if(numEscolhido == seguinte)
        {
            return true;
        }
        seguinte = primeiro + segundo;
        primeiro = segundo;
        segundo = seguinte;
    }
    return false;  
};

main()
{
    int numEscolhido;

    cout << "Insira um valor numerico para verificar se ele esta na sequencia de Fibonacci" << endl;
    cout << "obs: se o valor for negativo, ele se tornara positivo" << endl;
    cin >> numEscolhido;
    numEscolhido = abs(numEscolhido);

    if(fibonacci(numEscolhido))
    {
        cout << "\n\nO numero " << numEscolhido << " esta na sequencia de Fibonacci.";
    }
    else
    {
        cout << "\n\nO numero " << numEscolhido << " nao esta na sequencia de Fibonacci.";
    }
}