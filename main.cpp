#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <time.h>

using namespace std;


void limpaTela(){
	system("CLS");
}


string retornaPalavraAleatoria(){
	
	string palavras[25] = {"Bicicleta" , "Roteador", "Cadeira", "Fliperama", "Computador", "Condicionador", "Prato", "Espertador", "Console", "Armario", "Refrigerante", "Televisao", "Vitrine", "Cadeado", "Chinelo", "Ventilador", "Escada" , "Fantasia", "Caminhao", "Guardanapo", "Guitarra", "Poltrona","Pincel", "Jabiroca", "Tupperware"};
	
	//indice gerado no intervalo (0,1,2);
	int indiceAleatorio = rand() % 25;
	
	//Exibe a palavra aleatorio
	//cout << palavras[indiceAleatorio];
	
	return palavras[indiceAleatorio];
	
}


string retornaPalavraComMascara(string palavra, int tamanhoDaPalavra){
	
	int i = 0;
	string palavraComMascara;
	
	//coloca a mascara
	while(i < tamanhoDaPalavra){
		palavraComMascara += "_";
		i++;
	}
	return palavraComMascara;
}

void exibeStatus(string palavraComMascara, int tamanhoDaPalavra, int tentativasRestantes, string letrasJaArriscadas,string mensagem){
	    
		//cout << "A palavra secreta eh " << palavra << " Tamanho:" << tamanhoDaPalavra << ")";
		cout << mensagem;
		cout << "\nDica -> Objeto do cotidiano.\n";
        cout << "\nPalavra: " << palavraComMascara << " (Tamanho:"<< tamanhoDaPalavra << ")";
		cout << "\n\nTentativas restantes:\n" << "(" <<tentativasRestantes << ")";
		
		//exibe as letras arriscadas
		int i;
		cout << "\nLetras Arriscadas:\n";
		for(i < 0;i < letrasJaArriscadas.size(); i++){
			cout << letrasJaArriscadas[i] << ", ";
		}
		
		
		
		
		
}
          
int jogar(int numeroDeJogadores){
	
	//palavra a ser adivinhada
	string palavra;
	
    
    
    //confere o numero de jogadores
    if(numeroDeJogadores == 1){
    		//palavra a ser adivinhada
	        palavra = retornaPalavraAleatoria();
	}else{
			
		cout <<"\n ----- Modo multiplayer selecionado -----\n";
		cout << "\nDigite uma palavra:";
		cin >> palavra;
	}

	//tamanho da palavra
	int tamanhoDaPalavra = palavra.size();
	
	//palavra mascarada
	string palavraComMascara = retornaPalavraComMascara(palavra, tamanhoDaPalavra);
	
	///Variaveis principais
	int tentativas = 0,maximoDeTentativas = 12;         // numeros de tentativas e erros
	int i = 0;
	char letra;                                         // letra arriscada pelo o usuário
	int opcao;                                          // opções finais
	string letrasJaArriscadas;                          //acumula as tentativas dos jogadores 
	string mensagem = "BOA SORTE NA JOGATINA";           //feedback do jogador
	bool jaDigitouLetra = false, acertouLetra = false; //auxiliar para saber se a letra já foi digitada
	                                            
	while(palavra != palavraComMascara && maximoDeTentativas - tentativas > 0){
		
		limpaTela();
		
		//exibe os status atual do jogo
		exibeStatus(palavraComMascara, tamanhoDaPalavra, maximoDeTentativas - tentativas, letrasJaArriscadas, mensagem);
		
		//le um palpite
		cout << "\nDigite uma letra:";
		cin >> letra;
		
		//percorre as letras já arriscadas
		for(i = 0; i < tentativas; i++){
			
			//Ao encontrar a letra
			if(letrasJaArriscadas[i] == (letra)){
				
				mensagem = "Deixa de ser lesado!\n";
				
				//Indica uma variavel booleana
				jaDigitouLetra = true;
			}
		}
		
		//se for uma letra nova
		if(jaDigitouLetra == false){
			
			
			letrasJaArriscadas += (letra);
		
		//percorre a palavra real e se a letra existir
		for(i = 0; i < tamanhoDaPalavra;i++){
			
			//se a letra existir na palavra escondida
			if(palavra[i] == (letra)){
				
				palavraComMascara[i] = palavra[i];
				
				acertouLetra = true;
				
				
			}
		}
		tentativas++;	
		
		if(acertouLetra == false){
		
		mensagem = "Errou feio, Errou rude.\n";
			
		}else{
			
		mensagem = "Acertou mizeravi!\n";	
		acertouLetra = false;
		}
	}
	//reinicia as auxiliares	
	jaDigitouLetra = false;
	acertouLetra = false;	
}
        
		if(palavra == palavraComMascara){
        	limpaTela();
        	cout << "\n     -----------------------------------------------------\n";
			cout << "     |PARABENS , VOCE MANJA DEMAIS JOVEM GAFANHOTO !!!!!!|";
			cout << "\n     -----------------------------------------------------";
			cout << "\n\nA palavra que estava escondida era: " << palavra;
			cout << "\n\n  -> Deseja voltar ao menu principal?\n";
			cout << "  -----------------------------------\n";
			cout << "\n1 -> Simbora\n";
			cout << "------------\n";
			cout << "\n2 -> Vou arregar\n";
			cout << "----------------\n";
			cout << "\nOpcao: ";
			cin >> opcao;
			//return opcao;
			if(opcao ==2)  {
		    cout << "\n";
            cout << "        -----------------------------\n";
            cout << "        | ATE MAIS , JOVEM PADAWAN! |\n";
            cout << "        -----------------------------";
            cout << "\n";
			return opcao;
	}
            
		}else{
			limpaTela();
			cout << "\n     -------------------------\n";
			cout << "     |PERDEU MEU CHAPA !!!!!!|";
			cout << "\n     -------------------------\n";
			cout << "\n\n  -> Deseja voltar ao menu principal?\n";
			cout << "  -----------------------------------\n";
			cout << "\n\n1 -> Simbora\n";
			cout << "------------\n";
			cout << "\n2 -> Vou arregar\n";
			cout << "----------------\n\n";
			cout << "Opcao: "; 
			cin >> opcao;
			//return opcao;
			if(opcao == 2){
		    cout << "\n";
            cout << "        -----------------------------\n";
            cout << "        | ATE MAIS , JOVEM PADAWAN! |\n";
            cout << "        -----------------------------";
            cout << "\n";
			return opcao;
	}
  }
}



