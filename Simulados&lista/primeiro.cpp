#include <bits/stdc++.h>

using namespace std;

class PessoaJuridica{
    private:
    string nomeFantasia;
    string cnpj;
    string endereco;
    string dono;

    public:
    string getNomeFantasia(){
        return nomeFantasia;
    }

    void setNomeFantasia(string nome){
        this->nomeFantasia=nome;
    }

    string getCnpj(){
        return cnpj;
    }

    void setCnpj(string cnpj){
        this->cnpj=cnpj;
    }

    string getEndereco(){
        return endereco;
    }

    void setEndereco(string endereco){
        this->endereco=endereco;
    }

    string getDono(){
        return dono;
    }

    void setDono(string nome){
        this->dono=nome;
    }
    
    PessoaJuridica(string dono, string nomeFantasia, string cnpj, string endereco){
        setDono(dono);
        setNomeFantasia(nomeFantasia);
        setCnpj(cnpj);
        setEndereco(endereco);
    }

};

class PessoaFisica{
    private:
    string nome;
    string cpf;
    string endereco;
    vector <PessoaJuridica> empresas;

    public:
    string getNome(){
        return nome;
    }

    void setNome(string nome){
        this->nome = nome;
    }

    string getCpf(){
        return cpf;
    }

    void setCpf(string cpf){
        this->cpf = cpf;
    }

    string getEndereco(){
        return endereco;
    }

    void setEndereco(string endereco){
        this->endereco=endereco;
    }

    void adicionarEmpresas(PessoaJuridica& empresa){
        empresas.push_back(empresa);
    }
    void mostrarEmpresas(){
        if(empresas.size()>0){
        for(int i=0;i<empresas.size();i++){
            cout<<"Nome da empresa: "<<empresas[i].getNomeFantasia()<<"\n";
            cout<<"CNPJ: "<<empresas[i].getCnpj()<<"\n";
        }
        }else{
            cout<<"Essa pessoa não tem empresas registradas\n";
        }
    }

    PessoaFisica(string nome, string cpf, string endereco){
        setNome(nome);
        setCpf(cpf);
        setEndereco(endereco);
    }

};

int main (){
    vector <PessoaFisica> pessoa;
    vector <PessoaJuridica> empresa;

    char aux;
    do{
        cout<<"Menu: \n";
        cout<<"a- Cadastrar pessoa física \n";
        cout<<"b- Cadastrar empresa \n";
        cout<<"c- Listar pessoas fisícas \n";
        cout<<"d- Listar empresas \n";
        cout<<"e- Listar associação de empresas\n";
        cout<<"s- Sair \n";
        cout<<"Escolha: ";
        cin>>aux;
        aux=tolower(aux);
        switch (aux)
        {
        case 'a':{
            string nome, cpf, endereco;
            cout<<"Nome: ";
            cin.ignore();
            getline(cin,nome);
            cout<<"CPF: ";
            getline(cin,cpf);
            cout<<"Endereco: ";
            getline(cin,endereco);
            
            if(pessoa.size()>0){
                for(int i=0;i<pessoa.size();i++){
                    if(pessoa[i].getCpf()==cpf){
                        cout<<"Pessoa já cadastrada!\nFavor registar outro CPF!\n";
                    
                    }
                }
            
            }else{
                pessoa.emplace_back(nome,cpf,endereco);
            }
            
            break;
        }
        case 'b':{
            string cpfDono, nomeFantasia,cnpj,endereco;
            bool encontrado=false;
            cout<<"CPF do empresário(a): ";
            cin.ignore();
            getline(cin,cpfDono);
            for (int i=0; i<pessoa.size();i++){
                if(pessoa[i].getCpf()==cpfDono){
                    encontrado=true;
                    cout<<"Nome da empresa: ";
                    getline(cin,nomeFantasia);
                    cout<<"CNPJ: ";
                    getline(cin,cnpj);
                    cout<<"Endereço da empresa: ";
                    getline(cin, endereco);

                if(empresa.size()>0){
                for(int i=0;i<empresa.size();i++){
                    if(empresa[i].getCnpj()==cnpj){
                        cout<<"CNPJ já cadastrado!\nFavor registar outro CNPJ!\n";
                    
                    }
                }
                }else{
                pessoa[i].adicionarEmpresas(empresa.emplace_back(pessoa[i].getNome(),nomeFantasia,cnpj,endereco));
               
                }

                   break;
                }
            }
            if(!encontrado){
            cout<<"CPF não encontrado\n";
            }
            break;
        }
        case 'c':{
            if(pessoa.size()>0){
            for(int i=0; i<pessoa.size();i++){
                cout<<"Nome: "<< pessoa[i].getNome() <<"\n";
                cout<<"CPF: "<< pessoa[i].getCpf()  <<"\n";
                cout<<"Endereço: "<< pessoa[i].getEndereco() <<"\n";
                cout<<"----------------------------\n";
                }
            }else{
                cout<<"Não existem pessoas cadastradas!\n";
            }
            break;
        }
        case 'd':{
            if(empresa.size()>0){
            for(int i=0; i<empresa.size();i++){
                cout<<"Empresa de: "<< empresa[i].getDono() <<"\n";
                cout<<"Nome da empresa: "<< empresa[i].getNomeFantasia() <<"\n";
                cout<<"Cnpj: "<< empresa[i].getCnpj()  <<"\n";
                cout<<"Endereço: "<< empresa[i].getEndereco() <<"\n";
                cout<<"----------------------------\n";
                }
            }else{
                cout<<"Não existem empresas cadastradas!\n";
            }
            break;
        }
        case 'e':{
            if(empresa.size()>0){
            for(int i=0; i<pessoa.size();i++){
                cout<<"Nome: "<<pessoa[i].getNome()<<"\n";
                cout<<"Empresas associadas:\n";
                pessoa[i].mostrarEmpresas();
                cout<<"----------------------------\n";
            }
            }else{
                cout<<"Não existem associações Registradas!\n";
            }
            break;
            
        }
        case 's':{
            cout<<"Saindo ...\n";
            aux='s';
            break;
        }
        default:
            cout<<"Opção inválida! \n";
            break;
        }
    }while (aux != 's');
    
    

    return 0;
}