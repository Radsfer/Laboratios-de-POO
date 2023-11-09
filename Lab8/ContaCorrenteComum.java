import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class ContaCorrenteComum {
    protected String titular;
    protected String numeroConta;
    protected double saldo;
    protected Date aniversario;
    protected List<Transacao> transacoes;

    public ContaCorrenteComum() {
        aniversario = new Date();
        saldo = 0;
    }

    public ContaCorrenteComum(String titular, String numeroConta) {
        this();
        transacoes = new ArrayList<>();
        this.titular = titular;
        this.numeroConta = numeroConta;
        aniversario = new Date();
        saldo = 0;
    }

    public String getTitular() {
        return titular;
    }

    public void setTitular(String titular) {
        this.titular = titular;
    }

    public String getNumeroConta() {
        return numeroConta;
    }

    public void setNumeroConta(String numeroConta) {
        this.numeroConta = numeroConta;
    }

    public double getSaldo() {
        return saldo;
    }

    public void setSaldo(double saldo) {
        this.saldo = saldo;
    }

    public Date getAniversario() {
        return aniversario;
    }

   
    public void depositar(double valor) {
        if (valor > 0) {
            saldo += valor;
            Transacao transacaoAtual = new Transacao("Depósito", valor);
            transacoes.add(transacaoAtual);
            System.out.println("Depósito realizado com sucesso.");
        } else {
            System.out.println("Valor de depósito inválido. Tente novamente.");
        }
    }


    public void sacar(double valor) {
        if (valor > 0 && valor <= saldo) {
            saldo -= valor;
            Transacao transacaoAtual = new Transacao("Saque", -valor);
            transacoes.add(transacaoAtual);
            System.out.println("Saque realizado com sucesso.");
        } else {
            System.out.println("Valor de saque inválido. Tente novamente.");
        }
    }

    public void adicionarTransacao(Transacao transacao) {
        transacoes.add(transacao);
    }

    public void extratoBase() {
        System.out.println("Titular: " + this.titular);
        System.out.println("Número da Conta: " + this.numeroConta);
        System.out.println("Saldo: " + this.saldo);

        if (transacoes != null) {
            System.out.println("Transações:");
            System.out.println("-------------------------------");
            for (int i = 0; i < transacoes.size(); i++) {
                transacoes.get(i).imprimirInformacoes();
            }
        }

    }

    public void extrato() {
        System.out.println("-------------------------------");
        System.out.println("Tipo de conta: [CCC] Conta Corrente Comum");
        extratoBase();
    }
}
