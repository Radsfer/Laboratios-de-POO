import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Bloggo {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String texto;

        while ((texto = br.readLine()) != null) {
            StringBuilder saidaTexto = new StringBuilder();
            boolean italico = false;
            boolean negrito = false;

            for (char c : texto.toCharArray()) {
                if (c == '_') {
                    if (italico) {
                        saidaTexto.append("</i>");
                    } else {
                        saidaTexto.append("<i>");
                    }
                    italico = !italico;
                } else if (c == '*') {
                    if (negrito) {
                        saidaTexto.append("</b>");
                    } else {
                        saidaTexto.append("<b>");
                    }
                    negrito = !negrito;
                } else {
                    saidaTexto.append(c);
                }
            }

            System.out.println(saidaTexto.toString());
        }
    }
}
