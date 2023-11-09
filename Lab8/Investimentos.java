public class Investimentos extends ContaCorrenteComum {
    private double rendimentoAnual;

    public Investimentos(ContaCorrenteComum contaCorrenteComum, double rendimentoAnual){
        super(contaCorrenteComum.getTitular(), contaCorrenteComum.getNumeroConta());
        this.rendimentoAnual=rendimentoAnual;
    }
    
    @Override
    public void extrato() {
        System.out.println("-------------------------------");
        System.out.println("Tipo de conta: [CI] Conta de Investimentos");
        System.out.println("Rendimento anual de: " +(rendimentoAnual)+"%");
        extratoBase();
        
    }

    public double getRendimentoAnual() {
        return rendimentoAnual;
    }

    public void setRendimentoAnual(double rendimentoAnual) {
        this.rendimentoAnual = rendimentoAnual;
    }

    
}
