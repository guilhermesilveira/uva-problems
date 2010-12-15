

import java.io.IOException;
import java.util.Enumeration;
import java.util.Hashtable;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.Vector;

/**
 * @author Guilherme
 */
class Main {

    static int maxLg = 200;

    // le uma linha inteira
    static String readLine() throws IOException {
        byte lin[] = new byte[maxLg];
        int lg = 0, car = -1;
        while (lg < maxLg) {
            car = System.in.read();
            if ((car < 0) || (car == '\n')) {
                break;
            }
            lin[lg++] += car;
        }
        if ((car < 0) && (lg == 0)) {
            return (null); // eof
        }
        return (new String(lin, 0, lg));
    }

    public static void main(String[] args) throws NumberFormatException,
            IOException {

        while (true) {
            if (!new Main().run()) {
                break;
            }
        }

    }

    final Hashtable tarefas = new Hashtable();
    final Vector listaTarefas = new Vector();

    private final boolean run() throws IOException {

        String[] line = split(readLine().trim());
        int tarefas = Integer.parseInt(line[0]);
        int dependencias = Integer.parseInt(line[1]);

        if (tarefas == 0 && dependencias == 0) {
            return false;
        }

        // gera as tarefas, cria vertices
        for (int i = 0; i != tarefas; i++) {
            newTarefa2((i + 1));
        }

        // gera as dependencias, cria arestas
        for (int i = 0; i != dependencias; i++) {
            line = split(readLine().trim());
            geraDependencia("" + line[0], "" + line[1]);
        }

        // FINAL STACK
        Stack resultado = new Stack();

        // DFS
        Vector completeList = new Vector();//new Vector(this.tarefas.values());
        
        Enumeration enum = this.tarefas.elements();
        while(enum.hasMoreElements()) {
            completeList.addElement(enum.nextElement());
        }
        
        while (!completeList.isEmpty()) {

            Tarefa2 t1 = (Tarefa2) completeList.elementAt(0);
            completeList.removeElementAt(0);

            Vector pilha = new Vector();
            pilha.addElement(t1);
            t1.visitado = true;

            while (!pilha.isEmpty()) {

                Tarefa2 t = (Tarefa2) pilha.elementAt(pilha.size() - 1);

                if (t.posicaoAtual >= t.dep.size()) {
                    // posso parar esse cara
                    resultado.push(t);
                    pilha.removeElementAt(pilha.size() - 1);
                    continue;
                }

                Tarefa2 nova = (Tarefa2) t.dep.elementAt(t.posicaoAtual++);
                if (nova.visitado) {
                    continue;
                }

                nova.visitado = true;
                pilha.addElement(nova);
                completeList.removeElement(nova);

            }

        }

        String s = "";
        while (!resultado.isEmpty()) {
            s += resultado.pop() + " ";
        }
        System.out.println(s.substring(0, s.length() - 1));

        return true;

    }

    static String[] split(String s) {
        StringTokenizer st = new StringTokenizer(s, " ");
        String[] tokens = new String[st.countTokens()];
        for (int i = 0; i != tokens.length; i++) {
            tokens[i] = st.nextToken();
        }
        return tokens;
    }

    private void geraDependencia(String t1, String t2) {
        getTarefa2(t1).addDependencia(getTarefa2(t2));
    }

    private final void newTarefa2(int s) {
        Tarefa2 t = new Tarefa2();
        t.name = s;
        tarefas.put("" + s, t);
        listaTarefas.addElement(t);
    }

    private final Tarefa2 getTarefa2(String s) {
        return (Tarefa2) tarefas.get(s);
    }

}

class Tarefa2 {

    int name;

    Vector dep = new Vector();

    int posicaoAtual = 0;

    boolean visitado = false;

    public boolean equals(Object obj) {
        return this.name==(((Tarefa2) obj).name);
    }

    public void addDependencia(Tarefa2 tarefa) {
        dep.addElement(tarefa);
    }

    public String toString() {
        return this.name + "";
    }

}