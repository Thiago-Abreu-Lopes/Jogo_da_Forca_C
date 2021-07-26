#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<string.h>

main()
{	
	char continuar;
	do{
		//---------------------------Sorteador da palavra no arquivo <palavra.txt> -------------------------
		
		char palavras_da_lista[100][20];
		int palavras,numero_aleatorio;
		
		FILE*arquivo_com_palavras; 
		arquivo_com_palavras=fopen("palavras.txt","r");
		if(arquivo_com_palavras==NULL){ 
			printf("ERRO AO ABRIR O ARQUIVO!!!");
			return 1;
			} // verifica se foi possivel ler o arquivo com as palavras
			
		for(palavras=0;palavras<100;palavras++){  
			fscanf(arquivo_com_palavras,"%s",palavras_da_lista[palavras]);
		} // preenche o vetor palavras_da_lista com as palavras da lista :D
		
		srand(time(NULL));   
		numero_aleatorio=rand()%99; //a variavel numero_aleatorio recebe um numero aleatorio de 0 a 99  
		      
		//--------------------------------------------------------------------------------------------------
		//------------------------------Implementação das etapas do jogo------------------------------------
		int  chances = 6; 
		int indice; 
		char letra;
		int tamanho_da_palavra = strlen(palavras_da_lista[numero_aleatorio]); 
		int verificador2 = 0; // se for 0 NÃO acertou a palavra, se for 1 acertou a palavra
		int verificador = 0;  // se for 0 NÃO acertou a letra, se for 1 acertou a letra	
		char palavra_secreta[tamanho_da_palavra]; 
		
		
		for (indice = 0;indice<tamanho_da_palavra;indice++ ) {
			palavra_secreta[indice] = '_';
		} // preenche o vetor palavra_secreta com '_' representando as letras que faltam ser descobertas
		while(chances>0){
			printf("\nChances: %d\n", chances);
			for (indice = 0;indice<tamanho_da_palavra;indice++ ) {
				printf("%c ",palavra_secreta[indice]);
			} // imprime a palavra_secreta
			
			printf("\n\nDigite uma letra :\n");
			setbuf(stdin, NULL); 
			scanf("%c",&letra);  // coleta a letra que sera verificada
			
			for(indice = 0;indice<tamanho_da_palavra;indice++) 	{
				if (palavras_da_lista[numero_aleatorio][indice] == letra){ //verifica se a letra esta presenta na palavra sorteada
					palavra_secreta[indice] = letra; // se a letra estiver ela é substituida na palavra_secreta
					verificador = 1; 
					int indice2 = strncmp(palavras_da_lista[numero_aleatorio],palavra_secreta, tamanho_da_palavra); 
					//^ compara a palavra secreta com a palavra sorteada
					if(indice2 == 0){ 
						printf("\n VOCE ACERTOU !! :D \n A palavra era: %s\n",palavras_da_lista[numero_aleatorio]);
						verificador2 = 1;
						break; 
					} // verifica se a palavra foi completamente descoberta
				}
			}
			if (verificador2 == 1){
				break; 
			} // verifica se a palavra foi completamente descoberta
			if (verificador == 0){
				chances--;
			}else{
				verificador = 0;
			}// verifica se a letra foi completamente descoberta e prepara para a proxima comparação
			
		}
		if(chances == 0){
			printf("\n VOCE ERROU!! :( \nA palavra era: %s\n",palavras_da_lista[numero_aleatorio]);
		} // reduz as chances em caso de erros
		printf("Deseja continuar: aperte s para continuar ou aperte n para nao prosseguir\n");
		setbuf(stdin, NULL);
		scanf("%c", &continuar);
		system("cls"); // limpa o terminal
		//--------------------------------------------------------------------------------------------------	
	}while(continuar == 's');
	
	
}

