

import java.io.*;
import java.util.*;

public class VetoresBinarios {

    public static final int MAXDIMENSOES = 8;

    public static long k[] = new long[32];

    public static void main(String args[]) throws Exception {

        k[0] = 1;
        for (int i = 1; i != 32; i++) {
            k[i] = k[i - 1] * 2;
        }

        for (int dimensoes = 1; dimensoes != MAXDIMENSOES; dimensoes++) {

            int pontosCount = dimensoes + 1;
            int vetores[][] = new int[pontosCount + 1][dimensoes + 1];

            System.out.println("Tentando " + pontosCount + " pontos em "
                    + dimensoes + " dimensoes");
            tentaPreencher(vetores, 0, 0, dimensoes, pontosCount, -1);
            System.out.println();

        }

    }

    public static boolean tentaPreencher(int vetores[][], int vet, int pos,
            int dimensoes, int pontosCount, double dist) {

        // cheguei no final
        if (vet == pontosCount) {

            // verifica
            double distancia = calculaDistancia(vetores, 0, 1, dimensoes);
            for (int v1 = 0; v1 < pontosCount - 1; v1++) {
                for (int v2 = v1 + 1; v2 != pontosCount; v2++) {
                    if (distancia != calculaDistancia(vetores, v1, v2,
                            dimensoes)) {
                        return false;
                    } else if (ehIgual(vetores, v1, v2, dimensoes)) {
                        return false;
                    }
                }
            }

            for (int v1 = 0; v1 != pontosCount; v1++) {
                imprime(vetores, v1, dimensoes);
            }

            System.out.println(distancia);
            return true;

        }

        // se ja passei da ultima posicao desse vetor, tento o proximo vetor
        if (pos == dimensoes) {

            // se for o primeiro vetor, nao pode ser nulo
            if (vet == 0 && ehNulo(vetores, 0, dimensoes)) {
                //return false;
            } else if (vet == 1) {
                // se estamos terminando o segundo
                dist = calculaDistancia(vetores, 0, 1, dimensoes);
            }

            // verifica se eh igual a algum anterior
            for (int i = 0; i != vet; i++) {
                if (ehIgual(vetores, vet, i, dimensoes)) {
                    return false;
                }
            }

            // verifica a distancia
            if (vet > 1) {
                for (int i = 0; i != vet; i++) {
                    if (calculaDistancia(vetores, vet, i, dimensoes) != dist) {
                        return false;
                    }
                }
            }

            // tem que ser maior
            if (vet > 0) {
                if (vetores[vet - 1][dimensoes] >= vetores[vet][dimensoes]) {
                    return false;
                }
            }

            vetores[vet + 1][dimensoes] = 0;

            return tentaPreencher(vetores, vet + 1, 0, dimensoes, pontosCount,
                    dist);

        }

        // tento as duas possibilidades dessa posicao nesse vetor
        vetores[vet][pos] = 0;
        if (tentaPreencher(vetores, vet, pos + 1, dimensoes, pontosCount, dist)) {
            return true;
        }
        vetores[vet][pos] = 1;
        vetores[vet][dimensoes] += k[pos];
        if (tentaPreencher(vetores, vet, pos + 1, dimensoes, pontosCount, dist)) {
            return true;
        }
        vetores[vet][dimensoes] -= k[pos];
        return false;

    }

    public static double calculaDistancia(int vetores[][], int i1, int i2,
            int dimensoes) {
        double soma = 0.0;
        for (int i = 0; i != dimensoes; i++) {
            soma += (vetores[i1][i] - vetores[i2][i])
                    * (vetores[i1][i] - vetores[i2][i]);
        }
        return Math.sqrt(soma);
    }

    public static boolean ehNulo(int vetores[][], int v, int dimensoes) {
        int i;
        for (i = 0; i != dimensoes; i++) {
            if (vetores[v][i] != 0) {
                break;
            }
        }
        if (i == dimensoes) {
            return true;
        }
        return false;
    }

    public static void imprime(int vetores[][], int v, int dimensoes) {
        int i;
        System.out.print("(");
        for (i = 0; i != dimensoes; i++) {
            System.out.print(vetores[v][i]);
            if (i != dimensoes - 1) {
                System.out.print(",");
            }
        }
        System.out.println(")");
    }

    public static boolean ehIgual(int vetores[][], int v1, int v2, int dimensoes) {
        for (int i = 0; i != dimensoes; i++) {
            if (vetores[v1][i] != vetores[v2][i]) {
                return false;
            }
        }
        return true;
    }

    public static long valorDe(int vetores[][], int v, int dimensoes) {
        long k = 1, total = 0;
        for (int i = 0; i != dimensoes; i++) {
            if (vetores[v][i] == 1) {
                total += k;
            }
            k *= 2;
        }
        return total;
    }

}