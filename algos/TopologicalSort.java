package grafos.topologicalsort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Stack;

/**
 * @author Guilherme
 */
public class TopologicalSort {

    static BufferedReader br = new BufferedReader(new InputStreamReader(
            System.in));

    public static void main(String[] args) throws NumberFormatException,
            IOException {

        int casos = Integer.parseInt(br.readLine());

        for (int i = 0; i != casos; i++) {

            if (i != 0) {
                System.out.println();
            }

            System.out.println("Case " + (i + 1) + ":");
            new TopologicalSort().run();

        }

    }

    final HashMap tarefas = new HashMap();

    private final void run() throws IOException {

        String[] line = br.readLine().trim().split("[\\s]+");
        int tarefas = Integer.parseInt(line[0]);
        int dependencias = Integer.parseInt(line[1]);

        // debug info
        //System.out.println(tarefas + " " + dependencias);

        // gera as tarefas, cria vertices
        for (int i = 0; i != tarefas; i++) {
            newTarefa(br.readLine());
        }

        // gera as dependencias, cria arestas
        for (int i = 0; i != dependencias; i++) {
            line = br.readLine().trim().split("\\s+");
            geraDependencia(line[0], line[1]);
        }

        // FINAL STACK
        Stack resultado = new Stack();

        // DFS
        ArrayList completeList = new ArrayList(this.tarefas.values());
        while (!completeList.isEmpty()) {

            Tarefa t1 = (Tarefa) completeList.remove(0);

            ArrayList pilha = new ArrayList();
            pilha.add(t1);
            t1.visitado = true;

            while (!pilha.isEmpty()) {

                Tarefa t = (Tarefa) pilha.get(pilha.size() - 1);

                if (t.posicaoAtual >= t.dep.size()) {
                    // posso parar esse cara
                    resultado.push(t);
                    pilha.remove(t);
                    continue;
                }

                Tarefa nova = (Tarefa) t.dep.get(t.posicaoAtual++);
                if (nova.visitado) {
                    continue;
                }

                nova.visitado = true;
                pilha.add(nova);
                completeList.remove(nova);

            }

        }

        while (!resultado.isEmpty()) {
            System.out.println(resultado.pop());
        }

    }

    private void geraDependencia(String t1, String t2) {
        getTarefa(t1).addDependencia(getTarefa(t2));
    }

    private final void newTarefa(String s) {
        Tarefa t = new Tarefa();
        t.name = s;
        tarefas.put(s, t);
       // System.out.println("nova: " + s);
    }

    private final Tarefa getTarefa(String s) {
        return (Tarefa) tarefas.get(s);
    }

}

class Tarefa {

    String name;

    ArrayList dep = new ArrayList();

    int posicaoAtual = 0;
    
    boolean visitado = false;

    /**
     * Preparando para reciclar objetos
     * 
     * @param s
     */
    public void recycle(String s) {
        dep.clear();
        this.name = s;
        posicaoAtual = 0;
    }

    public boolean equals(Object obj) {
        return this.name.equals(((Tarefa) obj).name);
    }

    public void addDependencia(Tarefa tarefa) {
        dep.add(tarefa);
    }

    public int hashCode() {
        return this.name.hashCode();
    }
    
    public String toString() {
        return this.name;
    }

}