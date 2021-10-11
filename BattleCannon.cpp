#include <iostream>
#include <windows.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
#include <ctime>

using namespace std;

#define ESPACO 32

void gotoxy(int coluna, int linha){
COORD coordenada;
coordenada.X = coluna;
coordenada.Y = linha;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordenada);
}

enum DOS_COLORS {
    BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN,
    LIGHT_GRAY, DARK_GRAY, LIGHT_BLUE, LIGHT_GREEN, LIGHT_CYAN,
    LIGHT_RED, LIGHT_MAGENTA, YELLOW, WHITE
};
void textColor(DOS_COLORS iColor);

int forca=0;
int acerto=0;
int forcaTotal;
char caracter, tecla;
int angulo;
int vidaTotal = 5, vidaTotal2 = 5;
char vida = 3;
char bala = 42;
char canhao = 254;
char canhao2 = 219;
char cano = 205;
int x = 0;
int y = 12;
int pontos;
int pontos2;
string barra = "";

int yNovo = y;
int yVelho = y;
int variacaoY = 0;

int xNovo = 0;
int xVelho = 0;
int variacaoX = 0;

///////////////////////////////////

int yNovo2 = y;
int yVelho2 = y;
int variacaoY2 = 0;

int xNovo2 = 0;
int xVelho2 = 0;
int variacaoX2 = 0;

/////////////////////////////////////////

int xBaseCanhao1 = 0;
int xCorpoCanhao1 = 0;
int xCanoCanhao1 = 0;
int yBaseCanhao1 = 0;
int yCorpoCanhao1 = 0;
int yCanoCanhao1 = 0;

int xBaseCanhao2 = 0;
int xCorpoCanhao2 = 0;
int xCanoCanhao2 = 0;
int yBaseCanhao2 = 0;
int yCorpoCanhao2 = 0;
int yCanoCanhao2 = 0;

    string Mapa[15][77]={
"                                   /\\                                    ",
"                              /\\  /  \\                                  ",
"                       /\\    /  \\/    \\        /\\                     ",
"                      /  \\  /   /      \\  /\\  /  \\                    ",
"         /\\          /  ^ \\/^ ^/^  ^  ^ \\/^ \\/  ^ \\                   ",
"        / ^\\    /\\  / ^   /  ^/ ^ ^ ^   ^\\ ^/  ^^  \\                   ",
"       /^   \\  / ^\\/ ^ ^   ^ / ^  ^    ^  \\/ ^   ^  \\       *         ",
"      /  ^ ^ \\/^  ^\\ ^ ^ ^   ^  ^   ^   ____  ^   ^  \\     /|\\        ",
"     / ^ ^  ^ \\ ^  _\\___________________|  |_____^ ^  \\   /||o\\       ",
"    / ^^  ^ ^ ^\\  /______________________________\\  ^ ^\\ /|o|||\\     ",
"   /  ^  ^^ ^ ^  /________________________________\\  ^  /|||||o|\\      ",
"  /^ ^  ^ ^^  ^    ||___|___||||||||||||___|__|||      /||o||||||\\       ",
" / ^   ^   ^    ^  ||___|___||||||||||||___|__|||          | |            ",
"/ ^ ^ ^  ^  ^  ^   ||||||||||||||||||||||||||||||oooooooooo| |            ",
"oooooooooooooooooooooooooooooo~~~~~~~~~~ooooooooooooooooooooooooooooooooo"
};


string Mapa2[15][66]={
"                                                                ",
"  ^  ^  ^   ^      ___I_      ^  ^   ^  ^  ^   ^  ^             ",
" /|\\/|\\/|\\ /|\\    /\\-_--\\    /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\",
" /|\\/|\\/|\\ /|\\   /  \\_-__\\   /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\",
" /|\\/|\\/|\\ /|\\   |[]| [] |   /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\ ",
"                                                                ",
" ^  ^  ^          ^  ^   ^  ^  ^   ^  ^       ^  ^   ^  ^  ^   ^  ^        ",
"/|\\/|\\/|\\        /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\     /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\",
"/|\\/|\\/|\\        /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\     /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\",
"/|\\/|\\/|\\        /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\     /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\ ",
"",
"",
"",
"",
" ooooooooooooooooooooooooooooooo~~~~~~~~~~~ooooooooooooooooooooooooooooooooo",
};

