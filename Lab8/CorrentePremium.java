
public class CorrentePremium extends ContaCorrenteComum {
    private double creditoEspecial;

    public CorrentePremium(ContaCorrenteComum contaCorrenteComum, double creditoEspecial) {
        super(contaCorrenteComum.getTitular(), contaCorrenteComum.getNumeroConta());
        this.creditoEspecial = creditoEspecial;
    }
    
    @Override
    public void sacar(double valor) {
        if (valor > 0 && valor <= saldo+creditoEspecial) {
            saldo -= valor;
            Transacao transacaoAtual = new Transacao("Saque", -valor);
            transacoes.add(transacaoAtual);
            System.out.println("Saque realizado com sucesso.");
        } else {
            System.out.println("Valor de saque inválido. Tente novamente.");
        }
    }

    @Override
    public void extrato() {
        System.out.println("-------------------------------");
        System.out.println("Tipo de conta: [CCP] Conta Corrente Premium");
        System.out.println("Crédito especial: " + this.creditoEspecial);
        extratoBase();
    }

}
