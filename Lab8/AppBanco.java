import java.util.Scanner;

public class AppBanco {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Banco contas = new Banco();

        //Habib essa parte foi implementada para facilitar seus teste, desculpa pelo metodo de numeração da conta,
        //sei que fica meio longo mas queria testar essa possibilidade de gerar numeros com datas.

        // ContaCorrenteComum contaTesteCCC = new ContaCorrenteComum("Titular CCC", "202310260001");
        // CorrentePremium contaTesteCCP = new CorrentePremium(new ContaCorrenteComum("Titular CCP", "202310260002"), 1000.0);
        // Investimentos contaTesteCI = new Investimentos(new ContaCorrenteComum("Titular CI", "202310260003"), 5.0);
        // Poupanca contaTesteCP = new Poupanca(new ContaCorrenteComum("Titular CP", "202310260004"));

        // contas.cadastrarContaCorrenteComum(contaTesteCCC);
        // contas.cadastrarContaCorrentePremium(contaTesteCCP);
        // contas.cadastrarContaInvestimentos(contaTesteCI);
        // contas.cadastrarContaPoupanca(contaTesteCP);

        int opcao;
        while (true) {
            System.out.println("\n=== Menu ===");
            System.out.println("1. Criar conta");
            System.out.println("2. Realizar operações em conta");
            System.out.println("3. Imprimir todas as contas");
            System.out.println("4. Sair");
            System.out.print("Escolha a opção: ");

            if (scanner.hasNextInt()) {
                opcao = scanner.nextInt();
                scanner.nextLine(); 
            } else {
                System.out.println("Opção inválida. Por favor, insira um número inteiro.");
                scanner.nextLine(); 
                continue; 
            }

            switch (opcao) {
                case 1: {
                    System.out.print("Digite o tipo de conta (CCC, CCP, CI, CP): ");
                    String tipoContaNova = scanner.nextLine();

                    switch (tipoContaNova) {
                        case "CCC": {
                            System.out.print("Digite o nome do titular da conta: ");
                            String titular = scanner.nextLine();
                            ContaCorrenteComum novaContaCCC = contas.criarContaPadrao(titular);
                            contas.cadastrarContaCorrenteComum(novaContaCCC);
                            System.out.println("Conta Corrente Comum cadastrada com sucesso!");
                            break;
                        }
                        case "CCP": {
                            System.out.print("Digite o nome do titular da conta: ");
                            String titular = scanner.nextLine();
                            ContaCorrenteComum contaBaseCCP = contas.criarContaPadrao(titular);

                            System.out.print("Digite o crédito especial: ");
                            double creditoEspecial = scanner.nextDouble();
                            CorrentePremium novaContaCCP = new CorrentePremium(contaBaseCCP, creditoEspecial);
                            contas.cadastrarContaCorrentePremium(novaContaCCP);
                            System.out.println("Corrente Premium cadastrada com sucesso!");

                            break;
                        }
                        case "CI": {
                            System.out.print("Digite o nome do titular da conta: ");
                            String titular = scanner.nextLine();
                            ContaCorrenteComum contaBaseCI = contas.criarContaPadrao(titular);

                            System.out.print("Digite o rendimento anual já em porcentagem: ");
                            double rendimentoAnual = scanner.nextDouble();
                            Investimentos novaContaCI = new Investimentos(contaBaseCI, rendimentoAnual);
                            contas.cadastrarContaInvestimentos(novaContaCI);
                            System.out.println("Investimentos cadastrada com sucesso!");

                            break;
                        }
                        case "CP": {
                            System.out.print("Digite o nome do titular da conta: ");
                            String titular = scanner.nextLine();
                            ContaCorrenteComum contaBaseCP = contas.criarContaPadrao(titular);
                            Poupanca novaContaCP = new Poupanca(contaBaseCP);
                            contas.cadastrarContaPoupanca(novaContaCP);
                            System.out.println("Poupança cadastrada com sucesso!");

                            break;
                        }
                        default:
                            System.out.println("Tipo de conta inválido. Tente novamente.");
                    }
                    break;
                }
                case 2: {
                    System.out.print("Digite o número da conta: ");
                    String numeroConta = scanner.nextLine();

                    System.out.print("Digite o tipo de conta (CCC, CCP, CI, CP): ");
                    String tipoConta = scanner.nextLine();

                    Object conta = contas.encontrarContaPorNumeroETTipo(numeroConta, tipoConta);

                    if (conta != null) {
                        System.out.println("\nOperações em conta " + numeroConta);
                        System.out.println("1. Depositar");
                        System.out.println("2. Sacar");
                        System.out.println("3. Visualizar extrato");
                        System.out.print("Escolha a operação: ");

                        if (scanner.hasNextInt()) {
                            int operacao = scanner.nextInt();
                            scanner.nextLine(); 

                            switch (operacao) {
                                case 1: {
                                    System.out.print("Digite o valor a ser depositado: ");
                                    double valorDeposito = scanner.nextDouble();

                                    if (conta instanceof ContaCorrenteComum) {                                       
                                        ContaCorrenteComum contaCC = (ContaCorrenteComum) conta;
                                        contaCC.depositar(valorDeposito);
                                    } else if (conta instanceof CorrentePremium) {                                      
                                        CorrentePremium contaCP = (CorrentePremium) conta;
                                        contaCP.depositar(valorDeposito);
                                    } else if (conta instanceof Investimentos) {                                        
                                        Investimentos contaCI = (Investimentos) conta;
                                        contaCI.depositar(valorDeposito);
                                    } else if (conta instanceof Poupanca) {
                                        Poupanca contaCP = (Poupanca) conta;
                                        contaCP.depositar(valorDeposito);
                                    }
                                    break;
                                }
                                case 2: {
                                    System.out.print("Digite o valor a ser sacado: ");
                                    double valorSaque = scanner.nextDouble();

                                    if (conta instanceof ContaCorrenteComum) {
                                        ((ContaCorrenteComum) conta).sacar(valorSaque);
                                    } else if (conta instanceof CorrentePremium) {
                                        ((CorrentePremium) conta).sacar(valorSaque);
                                    } else if (conta instanceof Investimentos) {
                                        ((Investimentos) conta).sacar(valorSaque);
                                    } else if (conta instanceof Poupanca) {
                                        ((Poupanca) conta).sacar(valorSaque);
                                    }
                                    break;
                                }
                                  case 3: {

                                    if (conta instanceof ContaCorrenteComum) {
                                        ((ContaCorrenteComum) conta).extrato();
                                    } else if (conta instanceof CorrentePremium) {
                                        ((CorrentePremium) conta).extrato();
                                    } else if (conta instanceof Investimentos) {
                                        ((Investimentos) conta).extrato();
                                    } else if (conta instanceof Poupanca) {
                                        ((Poupanca) conta).extrato();
                                    }
                                    break;
                                }
                                default:
                                    System.out.println("Operação inválida. Tente novamente.");
                            }
                        } else {
                            System.out.println("Operação inválida. Por favor, insira um número inteiro.");
                            scanner.nextLine(); 
                        }
                    } else {
                        System.out.println("Conta não encontrada.");
                    }
                    break;
                }
                case 3: {
                    contas.imprimirTodasContas();
                    break;
                }

                case 4: {
                    System.out.println("Saindo...");
                    scanner.close();
                    System.exit(0);
                }
                default:
                    System.out.println("Opção inválida. Tente novamente.");
                    break;
            }
        }
    }
}