string Mapa3[15][59]={
"",
"",
"",
"                                 .|                           ",
"                                 | |                          ",
"                                 |'|            ._____        ",
"                         ___    |  |            |.   |' .----|",
"                 _    .-'   '-. |  |     .--'|  ||   | _|    |",
"              .-'|  _.|  |    ||   '-__  |   |  |    ||      |",
"              |' | |.    |    ||       | |   |  |    ||      |",
" _____________|  '-'     '    ""       '-'     '-.'    '`      |___________",
"",
"",
"_______________________________^^^^^^^^^^^_________________________________",
"",
};

    void Imprime(){
    for(int i=0; i<15; i++ ) {
        for(int j=0; j<15; j++) {
            gotoxy(i,j);
            textColor(WHITE);
            cout << Mapa [i][j];
        }
    }
    }

    void Imprime3(){
        for(int i=0; i<15; i++ ) {
        for(int j=0; j<15; j++) {
            gotoxy(i,j);
            textColor(WHITE);
            cout << Mapa3 [i][j];
        }
    }
    }

    void Imprime2(){
            for(int i=0; i<15; i++ ) {
            for(int j=0; j<15; j++) {
                gotoxy(i,j);
                textColor(WHITE);
                cout << Mapa2 [i][j];
            }
    }
    }

class Movs{

public:

    void setCourseJ1(int x, int s0y, int vx, int vy, int t){
        courseS0x = x;
        courseS0y = s0y;
        courseVx = vx;      /// vari�veis utilizadas na conta ///
        courseVy = vy;
        courseT = t;
    }

        void setCourseJ2(int x, int s0y, int vx, int vy, int t){
        courseS0x = x;
        courseS0y = s0y;
        courseVx = vx;      /// vari�veis utilizadas na conta ///
        courseVy = vy;
        courseT = t;
    }

    void setCourseSx(int sx){
        courseSx = sx;
    }
    void setCourseSy(int sy){ /// sx e sy s�o variaveis separadas para n�o entrar valor ///
        courseSy = sy;
    }

    int mru(int t){
        xNovo = courseS0x + courseVelX * t;
        setCourseSx(courseS0x + courseVelX * t); /// realiza��o do calculo MUV ///
        variacaoX = xNovo-xVelho;
        if (variacaoX < 0)
        {
            variacaoX = variacaoX * (-1);
        }
       return xNovo;
    }

    int mru2(int t){
        xNovo2 = courseS0x + courseVelX * t;
        setCourseSx(courseS0x + courseVelX * t); /// realiza��o do calculo MUV ///
        variacaoX2 = xNovo2-xVelho2;
        if (variacaoX2 < 0)
        {
            variacaoX2 = variacaoX2 * (-1);
        }
       return xNovo2;
    }

    int courseSx, courseS0x, courseVx, courseSy, courseVy, courseS0y, courseT; /// declara��o de todas as vari�veis ///
    float  courseVelX, courseVelY, vex, vey;

    int MRUV(int t){
        yNovo = courseS0y + courseVelY * t + 0.5 * pow(t, 2);
        setCourseSy(courseS0y + courseVelY * t + 0.5 * pow(t, 2)); /// calculo do MRUV ///
        variacaoY = yNovo-yVelho;
        if (variacaoY < 0)
        {
            variacaoY = variacaoY * (-1);
        }
       return yNovo;
    }

    int MRUV2(int t){
        yNovo2 = courseS0y + courseVelY * t + 0.5 * pow(t, 2);
        setCourseSy(courseS0y + courseVelY * t + 0.5 * pow(t, 2)); /// calculo do MRUV ///
        variacaoY2 = yNovo2-yVelho2;
        if (variacaoY2 < 0)
        {
            variacaoY2 = variacaoY2 * (-1);
        }
       return yNovo2;
    }


    void SorteiaMapa(int maparand){

    switch(maparand){

case 1:
    Imprime();
    break;
case 2:
    Imprime2();
    break;
case 3:
    Imprime3();
    break;
    }

    }


        void For_Bala()
    {
        caracter = getch();

        switch(caracter){

        case ESPACO:

        if(forca < 10){
        for(int c = 1; c < 11; c++){

        if(kbhit()){
            char tiro = getch();
            if(tiro==ESPACO){
                break;
            }
        }

       forca +=1;
       textColor(YELLOW);
       barra += "&";
       gotoxy(21,17);
       cout << barra;

       gotoxy(21,19);
       cout << forca;
       Sleep(100);
        }
        }
        break;
        }
    }

