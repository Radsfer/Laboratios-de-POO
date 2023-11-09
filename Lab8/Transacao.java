import java.text.SimpleDateFormat;
import java.util.Date;

public class Transacao {
    private Date dataTransacao;
    private String descricao;
    private double valor;

    public Transacao(String descricao, double valor) {
        dataTransacao = new Date();
        this.descricao = descricao;
        this.valor = valor;
    }

    public Date getDataTransacao() {
        return dataTransacao;
    }

    public String getDescricao() {
        return descricao;
    }

    public void setDescricao(String descricao) {
        this.descricao = descricao;
    }

    public double getValor() {
        return valor;
    }

    public void setValor(double valor) {
        this.valor = valor;
    }

public void imprimirInformacoes() {
    SimpleDateFormat dateFormat = new SimpleDateFormat("dd/MM/yyyy HH:mm:ss");
    String dataFormatada = dateFormat.format(this.dataTransacao);

    System.out.println("Data da Transação: " + dataFormatada);
    System.out.println("Descrição: " + this.descricao);
    System.out.println("Valor: " + this.valor);
    System.out.println("-------------------------------");
}

}