void menuInicial(){
	
	//opcao
	int opcao = 0;
	
	//Quando o jogador não digita uma opcao válida, volta ao menu novamente
	while(opcao  < 1 || opcao > 3){
	
	limpaTela();
	cout << "  ----------------------------\n";
	cout << "  |BEM VINDO AO SURVIVOR WORD|\n";
	cout << "  ----------------------------\n";
	
	    cout << "           _________" ;
		cout << "\n             __|__" <<"\n               O\n  ";
		cout << "            /|\\\n";    
		cout << "             o | o  "    ;
		cout << "\n              / \\\n      ";  
	
	cout << "\n 1 -> Single Player\n";
	cout << " ------------------\n";
	cout << "\n 2 -> Multiplayer Local\n";
	cout << " ----------------------\n";
	cout << "\n 3 -> Sobre\n";
	cout << " ----------\n";
	cout << "\n 4 -> Sair\n";
	cout << " ---------\n";
	cout << "\n Escolha uma opcao e tecle ENTER:\n";
	cout << "\nOpcao: ";
	cin >> opcao;
	
	
	//faz algo de acordo com a opção escolhida
	switch(opcao){
		case 1:
			//inicia o jogo
			if(jogar(1) == 1){
				menuInicial();
			}
			break;
		case 2:
			//inicia o jogo
			if(jogar(2) == 1){
				menuInicial();
			}
			break;
		case 3:
			//mostra informações do jogo
			
			limpaTela();
			cout << "\n                    INFORMACOES DO JOGO:\n\n";
			cout << "      -----------------------------------------------------\n";
			cout << "      |Aluno universitario de Sistemas e Midias Digitais. |\n";
			cout << "      |Desenvolvedor: Wallace Leite, since 2020.          |";
			cout << "\n      |Desenvolvido na linguagem C e C++.                 |";
			cout << "\n      |Estagiario da empresa CALANGO COMPUTERS.           |";
			cout << "\n      -----------------------------------------------------\n";
			cout << "\n\n   1 -> Voltar ao menu principal\n";
			cout << "   -----------------------------\n";
	        cout << "\n   2 -> Sair do jogo\n";
	        cout << "   -----------------\n\n";
	        cout << "Opcao: ";
			cin >> opcao;
	        
	        
			if(opcao == 1){
	           menuInicial();
			}
		
		break;				
    }
        if(opcao != 1){
		cout << "\n";
        cout << "        -----------------------------\n";
        cout << "        | ATE MAIS , JOVEM PADAWAN! |\n";
        cout << "        -----------------------------";
        cout << "\n";
		 
		 }
        break;
        /*cout << "\n";
        cout << "        -----------------------------\n";
        cout << "        | ATE MAIS , JOVEM PADAWAN! |\n";
        cout << "        -----------------------------";
        cout << "\n";
		break;*/
  }
	
}

int main(){
	
	//Faz gerar numeros aleatórios
	srand( (unsigned)time(NULL));
	
    menuInicial();
	
	system ("PAUSE");
}
