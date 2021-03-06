/* * * * * * * * * * * * * * * * * * * * * * * * *
 *                                               *
 * Nome : Rafael Escaleira Ferreira dos Santos.  *
 * Universidade Federal do Mato Grosso do Sul    *
 * Disciplina : Estrutura de Dados e Programação *
 *                                               *
 * * * * * * * * * * * * * * * * * * * * * * * * */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "abb.h"

int main (void) {
    
    cor_texto (ciano);
    printf ("\n\t* * * * * * * * ");
    estilo_texto (resetar);
    
    cor_texto (amarelo);
    printf ("CONFERE FUNCIONAMENTO");
    estilo_texto (resetar);
    
    cor_texto (ciano);
    printf (" * * * * * * * *\n\t*                                                   *\n");
    estilo_texto (resetar);
    
    teste_constroi_abb ();
    teste_insere_abb ();
    teste_busca_abb ();
    teste_remove_abb ();
    
    cor_texto (ciano);
    printf ("\t*                                                   *\n\t* * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
    estilo_texto (resetar);
    
    int n, * v, i;
    tarv arv;
    treg * aux;
    clock_t inicio, fim;
    double tempo [2];
    
    abb_constroi (&arv, &compara);
    
    printf ("Quantidade de Elementos : ");
    scanf ("%d", &n);
    
    aux = (treg *) malloc (sizeof (treg));
    v = (int *) malloc (n * sizeof (int));
    
    printf ("\nVetor : ");
    
    for (i = 0; i < n; i ++) {
        
        scanf ("%d", (v + i));
        
    }
    
    printf("\n");
    
    /* Inserção em ABB */
    
    inicio = clock ();
    
    for (i = 0; i < n; i ++) {
        
        cor_texto (ciano);
        printf ("\n* * * * * * * * ");
        estilo_texto (resetar);
        printf ("Inserção Árvore de Busca Binária");
        cor_texto (ciano);
        printf (" * * * * * * * *\n\n");
        estilo_texto (resetar);
        
        printf ("Insere : ");
        cor_texto (verde);
        printf ("%d\n\n", * (v + i));
        estilo_texto (resetar);
        
        abb_insere (&arv, aloca_reg (* (v + i)));
        
        imprime_arvore_abb (arv.raiz, 0, * (v + i));
        
        estilo_texto (resetar);
        
    }
    
    fim = clock ();
    
    tempo [0] = ( (double) (fim - inicio) ) / CLOCKS_PER_SEC;
    
    /* Remoção em ABB */
    
    inicio = clock ();
    
    for (i = 0; i < n; i ++) {
        
        cor_texto (ciano);
        printf ("\n\n* * * * * * * * ");
        estilo_texto (resetar);
        printf ("Remoção Árvore de Busca Binária");
        cor_texto (ciano);
        printf (" * * * * * * * *\n\n");
        estilo_texto (resetar);
        
        aux = arv.raiz -> reg;
        
        printf ("Remove : ");
        cor_texto (verde);
        printf ("%d\n\n", aux -> id);
        estilo_texto (resetar);
        
        abb_remove (&arv, aloca_reg (aux -> id));
        
        imprime_arvore_abb (arv.raiz, 0, aux -> id);
        
        if (arv.raiz == NULL) {
            
            cor_texto (verde);
            printf("\t* * * * * *\n\t*");
            estilo_texto (resetar);
            
            cor_texto (vermelho);
            printf ("   NULL  ");
            estilo_texto (resetar);
            
            cor_texto (verde);
            printf("*\n\t* * * * * *\n");
            estilo_texto (resetar);
            
        }
        
    }
    
    printf ("\n");
    
    fim = clock ();
    
    tempo [1] = ( (double) (fim - inicio) ) / CLOCKS_PER_SEC;
    
    cor_texto (ciano);
    printf ("\t* * * * * * * * * ");
    estilo_texto (resetar);
    
    cor_texto (amarelo);
    printf("TEMPO DE EXECUÇÃO");
    estilo_texto (resetar);
    
    cor_texto (ciano);
    printf (" * * * * * * * * *\n");
    printf("\t*                                                   *\n");
    estilo_texto (resetar);
    
    cor_texto (ciano);
    printf("\t*");
    estilo_texto (resetar);
    
    cor_texto (verde);
    printf ("\t  * ");
    cor_texto (magenta);
    printf ("ABB ");
    estilo_texto (resetar);
    printf ("Inserção : %.6lf segundos\t", tempo [0]);
    
    cor_texto (ciano);
    printf("    *\n");
    estilo_texto (resetar);
    
    cor_texto (ciano);
    printf("\t*");
    estilo_texto (resetar);
    
    cor_texto (verde);
    printf ("\t  * ");
    cor_texto (magenta);
    printf ("ABB ");
    estilo_texto (resetar);
    printf ("Remoção  : %.6lf segundos\t", tempo [1]);
    
    cor_texto (ciano);
    printf("    *\n");
    estilo_texto (resetar);
    
    cor_texto (ciano);
    printf("\t*                                                   *\n");
    printf("\t* * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
    estilo_texto (resetar);
    
    free_node_abb (arv.raiz);
    free (v);
    
    cor_texto (vermelho);
    estilo_texto (piscar);
    printf ("\t\t\t     FIM DE EXECUÇÃO\n\n");
    estilo_texto (resetar);
    
    return 0;
    
}
