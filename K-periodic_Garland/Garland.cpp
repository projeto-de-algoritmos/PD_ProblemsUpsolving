#include<bits/stdc++.h>

using namespace std;

void solucao()
{
    // variaveis indicadas pelo problema
    int n, k; 
    string LEDs;           

    cin >> n >> k >> LEDs; // n = tamanho e k = periodo dos LEDs necessario

    vector<int> prefix(n+2), calcula(n+2); //um vetor para prefix e outro para o calcular a solução da progamação dinamica

    for(int i=1; i<=n; i++)//soma dos prefixos
    {
        prefix[i] = prefix[i-1];
        if(LEDs[i-1] == '1') prefix[i]++;
    }

    int resposta = prefix[n]; // inicialização da resposta

    for(int i=1; i<=n; i++)// Calculo dos resultados da programacao dinamica
    {
        int bitFlip;
        if(LEDs[i-1] == '1') bitFlip = 0;
        else bitFlip = 1;

        calcula[i] = bitFlip + prefix[i-1];

        if(i >= k)
        {
            calcula[i] = min(calcula[i], bitFlip + calcula[i-k] + prefix[i-1] - prefix[i-k]);
        } 

        resposta =  min(resposta, calcula[i] + prefix[n] - prefix[i]);
    }

    cout << resposta << endl;
}

int main()
{
    int t;// variavel para os casos de testes, indicada pelo problema

    cin >> t;

    for(int j=0; j<t; j++)
    {
        solucao();
    }
    
    return 0;
}