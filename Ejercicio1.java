package ejercicios3_6;

import ejercicios3_1.Consola;

public class Ejercicio1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int n, multi, contador, numero;
		System.out.println("Introduce la cantidad de numeros");
		n = Consola.leeInt();
		contador = 1;
		multi = 1;
		numero = 1;
		while (contador < n) {
			numero = numero * multi;
			multi = multi + 1;
			System.out.print(numero + "\t");
			contador = contador + 1;
		}
;
		System.out.println("oksjd");
		System.out.println("oksjd");

}
