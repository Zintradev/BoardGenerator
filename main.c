#include <stdio.h>
#include <stdlib.h>
#define BLANCO_F   "\x1b[47m"
#define NEGRO_F    "\x1b[40m"

void elecciondejuego(int select, int ancho, int largo, char linea, char columna, char esquinaizqsup, char esquinadchasup, char esquinaizqinf, char esquinadchainf, char tnormal, char tinvertida, char cruz, char tlateralizq ,char tlateraldcha);
void tresenraya(int ancho, int largo, char linea, char columna, char esquinaizqsup, char esquinadchasup, char esquinaizqinf, char esquinadchainf, char tnormal, char tinvertida, char cruz, char tlateralizq, char tlateraldcha);
void ajedrez(int ancho, int largo, char linea, char columna, char esquinaizqsup, char esquinadchasup, char esquinaizqinf, char esquinadchainf, char tnormal, char tinvertida, char cruz, char tlateralizq, char tlateraldcha);
void filasuperior(int ancho,int casillas, char linea, char esquinaizqsup, char esquinadchasup, char tnormal);
void filacentral(int ancho, int casillas, char linea, char cruz, char tlateralizq, char tlateraldcha);
void filacolumna(int ancho, int casillas, int largo, char columna);
void filacolumnanegra(int ancho, int casillas, int largo, char columna);
void filacolumnablanca(int ancho, int casillas, int largo, char columna);
void filainferior(int ancho, int casillas, char linea, char esquinaizqinf, char esquinadchainf, char tinvertida);


int main()
{
    int eleccion, tipolinea, anchura, longitud, repetir, casillas = 0;

    char linea, columna, esquinaizqsup, esquinadchasup, esquinaizqinf, esquinadchainf, tnormal, tinvertida, cruz, tlateralizq, tlateraldcha  = '\0';
    //ELECCION DE PARAMETROS DE LOS JUEGOS
    do{
        printf("\n\n\n\n\t\t\t\t\t\t***BIENVENIDO AL MENU***\n\n");
        printf("\t\tNotas a tener en cuenta:\n\t\t1.Para una proporcion cuadrada se recomienda poner la mitad de largo que de ancho ya que\n\t\tel caracter de longitud es mas largo que el de anchura\n\n\t\t2.Para el tres en raya se recomienda 10x5 y para el ajedrez se recomienda 4x2.\n\n\t\t3.Para los colores del ajedrez he usado #define para crear una macro que representa una secuencia\n\t\tde escape ANSI para establecer el color de fondo de los espacios en blanco.\n\n");

        do{
            printf("\t\tSi desea jugar al tres en raya pulse 1, si desea jugar al ajedrez pulse 2: ");
            scanf("%d",&eleccion);

            printf("\t\tPulse 1 para linea simple y 2 para linea doble: ");
            scanf("%d",&tipolinea);

            printf("\t\tQue anchura desea que tengan los cuadrados: ");
            scanf("%d",&anchura);

            printf("\t\tQue longitud desea que tengan los cuadrados: ");
            scanf("%d",&longitud);

            if(tipolinea<1 || tipolinea>2 || eleccion<1 || eleccion>2)(printf("\n\t\tError en los datos, intentelo de nuevo\n"));

        }while(tipolinea<1 || tipolinea>2 || eleccion<1 || eleccion>2);

        //TIPOS DE CARACTERES SEGUN ASCII PARA CADA LINEA,LINEA1 SIMPLE, LINEA 2 DOBLE
        if (tipolinea == 1) {
            linea = 196;
            columna = 179;
            esquinaizqsup = 218;
            esquinadchasup = 191;
            esquinaizqinf = 192;
            esquinadchainf = 217;
            tnormal = 194;
            tinvertida = 193;
            cruz = 197;
            tlateralizq = 195;
            tlateraldcha = 180;
        } else if (tipolinea == 2) {
            linea = 205;
            columna = 186;
            esquinaizqsup = 201;
            esquinadchasup = 187;
            esquinaizqinf = 200;
            esquinadchainf = 188;
            tnormal = 203;
            tinvertida = 202;
            cruz = 206;
            tlateralizq = 204;
            tlateraldcha = 185;
        }

        elecciondejuego(eleccion, anchura, longitud, linea,  columna,  esquinaizqsup,  esquinadchasup,  esquinaizqinf,  esquinadchainf, tnormal, tinvertida, cruz, tlateralizq, tlateraldcha);

        printf("\n\n\t\tSi esta satisfecho con el resultado pulse 1 para cerrar la aplicacion\n\t\tEn caso de que quiera repetir el proceso de creacion pulse cualquier numero distinto de 1: ");
        scanf("%d",&repetir);

        if(repetir==1)printf("\n\t\tGracias por su visita. :)\n");

    }while(repetir != 1);//SI SE PULSA OTRA TECLA QUE NO SEA 1 VUELVE A HACER TODO

}