    void AplicaVento(int direcaoV, int forcaV){

    switch(direcaoV){

      case 1: {       /// VENTO NORTE ///
        vex -= forcaV;
        gotoxy(24,23);
        cout << "Direcao do Vento: Norte";
        gotoxy(24,24);
        cout << "Forca do Vento: " << forcaV;
        break;
    }

      case 2: {       /// VENTO SUL ///
        vex += forcaV;
        gotoxy(24,23);
        cout << "Direcao do Vento: Sul";
        gotoxy(24,24);
        cout << "Forca do Vento: " << forcaV;
        break;
    }

      case 3: {       /// VENTO lESTE ///
        vex += forcaV;
        gotoxy(24,23);
        cout << "Direcao do Vento: Leste";
        gotoxy(24,24);
        cout << "Forca do Vento: " << forcaV;
        break;
    }

      case 4: {       /// VENTO OESTE ///
        vex -= forcaV;
        gotoxy(24,23);
        cout << "Direcao do Vento: Oeste";
        gotoxy(24,24);
        cout << "Forca do Vento: " << forcaV;
        break;
    }

      case 5: {       /// VENTO SUDOESTE ///
        vex += (forcaV * 0.7071);
        vey -= (forcaV * 0.7071);
        gotoxy(24,23);
        cout << "Direcao do Vento: Sudoeste";
        gotoxy(24,24);
        cout << "Forca do Vento: " << forcaV;
        break;
    }

      case 6: {       /// VENTO NOROESTE ///
        vey -= (forcaV * 0.7071);
        vex -= (forcaV * 0.7071);
        gotoxy(24,23);
        cout << "Direcao do Vento: Noroeste";
        gotoxy(24,24);
        cout << "Forca do Vento: " << forcaV;
        break;
    }

      case 7: {       /// VENTO SUDESTE ///
        vey += (forcaV * 0.7071);
        vex += (forcaV * 0.7071);
        gotoxy(24,23);
        cout << "Direcao do Vento: Sudeste";
        gotoxy(24,24);
        cout << "Forca do Vento: " << forcaV;
        break;
    }
      case 8: {       /// VENTO NORDESTE ///
        vey -= (forcaV * 0.7071);
        vex += (forcaV * 0.7071);
        gotoxy(24,23);
        cout << "Direcao do Vento: Nordeste";
        gotoxy(24,24);
        cout << "Forca do Vento: " << forcaV;
        break;
    }

    }
    }


    void VelX(int vex){
    courseVelX = vex;
    }

    void VelY(int vey){
    courseVelY = vey;
    }

    void EquacaoX(){
    VelX(forcaTotal * cos(angulo*3.14/180));
    }

    void Equacaoy(){
    VelY(forcaTotal * -sin(angulo*3.14/180));
    }

    void EquacaoX2(){
    VelX(forcaTotal * -cos(angulo*3.14/180));
    }

    void Equacaoy2(){
    VelY(forcaTotal * -sin(angulo*3.14/180));
    }

    void movimentoOblicoJ1(){
        for(int i = 0; i < courseT; i++){
            EquacaoX();
            Equacaoy();
            xVelho = mru(i);
            yVelho = MRUV(i);
            if (i>5)
            {
                for(int auxX=xVelho; auxX < xVelho+variacaoX; auxX++)
                {
                    for(int auxY = yVelho; auxY < yVelho+variacaoY; auxY++)
                    {
                           gotoxy(auxX,auxY);
                           if(acerto != 1 && ((auxX == xBaseCanhao2 && auxY == yBaseCanhao2) || (auxX == xCorpoCanhao2 && auxY == yCorpoCanhao2) || (auxX == xCanoCanhao2 && auxY == yCanoCanhao2))){
                                vidaTotal2--;
                                acerto = 1;
                           }

                    }
                }
            }
    if(acerto == 1 || yNovo>13)
       {
        i = courseT;
       }
    else
    {
        gotoxy(courseSx, courseSy);     /// For do Movimento Oblico que � a jun��o do MUV com MRUV ///
        cout << bala;
    }
        Sleep(200);

    }
    }

    void movimentoOblicoJ2(){
    for(int f = 0; f < courseT; f++){
            EquacaoX2();
            Equacaoy2();
            xVelho2 = mru2(f);
            yVelho2 = MRUV2(f);
            if (f>4)
            {
                if(acerto==0){
                    for(int auxX2=xVelho2; auxX2 > xVelho2-variacaoX2; auxX2--)
                    {
                        for(int auxY2 = yVelho2; auxY2 < yVelho2+variacaoY2; auxY2++)
                        {
                                gotoxy(auxX2,auxY2);
                               if(acerto != 1 && ((auxX2 == xBaseCanhao1 && auxY2 == yBaseCanhao1) || (auxX2 == xCorpoCanhao1 && auxY2 == yCorpoCanhao1) || (auxX2 == xCanoCanhao1 && auxY2 == yCanoCanhao1))){
                                    vidaTotal--;
                                    acerto = 1;
                                }
                        }
                    }
                }
            }
       if(acerto == 1 || yNovo2>13)
       {
        f = courseT;
       }
       else
       {
        gotoxy(courseSx, courseSy);     /// For do Movimento Oblico que � a jun��o do MUV com MRUV ///
        cout << bala;
       }
        Sleep(200);
    }
    }

};

