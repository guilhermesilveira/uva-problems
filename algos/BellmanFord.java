package grafos.bellmanford;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Hashtable;
import java.util.Iterator;

/**
 * @author Guilherme
 */
public class BellmanFord {

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
            new BellmanFord().run();

        }

    }

    final HashMap clientes = new HashMap();

    final ArrayList arestas = new ArrayList();

    private final void run() throws IOException {

        String[] line = br.readLine().trim().split("[\\s]+");
        int clientes = Integer.parseInt(line[0]);
        int rotas = Integer.parseInt(line[1]);

        // gera os clientes, cria vertices
        for (int i = 0; i != clientes; i++) {
            newCliente(br.readLine());
        }

        // gera as dependencias, cria arestas
        for (int i = 0; i != rotas; i++) {
            line = br.readLine().trim().split("\\s+");
            geraRota(line[0], line[1], Double.parseDouble(line[2]));
        }

        line = br.readLine().trim().split("\\s+");
        Cliente from = getCliente(line[0]);
        from.custoAtual = 0;
        Cliente to = getCliente(line[1]);

        System.out.println("Indo de " + from + " ate " + to);

        // para cada vertice em V
        for (int k = 0; k != clientes - 1; k++) {
            System.out.println("Iteracao " + k);
            // para cada aresta
            for (int i = 0; i != rotas; i++) {
                Aresta a = (Aresta) this.arestas.get(i);
                // se for mais curto
                if (a.to.custoAtual > a.from.custoAtual + a.custo) {
                    a.to.custoAtual = a.from.custoAtual + a.custo;
                    a.to.parent = a.from;
                }
            }
            for (Iterator i = this.clientes.values().iterator(); i.hasNext();) {
                Cliente ccc = (Cliente) i.next();
                System.out.println(ccc + " :: " + ccc.custoAtual);
            }
        }

        // para cada aresta
        for (int i = 0; i != rotas; i++) {
            Aresta a = (Aresta) this.arestas.get(i);
            // se for mais curto
            if (a.to.custoAtual > a.from.custoAtual + a.custo) {
                System.out.println("Sistema invalido");
                return;
            }
        }

        System.out.println("Custo: " + to.custoAtual);

    }

    private void geraRota(String t1, String t2, double custo) {
        Aresta a = new Aresta(getCliente(t1), getCliente(t2), custo);
        arestas.add(a);
        getCliente(t1).addRota(a);
    }

    private final void newCliente(String s) {
        Cliente t = new Cliente();
        t.name = s;
        clientes.put(s, t);
    }

    private final Cliente getCliente(String s) {
        return (Cliente) clientes.get(s);
    }

}

class Cliente {

    String name;

    Hashtable dep = new Hashtable();

    Cliente parent;

    double custoAtual = Double.POSITIVE_INFINITY;

    public boolean equals(Object obj) {
        return this.name.equals(((Cliente) obj).name);
    }

    /**
     * @param cliente
     */
    public Aresta getAresta(Cliente cliente) {
        return (Aresta) dep.get(cliente);
    }

    public void addRota(Aresta a) {
        dep.put(a.to, a);
    }

    public int hashCode() {
        return this.name.hashCode();
    }

    public String toString() {
        return this.name;
    }

}

class Aresta {

    double custo;

    Cliente from;

    Cliente to;

    Aresta(Cliente f, Cliente t, double d) {
        this.from = f;
        this.to = t;
        this.custo = d;
    }

}