//FUNCION PARA ELEGIR EL JUEGO

void elecciondejuego(int select, int ancho, int largo, char linea, char columna, char esquinaizqsup, char esquinadchasup, char esquinaizqinf, char esquinadchainf, char tnormal, char tinvertida, char cruz, char tlateralizq ,char tlateraldcha)
{
        if(select==1){
            printf("\t\tHa elegido tres en raya de %d de ancho y %d de largo\n",ancho,largo);
            tresenraya(ancho, largo, linea, columna, esquinaizqsup, esquinadchasup, esquinaizqinf, esquinadchainf, tnormal, tinvertida, cruz, tlateralizq, tlateraldcha);
        }

        if(select==2){
            printf("\t\tHa elegido ajedrez de %d de ancho y %d de largo\n",ancho,largo);
            ajedrez(ancho, largo, linea, columna, esquinaizqsup, esquinadchasup, esquinaizqinf, esquinadchainf, tnormal, tinvertida, cruz, tlateralizq, tlateraldcha);
        }
}

//FUNCION PARA DIBUJAR EL TRES EN RAYA

void tresenraya(int ancho, int largo, char linea, char columna, char esquinaizqsup, char esquinadchasup, char esquinaizqinf, char esquinadchainf, char tnormal, char tinvertida, char cruz, char tlateralizq, char tlateraldcha){

    filasuperior( ancho, 3, linea, esquinaizqsup, esquinadchasup, tnormal);
    filacolumna(ancho, 3, largo, columna);
    filacentral(ancho, 3, linea, cruz, tlateralizq, tlateraldcha);
    filacolumna(ancho, 3, largo, columna);
    filacentral(ancho, 3, linea, cruz, tlateralizq, tlateraldcha);
    filacolumna(ancho, 3, largo, columna);
    filainferior(ancho, 3, linea, esquinaizqinf, esquinadchainf, tinvertida);
}

//FUNCION PARA DIBUJAR EL AJEDREZ

void ajedrez(int ancho, int largo, char linea, char columna, char esquinaizqsup, char esquinadchasup, char esquinaizqinf, char esquinadchainf, char tnormal, char tinvertida, char cruz, char tlateralizq, char tlateraldcha){

    filasuperior( ancho, 8, linea, esquinaizqsup, esquinadchasup, tnormal);
    filacolumnanegra(ancho, 8, largo, columna);
    for(int i=0;i<=2;i++)
        {
            filacentral(ancho, 8, linea, cruz, tlateralizq, tlateraldcha);
            filacolumnablanca(ancho, 8, largo, columna);
            filacentral(ancho, 8, linea, cruz, tlateralizq, tlateraldcha);
            filacolumnanegra(ancho, 8, largo, columna);
        }
    filacentral(ancho, 8, linea, cruz, tlateralizq, tlateraldcha);
    filacolumnablanca(ancho, 8, largo, columna);
    filainferior(ancho, 8, linea, esquinaizqinf, esquinadchainf, tinvertida);
}


//DIVIDIMOS LAS FILAS EN LA SUPERIOR DE UN CUADRADO, LA DEL MEDIO, LA INFERIOR, Y LA QUE SEPARA CUADRADOS


