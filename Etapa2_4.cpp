#include <iostream>
#include <string>
using namespace std;

class Estado
{
    public:
        string sigla;
        float faturamento;
    void exibirPercentual(float total)
    {
        cout << "Para o estado " << sigla << " temos o percentual de faturamento de " 
        << ((faturamento/total) * 100) << "%.\n" << endl;
    }
};

main()
{
    Estado distribuidora[5];

    distribuidora[0].sigla = "SP";
    distribuidora[0].faturamento = 67836.43;

    distribuidora[1].sigla = "RJ";
    distribuidora[1].faturamento = 36678.66;

    distribuidora[2].sigla = "MG";
    distribuidora[2].faturamento = 29229.88;

    distribuidora[3].sigla = "ES";
    distribuidora[3].faturamento = 27165.48;

    distribuidora[4].sigla = "Outros";
    distribuidora[4].faturamento = 19849.53;

    float somaFaturamento = 0;

    for(int i = 0; i < 5; i++)
    {
        somaFaturamento += distribuidora[i].faturamento;
    }

    for(int i = 0; i < 5; i++)
    {
        distribuidora[i].exibirPercentual(somaFaturamento);
    }

}