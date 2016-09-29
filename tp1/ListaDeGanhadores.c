#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
//----------------------------------------------------------------------------- Definir struct para armazenar nomes a ser comparados
typedef struct lista{
	char info[50];
}Lista;

//----------------------------------------------------------------------------- ordenar

int ordena(const void *a, const void *b){
	Lista *x = (Lista *) a;
	Lista *y = (Lista *) b;

	return strcmp(x->info, y->info);
}

int main()
//-----------------------------------------------------------------------------
{
    char url[] = "nomes", info[50];
    int cont = 0;
    Lista nomes[820];
//-----------------------------------------------------------------------------
    FILE *arquivo;
    FILE *Ordenado;
    FILE *winners;
//-----------------------------------------------------------------------------Abrir Arquivos
    arquivo         = fopen(url,"r");
    Ordenado = fopen("nomes ordenados", "w+");
    winners = fopen("winners.html", "w+");
//-----------------------------------------------------------------------------
    if(arquivo == NULL || Ordenado == NULL || winners == NULL)
			printf("Erro, nao foi possivel abrir o arquivo\n");
	else{
	    while( (fgets(info, sizeof(info), arquivo))!=NULL ){
			cont++;

	    }
	    cont--;
		fseek(arquivo, 0, SEEK_SET); // Apontar para o bit inical
//-----------------------------------------------------------------------------qsort ordena
		qsort(nomes, 820, sizeof(Lista), ordena);



    printf("Lista em HTML criada com sucesso...Aguarde!\n");
    int g = 0;
    int j,c=10;
       for ( g= 0; g < 10; g++) {
        printf("Carregando:%d", c);
        c+=10;

        for (j = 0; j < 40; j++) {
            //printf("");
            Sleep(5);
        }
        printf("\r");
        for ( j = 0; j < 60; j++) {
            printf(" "); // apaga a linha anterior
        }
        printf("\r");
    }


//----------------------------------------------------------------------------- gerando
		fprintf(winners, "<h1>Ganhadores com Letra R</h1>\n");
		fprintf(winners, "<meta http-equiv=""Content-Type" "content=""text/html""; charset=utf-8"">\n");
		fprintf(winners, "<ul>\n");
//----------------------------------------------------------------------------- pegando arquivo ordenado gerado e separando os cuqe começam com a letra R
	    while( (fgets(info, sizeof(info), arquivo))!=NULL ){

			fprintf(Ordenado, "%s",info);

		    	if(info[0] == 'R' || info[0] == 'r'){
		    		fprintf(winners, " <li> %s </li> \n", info);
		  		}
	    }

	    fprintf(winners, "\n</ul>");
	}
//-----------------------------------------------------------------------------	Fechar arquivos
	fclose(arquivo);
	fclose(Ordenado);
	fclose(winners);
//-----------------------------------------------------------------------------
    system("winners.html");

	return 0;
}

