import java.text.SimpleDateFormat;

public class Poupanca extends ContaCorrenteComum {
    public Poupanca(ContaCorrenteComum contaCorrenteComum){
        super(contaCorrenteComum.getTitular(), contaCorrenteComum.getNumeroConta());
        
    }
    @Override
    public void extrato() {
        System.out.println("-------------------------------");
        System.out.println("Tipo de conta: [CP] Conta Poupança");
        SimpleDateFormat dateFormat = new SimpleDateFormat("dd/MM/yyyy HH:mm:ss");
        System.out.println("Criada em:" + dateFormat.format(this.aniversario));
        extratoBase();
        
       
    }
}
