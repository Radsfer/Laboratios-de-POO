#ifndef __SISTEMA_H__
#define __SISTEMA_H__

#include <bits/stdc++.h>

using namespace std;

class Satelite
{
private:
    string nomeSatelite;

public:
    string getNomeSatelite();

    void setNomeSatelite(string nomeSatelite);

    Satelite(string nomeSatelite);
};

class Planeta
{
private:
    string estrelaOrbita;
    string nomePlaneta;
    string massaPlaneta;
    vector<Satelite> satelites;

public:
    string getEstrelaOrbita();
    string getNomePlaneta();
    string getMassaPlaneta();
    vector<Satelite> &getSatelite();

    void setEstrelaOrbita(string nomeEstrela);
    void setNomePlaneta(string planeta);
    void setMassaPlaneta(string massaPlaneta);

    void adicionarSatelite(Satelite &satelite);

    // Dentro da classe Planeta, adicione o método estático parseLinha
    static Planeta parseLinha(string linha);

    void imprimirInformacoes();
    void listarSatelites();

    Planeta(string nomePlaneta, string massaPlaneta, string estrela);
};
class SistemaEstelar
{
private:
    string nomeEstrela;
    vector<Planeta> planetas;

public:
    string getNomeEstrela();
    vector<Planeta> &getPlaneta();

    void setNomeEstrela(string estrela);

    void adicionarPlaneta(Planeta &planeta);
    void verificarSePlanetaEIdentico(Planeta &planeta);
    SistemaEstelar(string nomeEstrela);
};

#endif