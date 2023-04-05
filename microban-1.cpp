/**
    Estrutura inicial para um jogo de labirinto
    versão: 0.1 (Felski)
*/
#include <iostream>
#include<windows.h>
#include<conio.h>
#define BLACK        0
#define WHITE        7

using namespace std;

void cor_texto (int fonte, int fundo=0) {
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), (WORD) (fonte | fundo<<4));
}

// Menu do jogo
    // Novo jogo.
void novoJogo (){
  cout << "Novo jogo !" << endl;
}

    //continuar o jogo
void continuar(){
   cout << " Continuar jogo... " << endl;
}


void sobre(){
    cout << "Criado por Miguel Angel Moran. " << "\n Professor: Thiago Felski Pereira. Ciencias da Comutacao " << "\n 05/04/2023 " <<  endl;
}




int main()
{

       // Começo do Menu.
/*
   int opcao;
   do {
    cout << "MENU "<< endl;
    cout << "1. Novo Jogo " << endl;
    cout << "2. Continuar " << endl;
    cout << "3. Sobre " << endl;
    cout << "4. Fim " << endl;
    cout << " Escolha uma opcao : ";
    cin >> opcao;


   switch (opcao) {
    case 1:
        novoJogo();
        break;
    case 2:
        continuar();
        break;
    case 3:
         sobre();
        break;
    case 4:
        cout << "fim de jogo. " << endl;
        break;
    default:
        cout << "opcao invalida. Tente novamente. " << endl;
   }
   }

    while (opcao!= 4);
*/


    ///ALERTA: N�O MODIFICAR O TRECHO DE C�DIGO, A SEGUIR.
        //INICIO: COMANDOS PARA QUE O CURSOR N�O FIQUE PISCANDO NA TELA
        HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO     cursorInfo;
        GetConsoleCursorInfo(out, &cursorInfo);
        cursorInfo.bVisible = false; // set the cursor visibility
        SetConsoleCursorInfo(out, &cursorInfo);
        //FIM: COMANDOS PARA QUE O CURSOR N�O FIQUE PISCANDO NA TELA
        //IN�CIO: COMANDOS PARA REPOSICIONAR O CURSOR NO IN�CIO DA TELA
        short int CX=0, CY=0;
        COORD coord;
        coord.X = CX;
        coord.Y = CY;
        //FIM: COMANDOS PARA REPOSICIONAR O CURSOR NO IN�CIO DA TELA
    ///ALERTA: N�O MODIFICAR O TRECHO DE C�DIGO, ACIMA.

    int m[9][7]={   1,1,1,1,1,8,8,
                    1,0,0,1,1,8,8,
                    1,0,0,1,1,8,8,
                    1,0,0,1,1,1,1,
                    1,0,0,1,1,1,1,
                    1,3,2,2,0,1,1,
                    1,0,0,3,0,1,1,
                    1,0,0,1,1,1,1,
                    1,1,1,1,1,8,8 };

    //Posi��o inicial do personagem no console
    int x=6, y=4;

    //caja
    char caja=35;

    char local=158;

    char vacio=96;

    //Vari�vel para tecla precionada
    char tecla;

    while(true){
        ///Posiciona a escrita no início do console
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

        ///Imprime o jogo: mapa e personagem.
        for(int i=0;i<9;i++){
            for(int j=0;j<7;j++){
                if(i==x && j==y){
                    cout<<char(2); //personagem
                } else {
                    switch (m[i][j]){
                        case 0: cout<<" "; break; //caminho
                        case 1: cout<<char(219); break; //parede
                        case 2: cout<<caja; break; //caija
                        case 3: cout<<local; break; //local
                        case 4: cout<<vacio; break; //vacio
                        //default: cout<<"#"; //erro
                    } //fim switch
                }
            }
            cout<<"\n";
        } //fim for mapa

        //caja

        ///executa os movimentos
         if ( _kbhit() ){
            tecla = getch();
            switch(tecla)
{
    case 72: case 'w': ///cima
        if(m[x-1][y] != 1) {
            if (m[x-1][y] == 2 && m[x-2][y] != 1 && m[x-2][y] != 2) {
                m[x-2][y] = 2; // move a caixa
                m[x-1][y] = 0; // remove a caixa da posição anterior
            } else if (m[x-1][y] != 2) {
                x--;
            }
        }
        break;
    case 80: case 's': ///baixo
        if(m[x+1][y] != 1) {
            if (m[x+1][y] == 2 && m[x+2][y] != 1 && m[x+2][y] != 2) {
                m[x+2][y] = 2;
                m[x+1][y] = 0;
            } else if (m[x+1][y] != 2) {
                x++;
            }
        }
        break;
    case 75:case 'a': ///esquerda
        if(m[x][y-1] != 1) {
            if (m[x][y-1] == 2 && m[x][y-2] != 1 && m[x][y-2] != 2) {
                m[x][y-2] = 2;
                m[x][y-1] = 0;
            } else if (m[x][y-1] != 2) {
                y--;
            }
        }
        break;
    case 77: case 'd': ///direita
        if(m[x][y+1] != 1) {
            if (m[x][y+1] == 2 && m[x][y+2] != 1 && m[x][y+2] != 2) {
                m[x][y+2] = 2;
                m[x][y+1] = 0;
            } else if (m[x][y+1] != 2) {
                y++;
            }
        }
        break;
}
         }


    } //fim do laço do jogo

    return 0;
} //fim main
