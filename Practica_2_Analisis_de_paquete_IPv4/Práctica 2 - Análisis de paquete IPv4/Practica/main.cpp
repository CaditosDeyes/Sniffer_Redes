#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

using namespace std;
int binario[8];

int potencias[8] = {1, 2, 4, 8, 16, 32, 64, 128};
int potencias2[8] = {256, 512, 1024, 2048, 4096, 8192, 16384, 32768};

int limpiarBinario(){
    for(int i=7; i>=0; i--)
        binario[i]=0;
    return 0;
}
int imprimirBinario(){
    cout << "\nNumero en binario: ";
    for(int i=7; i>=0; i--)
        cout << binario[i];
    cout << endl;
    return 0;
}
int bin_dec(){
    int num=0;
    for(int i=7; i>=0; i--)
        num = num + (binario[i]*potencias[i]);
    return num;
}

void tipoServicioPrioridad(int prioridad){
    int aux = 4;
    // Bits de 0 a 2: Prioridad
    cout << endl << "Tipo de servicio: ";
    switch(prioridad){
        case 0:
            cout << "Prioridad De rutina" << endl;
            break;
        case 1:
            cout << "Prioritario" << endl;
            break;
        case 2:
            cout << "Inmediato" << endl;
            break;
        case 3:
            cout << "Relampago" << endl;
            break;
        case 4:
            cout << "Invalidacion Relampago" << endl;
            break;
        case 5:
            cout << "Procesando llamada crítica y de emergencia" << endl;
            break;
        case 6:
            cout << "Control de trabajo de Internet" << endl;
            break;
        case 7:
            cout << "Control de red" << endl;
            break;
        default:
            cout << "Se ha producido un error" << endl;
            break;
    }
    // Desglose de bits

    // Bit 3: Retardo
    if(binario[aux])
        cout << endl << "Retardo bajo";
    else
        cout << endl << "Retardo normal";
    aux--;
    //Bit 4: Rendimiento. 0= normal; 1= alto.
    if(binario[aux])
        cout << endl << "Rendimiento alta";
    else
        cout << endl << "Rendimiento normal";
    aux--;
    //Bit 5: Fiabilidad. 0=normal; 1= alta.
    if(binario[aux])
        cout << endl << "Fiabilidad alta";
    else
        cout << endl << "Fiabilidad normal";
    aux--;
    //Bit 6-7: No usados. Reservados para uso futuro.
    cout << endl;
}

int byte1_LTI(){
    int byte1=0;
    for(int i=7; i>=0; i--){
        byte1 = byte1 + binario[i]*potencias2[i];
        //cout << byte1 << " = " << binario[i] << " * " << potencias2[i] << endl;
        //system("PAUSE");
    }
    return byte1;
}

int byte2_LTI(){
    int byte2=0;
    for(int i=7; i>=0; i--){
        byte2 = byte2 + binario[i]*potencias[i];
        //cout << byte2 << " = " << binario[i] << " * " << potencias[i] << endl;
        //system("PAUSE");
    }
    return byte2;
}


// Banderas
// Posicion de Fragmento
int bandera3bits(){
    int i=7, suma=0;
     cout<<"Bit 0: Reservado\n";
        i--;
        if(binario[i]==0)
            cout<<"Bit 1: Reservado\n";
        else
            cout<<"Bit 1: No divisible\n";
        i--;
        if(binario[i]==0)
            cout<<"Bit 2: Ultimo Fragmento\n";
        else
             cout<<"Bit 2: Fragmento Intermedio\n";
        i--;
        // i=4
        for(i; i>=0; i--)
            suma = suma + (binario[i]*potencias2[i]);
        return suma;
}

// Tiempo de vida = bin_dec
// Protocolo = bin_dec
void protocolo(int prot){
    switch(prot){
        case 1:
            cout << "ICMPv4\n";
            break;
        case 6:
            cout << "TCP\n";
            break;
        case 17:
            cout << "UDP\n"; 
            break;
        case 58:
            cout << "ICMPv6\n";
            break;
        case 118:
            cout << "STP\n";
            break;
        case 121:
            cout << "SMP\n";
            break;
        default:
            cout << "Protocolo no reconocido\n";
            break;
    }
}

