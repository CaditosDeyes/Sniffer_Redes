#include <iostream>
using namespace std;

int main(){
    FILE*archivo;
    unsigned char palabra;
    int i=0;

    if ((archivo = fopen("ethernet_1.bin", "rb+")) == NULL){
        printf ( " Error en la apertura. Es posible que el fichero no exista \n ");
    }
    else{

            //palabra = fgetc (archivo);

            cout << "DIRECCION ORIGEN\n";
            for(int i=0; i<=5; i++){
                palabra = fgetc(archivo);
                printf("%0.2x:", palabra);
            }

            cout << "\n\n";

            cout << "DIRECCION DESTINO\n";
            for(int i=0; i<=5; i++){
                palabra = fgetc(archivo);
                printf("%0.2x:", palabra);
            }

            cout << "\n\n";

            cout << "TIPO\n";
            for(int i=0; i<=1; i++){
                palabra = fgetc(archivo);
                printf("%0.2x:", palabra);
            }

            switch(palabra){

            case 0:
                printf("\tIPv4\n");
                break;
            case 6:
                printf("\tARP\n");
                break;
            case 53:
                printf("\tRARP\n");
                break;
            case 221:
                printf("\tIPv6\n");
                break;
            }

            cout << "\n";
            cout << "DATOS\n";
            while(!feof(archivo)){ palabra = fgetc(archivo);
                printf("%0.2x:", palabra);


            //break;
        }
    }
    return 0;
}
