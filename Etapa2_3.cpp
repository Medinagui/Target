#include <iostream>
#include <fstream>
#include "./jsonHelp/json-develop/single_include/nlohmann/json.hpp"
using json = nlohmann::json;
using namespace std;

main()
{
    json dados;
    ifstream arquivo("./material apoio/dados.json");
    arquivo.open("./material apoio/dados.json");
    arquivo >> dados;
    arquivo.close();

    int menorDia;
    int maiorDia;
    int menorFat = 0;
    int maiorFat = 0;
    float soma = 0;
    float contaDia = 0;
    int DiasFaturamentoMaior = 0;

    for(auto& dia : dados)
    {
        //verifica maior e menor faturamento e abriga seus dias
        if((dia["valor"] > maiorFat) && (menorFat == 0))
        {
            menorFat = dia["valor"];
            menorDia = dia["dia"];
            maiorFat = dia["valor"];
            maiorDia = dia["dia"];
        }
        else if(dia["valor"] > maiorFat)
        {
            maiorFat = dia["valor"];
            maiorDia = dia["dia"];
        }
        else if((dia["valor"] < menorFat) && (dia["valor"] != 0))
        {  
            menorFat = dia["valor"];
            menorDia = dia["dia"];
        }

        //somar os faturamentos e contar os dias validos para a media

        if(dia["valor"] != 0)
        {
            soma += dia["valor"].get<float>();
            contaDia += 1;
        }
    }

    float mediaMensal = (soma/contaDia);

    for(auto& dia : dados)
    {
        if(dia["valor"] > mediaMensal)
        {
            DiasFaturamentoMaior += 1;
        }
    }

    cout << "Eis as informacoes obtidas pelos dados: " << endl;
    cout << "\nO dia com o MENOR faturamento foi o dia " << menorDia 
            << " com o faturamento de " << menorFat << endl;
    cout << "\nO dia com o MAIOR faturamento foi o dia " << maiorDia 
            << " com o faturamento de " << maiorFat << endl;
    cout << "\nE a quantidade de dias que tiveram um faturamento diario maior do que o mensal e de " << DiasFaturamentoMaior << endl;

}