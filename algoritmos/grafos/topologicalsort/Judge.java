package grafos.topologicalsort;



import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

/**
 * @author Guilherme
 */
public class Judge {

    static BufferedReader judge = new BufferedReader(new InputStreamReader(
            System.in));

    static BufferedReader br;

    public static void main(String[] args) throws NumberFormatException,
            IOException {

        br = new BufferedReader(new FileReader(new File(
                "algoritmos/grafos/topologicalsort/input")));

        int casos = Integer.parseInt(br.readLine());

        for (int i = 0; i != casos; i++) {

            if (i != 0) {
                System.out.println();
                judge.readLine();
            }

            System.out.println("Case " + (i + 1) + ":");
            judge.readLine();
            new Judge().run();

        }

    }

    final HashMap tarefas = new HashMap();

    private final void run() throws IOException {

        String[] line = br.readLine().trim().split("[\\s]+");
        int tarefas = Integer.parseInt(line[0]);
        int dependencias = Integer.parseInt(line[1]);

        // gera as tarefas, cria vertices
        for (int i = 0; i != tarefas; i++) {
            newTarefa(br.readLine());
        }

        // gera as dependencias, cria arestas
        for (int i = 0; i != dependencias; i++) {
            line = br.readLine().trim().split("\\s+");
            // INVERTO AS DEPENDENCIAS!!!
            geraDependencia(line[1], line[0]);
        }

        Tarefa ordemDele[] = new Tarefa[tarefas];
        for (int i = 0; i != tarefas; i++) {
            ordemDele[i] = getTarefa(judge.readLine());
        }

        for (int i = 0; i != tarefas; i++) {
            // se ele dependia de alguem
            if (ordemDele[i].dep.size() != 0) {
                // ve se as dependencias dele ja foram visitadas
                for (int k = 0; k != ordemDele[i].dep.size(); k++) {
                    if (!((Tarefa) ordemDele[i].dep.get(k)).visitado) {
                        System.out.println("WRONG ANSWER");
                        return;
                    }
                }
            }
            ordemDele[i].visitado = true;
        }

        System.out.println("ACCEPTED");

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