void Jog1(int x, char canhao, char canhao2, char cano){

        gotoxy(x,y+1);
        textColor(LIGHT_RED);
        cout << canhao;
        gotoxy(x,y);
        cout << canhao2;
        gotoxy(x+1,y);
        cout << cano;
        gotoxy(x+1,y+1);
        cout << canhao;
        gotoxy(x-1,y+1);
        cout << canhao;

        xBaseCanhao1 = x-1;
        xCorpoCanhao1 = x;
        xCanoCanhao1 = x+1;
        yBaseCanhao1 = y+1;
        yCorpoCanhao1 = y;
        yCanoCanhao1 = y;
}
///---------------------Canhao 2--------------------------///
void Jog2(int x, char canhao, char canhao2, char cano){
        gotoxy(x+41,y+1);
        textColor(LIGHT_CYAN);
        cout << canhao;
        gotoxy(x+41,y);
        cout << canhao2;
        gotoxy(x+40,y);
        cout << cano;
        gotoxy(x+42,y+1);
        cout << canhao;
        gotoxy(x+40,y+1);
        cout << canhao;

        xBaseCanhao2 = x+40;
        xCorpoCanhao2 = x+41;
        xCanoCanhao2 = x+40;
        yBaseCanhao2 = y+1;
        yCorpoCanhao2 = y;
        yCanoCanhao2 = y;

 }

 void VidasJog1(){
 gotoxy(5,20);
 textColor(LIGHT_RED);
 for(int a=1; a<=vidaTotal; a++){
    cout << vida;
    }
 }

void VidasJog2(){

 gotoxy(65,20);
 textColor(LIGHT_CYAN);
 for(int c=1; c<=vidaTotal2; c++){
    cout << vida;
    }
}


int main(){

Movs movimento;
int jogo = 1;
while(jogo){

barra = "";
forca=0;
srand(time(0));
x = rand()%25 +1;
int forcaV = rand()%4;
int direcaoV = (rand()%8)+1;
int maparand = (rand()%3)+1;


    movimento.SorteiaMapa(maparand);
    movimento.AplicaVento(direcaoV,forcaV);


    Jog1(x, canhao,canhao2,cano);
    Jog2(x, canhao,canhao2,cano);
    VidasJog1();
    VidasJog2();

    acerto=0;
    while(true){
    forca=0;
    barra = "";
    gotoxy(5,16);
    textColor(LIGHT_RED);
    cout << "Jogador 1 inserir angulo: ";
    cin >> angulo;
    gotoxy(5,17);
    cout << "Barra de forca: ";

    movimento.For_Bala();
    forcaTotal = forca + forcaV;
    movimento.setCourseJ1(x+2,12,3,-3,15);
    movimento.movimentoOblicoJ1();
    system("cls");
    break;
}

    Imprime();
    movimento.AplicaVento(direcaoV,forcaV);
    Jog1(x, canhao,canhao2,cano);
    Jog2(x, canhao,canhao2,cano);
    VidasJog1();
    VidasJog2();

    acerto=0;

     if(vidaTotal2<=0){
        system("cls");
        textColor(LIGHT_RED);
        cout << "Jogador 1 Venceu!" << endl;
        jogo=0;
        break;
    }

    while(true){
    forca=0;
    barra = "";
    gotoxy(5,16);
    textColor(LIGHT_CYAN);
    cout << "Jogador 2 inserir angulo: ";
    cin >> angulo;
    gotoxy(5,17);
    cout << "Barra de forca: ";
    movimento.For_Bala();
    forcaTotal = forca + forcaV;
    movimento.setCourseJ2(x+38,12,3,-3,15);
    movimento.movimentoOblicoJ2();
    system("cls");
    break;
    }

    if(vidaTotal<=0){
        system("cls");
        textColor(LIGHT_CYAN);
        cout << "Jogador 2 Venceu!" << endl;
        jogo = 0;
        break;
    }

}

}

void textColor(DOS_COLORS iColor) {
    HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
    bufferInfo.wAttributes &= 0x00F0;
    SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= iColor);
}
