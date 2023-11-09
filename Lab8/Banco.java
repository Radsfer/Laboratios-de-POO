import java.util.List;
import java.util.ArrayList;
import java.util.Date;
import java.text.SimpleDateFormat;

public class Banco {
    private List<ContaCorrenteComum> CCCs;
    private List<CorrentePremium> CCPs;
    private List<Investimentos> CIs;
    private List<Poupanca> CPs;

    public Banco() {
        CCCs = new ArrayList<>();
        CCPs = new ArrayList<>();
        CIs = new ArrayList<>();
        CPs = new ArrayList<>();
    }

    public int tamanhoTotalContas() {
        int tamanhoTotal = CCCs.size() + CCPs.size() + CIs.size() + CPs.size();
        return tamanhoTotal;
    }

    public ContaCorrenteComum criarContaPadrao(String titular) {
        SimpleDateFormat dateFormat = new SimpleDateFormat("yyyyMMdd");
        String dataAtual = dateFormat.format(new Date());
        int numeroSequencial = tamanhoTotalContas() + 1;
        String numeroConta = dataAtual + String.format("%04d", numeroSequencial);

        ContaCorrenteComum novaConta = new ContaCorrenteComum(titular, numeroConta);

        return novaConta;
    }

    public void cadastrarContaCorrenteComum(ContaCorrenteComum conta) {
        CCCs.add(conta);
    }

    public void cadastrarContaCorrentePremium(CorrentePremium conta) {
        CCPs.add(conta);
    }

    public void cadastrarContaInvestimentos(Investimentos conta) {
        CIs.add(conta);
    }

    public void cadastrarContaPoupanca(Poupanca conta) {
        CPs.add(conta);
    }

    public ContaCorrenteComum encontrarContaCorrenteComumPorNumero(String numeroConta) {
        for (int i = 0; i < CCCs.size(); i++) {
            ContaCorrenteComum conta = CCCs.get(i);
            if (conta.getNumeroConta().equals(numeroConta)) {
                return conta;
            }
        }
        return null; 
    }

    public CorrentePremium encontrarContaCorrentePremiumPorNumero(String numeroConta) {
        for (int i = 0; i < CCPs.size(); i++) {
            CorrentePremium conta = CCPs.get(i);
            if (conta.getNumeroConta().equals(numeroConta)) {
                return conta;
            }
        }
        return null; 
    }

    public Investimentos encontrarContaInvestimentosPorNumero(String numeroConta) {
        for (int i = 0; i < CIs.size(); i++) {
            Investimentos conta = CIs.get(i);
            if (conta.getNumeroConta().equals(numeroConta)) {
                return conta;
            }
        }
        return null; 
    }

    public Poupanca encontrarContaPoupancaPorNumero(String numeroConta) {
        for (int i = 0; i < CPs.size(); i++) {
            Poupanca conta = CPs.get(i);
            if (conta.getNumeroConta().equals(numeroConta)) {
                return conta;
            }
        }
        return null; 
    }

    public Object encontrarContaPorNumeroETTipo(String numeroConta, String tipoConta) {
        switch (tipoConta) {
            case "CCC":
                return encontrarContaCorrenteComumPorNumero(numeroConta);
            case "CCP":
                return encontrarContaCorrentePremiumPorNumero(numeroConta);
            case "CI":
                return encontrarContaInvestimentosPorNumero(numeroConta);
            case "CP":
                return encontrarContaPoupancaPorNumero(numeroConta);
            default:
                return null; 
        }
    }

    public void imprimirTodasContas() {
        System.out.println("Contas Corrente Comum:");
        for (ContaCorrenteComum conta : CCCs) {
            System.out.println(conta.getNumeroConta());
        }
    
        System.out.println("Contas Corrente Premium:");
        for (CorrentePremium conta : CCPs) {
            System.out.println(conta.getNumeroConta());
        }
    
        System.out.println("Contas de Investimentos:");
        for (Investimentos conta : CIs) {
            System.out.println(conta.getNumeroConta());
        }
    
        System.out.println("Contas de Poupança:");
        for (Poupanca conta : CPs) {
            System.out.println(conta.getNumeroConta());
        }
    }
    

}