int main(){
    FILE*archivo;
    unsigned char palabra;
    int i=0, aux=0, band=0, tamanio=0, version=0, prioridad=0, sumaLTI=0, frag=0;

    if ((archivo = fopen("ethernet_ipv4_tcp.bin", "rb+")) == NULL){
        printf ( "Error en la apertura. Es posible que el fichero no exista \n ");
    }
    else{

        //palabra = fgetc (archivo);
        cout << "DIRECCION ORIGEN\n";
        for(int i=0; i<=5; i++){
            palabra = fgetc(archivo);
            printf("%0.2X:", palabra);
        }
        
        cout << "\n\n";

        cout << "DIRECCION DESTINO\n";
        for(int i=0; i<=5; i++){
            palabra = fgetc(archivo);
            printf("%0.2X:", palabra);
        }

        cout << "\n\n";

        cout << "TIPO\n";
        for(int i=0; i<=1; i++){
            palabra = fgetc(archivo);
            printf("%0.2X:", palabra);
        }

        switch(palabra){
            case 0:
            // IPv4 caracteristicas -> REALIZADO
                printf("\n\nPaquete IPv4\n");
                palabra = fgetc(archivo);

                for(int i=7;i>=0;i--)
                    binario[i]=((palabra & (1 << i)) ? 1 : 0);

            // Version y Tamaño (1 byte) -> REALIZADO
                for(int i=0; i<=7; i++){
                    if(i<=3)
                        tamanio = (binario[i]*potencias[i])+tamanio;
                    else
                        version = (binario[i]*potencias[i-4])+version;
                }

                cout << "\nVersion: " << version << "\nTamanio: " << tamanio << endl;

            // Tipo de servicios 8 bits
                limpiarBinario();
                palabra = fgetc(archivo); // 00 del archivo
                //palabra = fgetc(archivo); // 00 del archivo
                //palabra = fgetc(archivo); // 3C del archivo
                //printf("palabra actual %0.2X", palabra);

                for(int i=7;i>=0;i--)
                    binario[i]=((palabra & (1 << i)) ? 1 : 0);
                
                //imprimirBinario();

                for(int i=5; i<=7; i++)
                    prioridad = (binario[i]*potencias[i-5])+prioridad;

                tipoServicioPrioridad(prioridad);

                // Longitud total e identificador: Palabras 00:3C

                for(int j=0; j<=1; j++){
                    palabra = fgetc(archivo); // 00-57
                    //printf("\nPalabra1: %0.2x\n", palabra);
                    for(int i=7;i>=0;i--)
                        binario[i]=((palabra & (1 << i)) ? 1 : 0);
                    //imprimirBinario();

                    sumaLTI = byte1_LTI();

                    palabra = fgetc(archivo); // 3c-09
                    //printf("\nPalabra2: %0.2x\n", palabra);
                    for(int i=7;i>=0;i--)
                        binario[i]=((palabra & (1 << i)) ? 1 : 0);
                    //imprimirBinario();

                    sumaLTI = sumaLTI + byte2_LTI();

                    if(band==0){
                        cout << "\nLongitud total: " << sumaLTI << " bytes";
                        band = 1;
                    }
                    else{
                        cout << "\nIdentificador: " << sumaLTI << endl;
                    }

                    sumaLTI = 0;
                }

                // Banderas y fragmento
                //conversion a binario banderas
                    palabra = fgetc(archivo); // 40
                    //printf("\nPalabra1: %0.2x\n", palabra);
                    for(int i=7;i>=0;i--)
                        binario[i]=((palabra & (1 << i)) ? 1 : 0);
                
                cout<<"\nBanderas" << endl;
                frag = bandera3bits();
                cout<<" "<<endl;

                palabra = fgetc(archivo); // 00
                    //printf("\nPalabra1: %0.2x\n", palabra);
                    for(int i=7;i>=0;i--)
                        binario[i]=((palabra & (1 << i)) ? 1 : 0);
                frag = frag + byte2_LTI();

                cout << "Posicion de fragmento: " << frag << endl;


                // Tiempo de vida
                
                palabra = fgetc(archivo); //40 - Tiempo de vida

                //printf("\nPalabra: %0.2x\n", palabra);
                for(int i=7;i>=0;i--)
                    binario[i]=((palabra & (1 << i)) ? 1 : 0);
                
                cout << "\nTiempo de vida: " << bin_dec();
                limpiarBinario();

                // Protocolo
                palabra = fgetc(archivo); //06 - Protocolo
                for(int i=7;i>=0;i--)
                    binario[i]=((palabra & (1 << i)) ? 1 : 0);

                cout << "\nProtocolo: ";
                protocolo(bin_dec());
                //cout << "\nProtocolo: " << bin_dec();
                limpiarBinario();

                // Checksum
                palabra = fgetc(archivo); //A8 - Checksum
                printf("\nChecksum: %0.2X:", palabra);
                palabra = fgetc(archivo); // 82
                printf("%0.2X", palabra);

                // Direccion IP origen = AC:16:C8:02
                cout << "\n\nDireccion IP origen: ";
                for(int ip=3; ip>=0; ip--){
                    palabra = fgetc(archivo); // AC:16:C8:02
                    for(int i=7;i>=0;i--)
                        binario[i]=((palabra & (1 << i)) ? 1 : 0);
                    
                    if(ip!=0)
                        cout << bin_dec() << ".";
                    else
                        cout << bin_dec();
                }
                // Direccion IP destino = D0:5E:F6:B8
                cout << "\nDireccion IP destino: ";
                for(int ip=3; ip>=0; ip--){
                    palabra = fgetc(archivo); // D0:5E:F6:B8
                    for(int i=7;i>=0;i--)
                        binario[i]=((palabra & (1 << i)) ? 1 : 0);
                    
                    if(ip!=0)
                        cout << bin_dec() << ".";
                    else
                        cout << bin_dec();
                }

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

        cout << "\n\nDATOS\n";
        while(!feof(archivo)){
            palabra = fgetc(archivo);
            printf(":%0.2X", palabra);
            //break;
        }
    }
    return 0;
}