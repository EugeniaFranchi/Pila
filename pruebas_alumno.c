#include "pila.h"
#include "testing.h"
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>


/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/

void pruebas_crear_destruir(){
	printf("\n--CREAR/DESTRUIR--\n");
	void* pil = pila_crear();
	print_test("Se creo una pila", true);
	pila_destruir(pil);
	print_test("Se destruyo la pila", true);
}

void pruebas_pila_vacia(){
	printf("\n--VACIA--\n");
	void* vacio = pila_crear();
	
    print_test("Esta vacia", pila_esta_vacia(vacio) == true);
    print_test("No puedo desapilar", pila_desapilar(vacio) == NULL);
    print_test("No hay tope", pila_ver_tope(vacio) == NULL);
    
    pila_destruir(vacio);
}

void pruebas_desapilar_apilar(){
	printf("\n--APILAR/DESAPILAR--\n");
	int valor1[] = {0};
	int valor2[] = {489};
	int valor3[] = {68};
	void* nulo = NULL;
	pila_t* pil1 = pila_crear();
	
	/*Pruebas de 1 elemento*/
	print_test("Apilo valor1",pila_apilar(pil1, valor1) == true);
	print_test("No esta vacia", pila_esta_vacia(pil1) == false);
	print_test("Desapila valor1", pila_desapilar(pil1) == valor1);
	print_test("Esta vacia", pila_esta_vacia(pil1) == true);
	
	/*Pruebas de varios elementos*/
	print_test("Apilo valor2",pila_apilar(pil1, valor2) == true);
	print_test("No esta vacia", pila_esta_vacia(pil1) == false);
	print_test("Apilo valor3",pila_apilar(pil1, valor3) == true);
	print_test("No esta vacia", pila_esta_vacia(pil1) == false);
	print_test("Desapila valor3", pila_desapilar(pil1) == valor3);
	print_test("No esta vacia", pila_esta_vacia(pil1) == false);
	print_test("Desapila valor2", pila_desapilar(pil1) == valor2);
	print_test("Esta vacia", pila_esta_vacia(pil1) == true);
	
	/*Pruebas con NULL*/
	print_test("Apilo NULL",pila_apilar(pil1, nulo) == true);
	print_test("No esta vacia", pila_esta_vacia(pil1) == false);
	print_test("Desapila NULL", pila_desapilar(pil1) == nulo);
	print_test("Esta vacia", pila_esta_vacia(pil1) == true);

	pila_destruir(pil1);
}

void pruebas_tope(){
	printf("\n--TOPE--\n");
	pila_t* pil2 = pila_crear();
	int valor1[] = {45};
	int valor2[] = {765};
	void* nulo = NULL;
	
	/*Pruebas con elementos*/
	print_test("Apilo valor1",pila_apilar(pil2, valor1) == true);
	print_test("En el tope esta valor1",pila_ver_tope(pil2) == valor1);
	print_test("Apilo valor2",pila_apilar(pil2, valor2) == true);
	print_test("En el tope esta valor2",pila_ver_tope(pil2) == valor2);
	print_test("Desapila valor2", pila_desapilar(pil2) == valor2);
	print_test("En el tope esta valor1",pila_ver_tope(pil2) == valor1);
	print_test("Desapila valor1", pila_desapilar(pil2) == valor1);
	print_test("No tiene tope.",pila_ver_tope(pil2) == NULL);
	
	/*Pruebas con NULL*/
	print_test("Apilo NULL",pila_apilar(pil2, nulo) == true);
	print_test("En el tope esta NULL",pila_ver_tope(pil2) == nulo);
	print_test("Desapila el cuarto elemento", pila_desapilar(pil2) == nulo);
	print_test("No tiene tope.",pila_ver_tope(pil2) == NULL);
	
	pila_destruir(pil2);
}

void pruebas_volumen(){
	printf("\n--VOLUMEN--\n");
	pila_t* pil3 = pila_crear();
	int valor[] = {23};
	
	/*Pruebas apilando*/
	int contador = 500;
	while (contador > 0){
		pila_apilar(pil3, valor);
		contador--;
	}
	print_test("Se redimensiona al apilar 500 elementos", true);
	
	/*Pruebas desapilando*/
	contador = 500;
	while (contador > 0){
		pila_desapilar(pil3);
		contador--;
	}
	print_test("Se redimensiona al desapilar 500 elementos", true);
	
	pila_destruir(pil3);
}

void pruebas_desapilada(){
	printf("\n--DESAPILADA--\n");
	void* pil4 = pila_crear();
	int valor[] = {89};
	
	/*Apilo*/
	int contador = 20;
	while (contador > 0){
		pila_apilar(pil4, valor);
		contador--;
	}
	
	/*Desapilo*/
	contador = 20;
	while (contador > 0){
		pila_desapilar(pil4);
		contador--;
	}
	
	/*Compruebo que desapilada por completo se comporta como recien creada*/
    print_test("Esta vacia", pila_esta_vacia(pil4) == true);
	print_test("No puedo desapilar", pila_desapilar(pil4) == NULL);
    print_test("No hay tope", pila_ver_tope(pil4) == NULL);
	
	pila_destruir(pil4);
}

void pruebas_pila_alumno() {
	pruebas_crear_destruir();
    pruebas_pila_vacia();
    pruebas_desapilar_apilar();
    pruebas_tope();
    pruebas_volumen();
    pruebas_desapilada();
}
