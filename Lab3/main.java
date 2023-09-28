import java.util.List;
import java.util.Scanner;


public class main {
    public static void main (String[] args) {
        Scanner scanner = new Scanner(System.in);
        Biblioteca biblioteca = new Biblioteca();

        while (true) {
            System.out.println("Escolha uma opção:");
            System.out.println("1) Adicionar livro");
            System.out.println("2) Procurar livro");
            System.out.println("3) Mostrar todos os livros");
            System.out.println("4) Sair");
            int opcao = scanner.nextInt();
            scanner.nextLine(); // Limpar o buffer

            switch (opcao) {
                case 1:
                    System.out.print("Digite o título do livro: ");
                    String titulo = scanner.nextLine();
                    System.out.print("Digite o nome do autor: ");
                    String nomeAutor = scanner.nextLine();
                    System.out.print("Digite a data de nascimento do autor: ");
                    String dataNascimento = scanner.nextLine();
                    System.out.print("Digite o ISBN do livro: ");
                    String isbn = scanner.nextLine();

                    Autor autor = new Autor(nomeAutor, dataNascimento);
                    Livro livro = new Livro(titulo, autor, isbn);
                    biblioteca.adicionarLivro(livro);
                    System.out.println("Livro adicionado à biblioteca.");
                    break;

                    case 2:
                    System.out.print("Digite o título do livro a ser procurado: ");
                    String tituloBusca = scanner.nextLine();
                    System.out.print("Digite o nome do autor do livro: ");
                    String autorBusca = scanner.nextLine();
                    
                    Autor autorProcura = new Autor(autorBusca, "");
                    List<Livro> resultadosBusca = biblioteca.buscarLivro(tituloBusca, autorProcura);
                
                    if (resultadosBusca.isEmpty()) {
                        System.out.println("Nenhum livro encontrado.");
                        
                    } else {
                        System.out.println("Livros encontrados:");
                        for (Livro l : resultadosBusca) {
                            System.out.println("Título: " + l.getTitulo());
                            System.out.println("Autor: " + l.getAutor().getNome());
                            System.out.println("ISBN: " + l.getISBN());
                            System.out.println("--------------------");
                        }
                    }
                    break;
                
                case 3:
                    System.out.println("Livros na biblioteca:");
                    biblioteca.mostrarLivros();
                    break;
                case 4:
                    System.out.println("Encerrando o programa.");
                    scanner.close();
                    System.exit(0);
                    break;
                default:
                    System.out.println("Opção inválida. Escolha uma opção válida.");
            }
        }
    }
}
