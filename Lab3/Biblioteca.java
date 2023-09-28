import java.util.ArrayList;
import java.util.List;

public class Biblioteca {
    private List<Livro> livros;

    public Biblioteca() {
        livros = new ArrayList<>();
    }

    public void adicionarLivro(Livro livro) {
        livros.add(livro);
    }

    public List<Livro> buscarLivro(String titulo, Autor autor) {
        List<Livro> resultados = new ArrayList<>();
        for (Livro livro : livros) {
            if (livro.getTitulo().equals(titulo) && livro.getAutor().equals(autor)) {
                resultados.add(livro);
            }
        }
        return resultados;
    }
    

    public void mostrarLivros() {
        for (Livro livro : livros) {
            System.out.println("Título: " + livro.getTitulo());
            System.out.println("Autor: " + livro.getAutor().getNome());
            System.out.println("Nascimento: " + livro.getAutor().getDataNascimento());
            System.out.println("ISBN: " + livro.getISBN());
            System.out.println("--------------------");
        }
    }

    
    public List<Livro> getLivros() {
        return livros;
    }

   
    public void setLivros(List<Livro> livros) {
        this.livros = livros;
    }
}