//FUNCION PARA FILA SUPERIOR

void filasuperior(int ancho,int casillas, char linea, char esquinaizqsup, char esquinadchasup, char tnormal){


    printf("\t\t\t");

    printf("%c",esquinaizqsup);
        for(int i=0;i<casillas;i++)
        {
            for(int i=0;i<=ancho-2;i++)
            {
                printf("%c", linea);
            }

                if(casillas==3)
                    {
                        if(i==0 || i==1){printf("%c",tnormal);}
                    }
                if(casillas==8)
                   {
                        if(i<7){printf("%c",tnormal);}
                   }
        }
    printf("%c",esquinadchasup);
    printf("\n");
}

//FUNCION PARA FILA QUE SEAPRA CUADRADOS

void filacentral(int ancho, int casillas, char linea, char cruz, char tlateralizq, char tlateraldcha){

    printf("%c",tlateralizq);
        for(int i=0;i<casillas;i++)
        {
            for(int i=0;i<=ancho-2;i++)
            {
                printf("%c", linea);
            }
                if(casillas==3)
                    {
                        if(i==0 || i==1){printf("%c",cruz);}
                    }
                if(casillas==8)
                    {
                        if(i<7){printf("%c",cruz);}
                    }
        }
    printf("%c",tlateraldcha);
    printf("\n");
}

//FUNCION PARA FILA MEDIA DEL CUADRADO

void filacolumna(int ancho, int casillas, int largo, char columna){

 printf("\t\t\t");

        for(int j=0;j<=largo-2;j++)
        {
            for(int i=0;i<casillas;i++)
            {
                printf("%c",columna);

                for(int i=0;i<=ancho-2;i++)
                {
                    printf(" ");
                }
            }
        printf("%c",columna);
        printf("\n\t\t\t");
        }
}

//FUNCION PARA FILA MEDIA DEL CUADRADO EMPEZANDO POR BLANCO

void filacolumnablanca(int ancho, int casillas, int largo, char columna){

 printf("\t\t\t");

        for(int j=0;j<=largo-2;j++)
        {
            for(int i=0;i<casillas;i++)
            {
                printf("%c",columna);

                if(i%2==0)
                {
                    for(int i=0;i<=ancho-2;i++)
                    {
                        printf(BLANCO_F" "NEGRO_F);
                    }
                }else{
                    for(int i=0;i<=ancho-2;i++)
                    {
                        printf(" ");
                    }
                }
            }
            printf("%c  ",columna);
            printf("\n\t\t\t");
        }
}

//FUNCION PARA FILA MEDIA DEL CUADRADO EMPEZANDO POR NEGRO

void filacolumnanegra(int ancho, int casillas, int largo, char columna){

 printf("\t\t\t");

        for(int j=0;j<=largo-2;j++)
        {
            for(int i=0;i<casillas;i++)
            {
                printf("%c",columna);

                if(i%2==0)
                {
                    for(int i=0;i<=ancho-2;i++)
                    {
                        printf(" ");

                    }
                }else{
                    for(int i=0;i<=ancho-2;i++)
                    {
                        printf(BLANCO_F" "NEGRO_F);
                    }
                }
            }
            printf("%c  ",columna);
            printf("\n\t\t\t");
        }
}

//FUNCION PARA LA FILA INFERIOR DEL CUADRADO

void filainferior(int ancho, int casillas, char linea, char esquinaizqinf, char esquinadchainf, char tinvertida){

    printf("%c",esquinaizqinf);
        for(int i=0;i<casillas;i++)
        {
            for(int i=0;i<=ancho-2;i++)
            {
                printf("%c", linea);
            }
                if(casillas==3)
                    {
                        if(i==0 || i==1){printf("%c",tinvertida);}
                    }
                if(casillas==8)
                    {
                        if(i<7){printf("%c",tinvertida);}
                    }
        }
    printf("%c",esquinadchainf);
    printf("\n");
}

