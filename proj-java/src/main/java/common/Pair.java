package common;

import java.util.Objects;

public class Pair<X,Y> {

    /**
     * Primeira componente
     */
    private X fst;

    /**
     * Segunda componente
     */
    private Y snd;


    /**
     * Contrutor parametrizado
     * @param fst Valor da primeira componente
     * @param snd Valor da segunda componente
     */
    public Pair(X fst, Y snd) {
        this.fst = fst;
        this.snd = snd;
    }

    /**
     * Hash code do par
     * @return Hash code do par
     */
    public int hashCode() {
        int hashFst = fst != null ? fst.hashCode() : 0;
        int hashSnd = snd != null ? snd.hashCode() : 0;

        return (hashFst + hashSnd) * hashSnd + hashFst;
    }

    /**
     * Método equals
     * @param o objeto a ser comparado com o par
     * @return true se o objeto é igual ao par, false caso contrário
     */
    public boolean equals(Object o) {
        if (o instanceof Pair) {
            Pair p = (Pair) o;
            return Objects.equals(this.fst, p.fst) && Objects.equals(snd, p.snd);
        }
        return false;
    }

    /**
     * Converte o par em uma string
     * @return String do par
     */
    public String toString() {
        return "(" + fst + ", " + snd + ")";
    }

    /**
     * Valor da primeira componente
     * @return Valor da primeira componente
     */
    public X getFst() {
        return fst;
    }

    /**
     * Valor da segunda componente
     * @return Valor da segunda componente
     */
    public Y getSnd() {
        return snd;
    }

}