#include "Sistema.hpp"

string Satelite::getNomeSatelite()
{
    return nomeSatelite;
};

void Satelite::setNomeSatelite(string nomeSatelite)
{
    this->nomeSatelite = nomeSatelite;
};

Satelite::Satelite(string nomeSatelite)
{
    setNomeSatelite(nomeSatelite);
};

string Planeta::getEstrelaOrbita()
{
    return estrelaOrbita;
};
string Planeta::getNomePlaneta()
{
    return nomePlaneta;
};
string Planeta::getMassaPlaneta()
{
    return massaPlaneta;
};
vector<Satelite> &Planeta::getSatelite()
{
    return satelites;
};

void Planeta::setNomePlaneta(string nomePlaneta)
{
    this->nomePlaneta = nomePlaneta;
};
void Planeta::setMassaPlaneta(string massaPlaneta)
{
    this->massaPlaneta = massaPlaneta;
};
void Planeta::setEstrelaOrbita(string estrela)
{
    this->estrelaOrbita = estrela;
};

void Planeta::adicionarSatelite(Satelite &satelite)
{
    satelites.push_back(satelite);
};

void Planeta::listarSatelites()
{
    if (satelites.size() > 0)
    {
        for (int i = 0; i < satelites.size(); i++)
        {
            cout << "Nome do satélite: " << satelites[i].getNomeSatelite() 
            << "\n";
        }
    }
    else
    {
        cout << "Não possui satélites\n";
    }
};

void Planeta::imprimirInformacoes()
{
    cout << "Planeta: " << nomePlaneta << "\n";
    cout << "Massa do planeta: " << massaPlaneta << "\n";
    cout << "Estrela em que orbita: " << estrelaOrbita << "\n";
    listarSatelites();
};

Planeta::Planeta(string nomePlaneta, string massaPlaneta, string estrela)
{
    setNomePlaneta(nomePlaneta);
    setMassaPlaneta(massaPlaneta);
    setEstrelaOrbita(estrela);
};
Planeta Planeta::parseLinha(string linha)
{
    stringstream ss(linha);
    string nomePlaneta, massaPlaneta, estrela, quantidadeLuas;

    // Extraia os valores da linha
    getline(ss, nomePlaneta, ',');    // Supondo que os valores são separados por vírgula
    getline(ss, massaPlaneta, ',');
    getline(ss, estrela, ',');
    getline(ss, quantidadeLuas, ',');
    
    // Crie um objeto Planeta com os valores extraídos
    Planeta planeta(nomePlaneta, massaPlaneta, estrela);

    // Agora, leia e adicione as luas ao Planeta
    int numLuas;
    try {
        numLuas = stoi(quantidadeLuas);
    } catch (const invalid_argument& e) {
        cerr << "Erro ao converter quantidade de luas para int: " << e.what() << endl;
        return planeta; // Retorna o Planeta original sem luas
    }

    for (int i = 0; i < numLuas; i++) {
        string nomeLua;
        getline(ss, nomeLua, ',');
        Satelite lua(nomeLua);
        planeta.adicionarSatelite(lua);
    }

    return planeta;
}


string SistemaEstelar::getNomeEstrela()
{
    return nomeEstrela;
};
vector<Planeta> &SistemaEstelar::getPlaneta()
{
    return planetas;
};

void SistemaEstelar::setNomeEstrela(string nomeEstrela)
{
    this->nomeEstrela = nomeEstrela;
};

void SistemaEstelar::adicionarPlaneta(Planeta &planeta)
{
    planetas.push_back(planeta);
};

void SistemaEstelar::verificarSePlanetaEIdentico(Planeta &planeta)
{
    int contador = 0;
    if (planetas.size() > 0)
    {
        for (int i = 0; i < planetas.size(); i++)
        {

            if (planeta.getNomePlaneta() == planetas[i].getNomePlaneta())
            {
                contador++;
            }
        }
        if (contador <= 1)
        {
            cout << "Não é igual a nenhum planeta\n";
        }
        else
        {
            cout << "Tem " << contador << " planetas iguais a " << planeta.getNomePlaneta() << " nesse sistema estelar\n";
        }
    }
    else
    {
        cout << "Esse é o primeiro planeta!\n";
    }
};

SistemaEstelar::SistemaEstelar(string nomeEstrela)
{
    setNomeEstrela(nomeEstrela);
};
