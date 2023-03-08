#include <iostream> 

using namespace std; 

void Jugar(); 
void Limpiar(); 
void Limpant(); 
void Mostrartablero();
void Ubicarfich();
bool RevisarH(int,int,char);
bool RevisarV(int,int,char);
bool RevisarD(int,int, char);
bool RevDiagInvertida(int,int,char);

char t[6][7]={' '},{' '},{' '},{' '},{' '},{' '},{' '}, 

             {' '},{' '},{' '},{' '},{' '},{' '},{' '}, 

             {' '},{' '},{' '},{' '},{' '},{' '},{' '}, 

             {' '},{' '},{' '},{' '},{' '},{' '},{' '}, 

             {' '},{' '},{' '},{' '},{' '},{' '},{' '}, 

             {' '},{' '},{' '},{' '},{' '},{' '},{' '},; 

              

char eleccion; 
char turno; 
int colT,colD,indD,h,k;
int contador= 0
bool listo = false;

int main(){ 

    while(true){ 

        Limpant(); 

        cout<<" Este juego se llama 4 en raya: "<<endl; 

        cout<<" Pulse 1 si desea jugar."<<endl; 

        cout<<" Pulse 2 para Salir."<<endl; 

        cout<<" Pulse el número de la opción que desea hacer: "; 

        cin>>eleccion; 

    switch(eleccion){ 

case '1': 

    turno = '0'; 

    Jugar(); 

    Limpiar(); 

    break; 

case '2': 

    return 0; 

    break; 

default: 

    cout<<" Esta opción no existe. Pulse cualquier carácter para continuar: "; 

    cin>>eleccion; 

    break; 

    } 

    } 

return 0; 

} 

void Limpant(){ 

if(system("clear"))== -1){ 

    cout<<"Errror para limpiar la pantalla."<<endl; 

    Limpant(); 

} 

} 

void Limpiar(){ 

for (int i=0; i<6;i++){ 

    for(int j= 1; j<7; j++){ 

        tablero[i][j] = ' '; 

        } 

    } 

} 

 
 

void Jugar(){ 

    Limpant(); 

    Mostrartablero(); 
if( RevisarH(indD,colD,turno) || RevisarV(indD,colD,turno) || RevisarD(indD,colD,turno) || RevDiagInvertida(indD,colD,turno)){
    cout<<"Ingrese cualquier caracter para seguir: "<<endl;
    cin>>eleccion;
    return;
}

 

    if(turno =='X'){ 

        turno = 'O'; 

    } 

    else{ 

        turno = 'X'; 

    } 

    cout<<"Turno de "<<turno<<endl; 
    cout<<"Eliga en que columna quiere situarse: ";
    cin>>colT;
    if (colT>7 and colT<1)
    {
        cout<<"Esta columna no existe. Ingrese cualquier caracter para seguir: ";
        cin>>eleccion;
        Jugar();
    }
    else{
        colD=colT;
        Ubicarfich();
    }
    Jugar();

} 

 
 

void Mostrartablero(){ 

    for(int f=0;f <6; f++){ 

        cout<<endl; 

        for(int c = 0; c <7; c++){ 

            cout<<tablero[f][c]<<" "; 

         

        } 

    } 

} 


void Ubicarfich(){
for(int f=0;f <6; f++){ 

        if (tablero[i][colD]==' ')
        {
          if (i > 0)
          {
            tablero[i-1][colD]= ' ';
          }
            tablero[i][colD]= turno;
            indD= i;
        }    
    }
} 
 
 bool RevisarH(int i, int j, char t){
cont = 1;
h=j;
listo = false;

while (!listo)
{
    h--;
    if (h>0)
    {
        if (tablero[i][h]==t)
        {
            cont++;
        }
        else{
            listo= true;
        }
        
    }
    else
    {
        listo = true;
    }
    
}
h=j;
listo = false;

while (!listo)
{
    h++;
    if (h<7)
    {
        if (tablero[i][h]==t)
        {
            cont++;
        }
        else{
            listo= true;
        }
        
    }
    else
    {
        listo = true;
    }
    
}
if (cont >=4)
{
    cout<<"Ganó el jugador: "<<t<<endl;
    return true;
}
return false;
 }

bool RevisarV(int i, int j, char t){
cont = 1;    
h=i;
listo = false;
while (!listo)
{
    h++;
    if (h<6)
    {
        if (tablero[h][j]==t)
        {
            cont++;
        }
        else{
            listo= true;
        }
        
    }
    else
    {
        listo = true;
    }
    
}
if (cont>=4)
{
    cout<<"Ganó el jugador: "<<t<<endl;
    return true;
}
return false;
}
 
 bool RevisarD(int i, int j, char t){
    cont = 1;
k=j;
h=j;
listo = false;

while (!listo)
{
    h++;
    k--;
    if (h < 6 and k > 0)
    {
        if (tablero[h][k]==t)
        {
            cont++;
        }
        else{
            listo= true;
        }
        
    }
    else
    {
        listo = true;
    }
    
}
h=i;
k=j;
listo = false;

while (!listo)
{
    h--;
    k++;
    if (h>0 and k<7)
    {
        if (tablero[h][k]==t)
        {
            cont++;
        }
        else{
            listo= true;
        }
        
    }
    else
    {
        listo = true;
    }
    
}
if (cont >= 4)
{
    cout<<"Ganó el jugador:"<<t<<endl;
    return true;
}
return false;
 }

 bool Rev<RevDiagInvertida(int i, int j, char t){
    cont = 1;
k=j;
h=i;
listo = false;

while (!listo)
{
    h++;
    k++;
    if (h < 6 and k < 7)
    {
        if (tablero[h][k]==t)
        {
            cont++;
        }
        else{
            listo= true;
        }
        
    }
    else
    {
        listo = true;
    }
    
}
h=i;
k=j;
listo = false;

while (!listo)
{
    h--;
    k--;
    if (h>0 and k>0)
    {
        if (tablero[h][k]==t)
        {
            cont++;
        }
        else{
            listo= true;
        }
        
    }
    else
    {
        listo = true;
    }
    
}
if (cont >= 4)
{
    cout<<"Ganó el jugador:"<<t<<endl;
    return true;
}
return false;
 }
